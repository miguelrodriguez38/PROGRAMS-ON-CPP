/**
Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 3: Regex
Autor: Miguel Rodríguez Reyes
Correo: alu0101794976@ull.edu.es
Fecha: 06/10/2026
Archivo Cliente.cc


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include "Html.h"
#include "Comment.h"

int CalcularLinea(const std::string& texto, std::size_t posicion) { // recorre hasta la posicion en la que estas para saber que linea es
  int linea = 1;
  for (std::size_t i = 0; i < posicion; ++i) {
    if (texto[i] == '\n') {
      ++linea;
    }
  }
  return linea;
}
void MostrarAyuda(const std::string& programa, std::ostream& output) {
  output << "Uso: " << programa << " <fichero_entrada.html> <fichero_salida.txt>" << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc == 2) {
    std::string opcion = argv[1];
    if (opcion == "--help" ) {
      MostrarAyuda(argv[0], std::cout);
      return 0;
    }
  }
  if (argc != 3) {
    MostrarAyuda(argv[0], std::cerr);
    return 1;
  }
  std::ifstream file(argv[1]);
  if (!file) {
    std::cerr << "Error opening the file" << std::endl;
    return 1;
  }
  Html fichero(argv[1]);
  std::string texto;
  std::string linea;
  while (std::getline(file, linea)) {
    texto += linea + '\n';
  }

  std::regex regex_etiqueta(R"(<(/?)(html|head|title|body|h1|p|a|img)(\s[^>]*)?>)");
  std::regex regex_atributo(R"((\w+)\s*=\s*("[^"]*"))");
  std::regex regex_doctype(R"(<!DOCTYPE\s+html\s*>)", std::regex::icase); // icase es para no darle importancia a las mayusculas o minusculas
  std::regex regex_comentario(R"(<!--([\s\S]*?)-->)");

  // 1. Doctype
  std::smatch resultado_doctype;
  bool hay_doctype = std::regex_search(texto, resultado_doctype, regex_doctype);  //std::regex_search(textoI(donde buscar), resultado(donde lo guardas), regex(lo que buscas));
  if (hay_doctype) {
    fichero.SetDoctype("HTML5");
  }

  // 2. Comentarios
  bool es_primero = true;
  for (std::sregex_iterator c(texto.begin(), texto.end(), regex_comentario), fin_c; /**está vacío**/ c != fin_c;/**mientras no coincidan**/  ++c) {
    std::size_t inicio = c->position(0);  // devuelve el caracter en el que empieza el comentario
    std::size_t final = inicio + c->length(0) - 1; // -1 porque los indices empiezan en cero
    int linea_inicio = CalcularLinea(texto, inicio); // si hay /n ++ linea
    int linea_fin = CalcularLinea(texto, final);
    bool es_descripcion = false;

    if (es_primero && hay_doctype) {
      std::size_t fin_doctype = resultado_doctype.position(0) + resultado_doctype.length(0);
      if (inicio >= fin_doctype) {
        std::string entre = texto.substr(fin_doctype, inicio - fin_doctype);
        if (std::regex_match(entre, std::regex(R"(\s*)"))) { // si es un salto de linea, un espacio o algo vacio lo que hay entre el doctype y la descrpcion ponemos a true la descripcion
          es_descripcion = true;
          std::string limpio = std::regex_replace((*c)[1].str(), std::regex(R"(^\s+|\s+$)"), ""); // Limpias el texto, borras los espacios de delante y de detras
          fichero.SetDescripcion(limpio);
        }
      }
    }
    es_primero = false;
    fichero.AñadirComentario(Comment(linea_inicio, linea_fin, (*c)[0].str() /** texto */, es_descripcion));
  }

  // 3. Etiquetas
  for (std::sregex_iterator it(texto.begin(), texto.end(), regex_etiqueta), fin; it != fin; ++it) {
    int numero_linea = CalcularLinea(texto, it->position(0)); // calculas la linea
    bool es_cierre = (*it)[1].length() > 0; // es cierra si su longitud es mayor que cero debido al caracter /
    std::string nombre = (*it)[2].str(); // str convierte un grupo del match por ejemplo html en un string normal

    Tag etiqueta(nombre, numero_linea, es_cierre);
    std::string atributos = (*it)[3].str();  // pillas un atributo por ejemplo href = "ULL" ( no se html )
    for (std::sregex_iterator at(atributos.begin(), atributos.end(), regex_atributo), fin_at; at != fin_at; ++at) { // recorrres ese atributo
      Attribute atributo((*at)[1].str(), (*at)[2].str()); // Creas un objeto conviertiendo a string ambos grupo nombre y valor
      etiqueta.IntroducirAtributo(atributo); // introduces el atributo en el vector
    }
    fichero.AñadirEtiquetas(etiqueta); // añades la etiqueta al vector
  }
  // 4. Links
  std::regex regex_enlace(R"(<a\s[^>]*href\s*=\s*"(\w+)://[^"]*"[^>]*>([\s\S]*?)</a>)");
  for (std::sregex_iterator e(texto.begin(), texto.end(), regex_enlace), fin_e; e != fin_e; ++e) {
    int numero_linea = CalcularLinea(texto, e->position(0));
    std::string protocolo = (*e)[1].str(); // protocolo encaja con el match 1 que es lo que cubre \s\S
    std::string contenido = std::regex_replace((*e)[2].str(), std::regex(R"(^\s+|\s+$)"), ""); // el atch 2 encaja con contenido que es lo que cubre *"
    fichero.AñadirEnlace(Link(numero_linea, protocolo, contenido));
  }
  std::ofstream salida(argv[2]);
  if (!salida) {
    std::cerr << "Error opening the output file" << std::endl;
    return 1;
  }
  fichero.Escribir(salida);
  return 0;
}