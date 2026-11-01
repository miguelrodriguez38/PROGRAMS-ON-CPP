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
Archivo Comment.cc


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include "Html.h"
 
Html::Html(const std::string& nombre) : nombre_fichero_{nombre}, tiene_html_{false}, tiene_head_{false}, tiene_body_{false} {}
 
void Html::AñadirEtiquetas(const Tag& tag) {
  if (!tag.EsDeCierre() && tag.GetNombre() == "html") {
    tiene_html_ = true;
  } else if (!tag.EsDeCierre() && tag.GetNombre() == "head") {
    tiene_head_ = true;
  } else if (!tag.EsDeCierre() && tag.GetNombre() == "body") {
    tiene_body_ = true;
  }
  etiquetas_.push_back(tag);
}
 
void Html::AñadirEnlace(const Link& enlace) {
  enlaces_.push_back(enlace);
}
 
void Html::AñadirComentario(const Comment& comentario) {
  comentarios_.push_back(comentario);
}
 
void Html::SetDescripcion(const std::string& descripcion) {
  descripcion_ = descripcion;
}
 
void Html::SetDoctype(const std::string& doctype) {
  doctype_ = doctype;
}
 
void Html::Escribir(std::ostream& output) const {
  output << "PROGRAM: " << nombre_fichero_ << std::endl << std::endl;
  output << "DESCRIPTION:" << std::endl << descripcion_ << std::endl
         << std::endl;
  output << "STRUCTURE:" << std::endl;
  output << "HTML: " << (tiene_html_ ? "True" : "False") << std::endl;
  output << "HEAD: " << (tiene_head_ ? "True" : "False") << std::endl;
  output << "BODY: " << (tiene_body_ ? "True" : "False") << std::endl;
  output << "DOCTYPE: " << doctype_ << std::endl << std::endl;
 
  output << "TAGS:" << std::endl;
  for (const auto& tag : etiquetas_) {
    output << tag << std::endl;
  }
 
  output << std::endl << "ATTRIBUTES:" << std::endl;
  for (const auto& tag : etiquetas_) {
    if (tag.TieneAtributos()) {
      tag.ImprimirAtributos(output);
    }
  }
 
  output << "COMMENTS:" << std::endl;
  for (const auto& comentario : comentarios_) {
    output << comentario << std::endl;
  }
 
  output << "LINKS:" << std::endl;
  for (const auto& enlace : enlaces_) {
    output << enlace << std::endl;
  }
}
