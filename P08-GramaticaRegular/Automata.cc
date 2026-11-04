/**
Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 6: Simulador de Automatas
Autor: Miguel Rodríguez Reyes
Correo: alu0101794976@ull.edu.es
Fecha: 21/10/2026
Archivo Automata.cc
**/

#include "Automata.h"
#include "Gramatica.h"

#include <iomanip>
#include <sstream>
#include <utility>

/**
 * @brief Lee un autómata desde un flujo.
 * @param input Flujo de entrada.
 * @param automata Autómata a rellenar.
 * @return Flujo leído.
 */
std::istream& operator>>(std::istream& input, Automata& automata) {
  int numero_estados;
  std::string linea;
  automata.LeerLineaUtil(input, linea);
  for (char simbolo : linea) {
    if (simbolo != ' ') {
      automata.alfabeto_.AnadirSimbolo(simbolo);
    }
  }
  input >> numero_estados;
  input >> automata.estado_arranque_;
  if (automata.estado_arranque_ < 0 || automata.estado_arranque_ >= numero_estados) {
    std::cerr << "El estado de arranque no existe" << std::endl;
    input.setstate(std::ios::failbit);
    return input;
  }
  std::getline(input, linea);
  for (int i = 0; i < numero_estados; i++) {
    std::getline(input, linea);
    std::istringstream linea_stream(linea);
    int id;
    int aceptacion;
    int numero_transiciones;
    linea_stream >> id >> aceptacion >> numero_transiciones;
    Estado estado(id, aceptacion == 1);
    for (int j = 0; j < numero_transiciones; j++) {
      char simbolo;
      int destino;
      linea_stream >> simbolo >> destino;
      estado.AnadirTransicion(simbolo, destino);
    }
    automata.estados_.emplace(id, estado);
  }
  return input;
}

/**
 * @brief Devuelve el alfabeto del autómata.
 * @return Alfabeto del autómata.
 */
const Alfabeto& Automata::GetAlfabeto() const { return alfabeto_;}

/**
 * @brief Devuelve los estados del autómata.
 * @return Mapa de estados.
 */
const std::map<int, Estado>& Automata::GetEstados() const { return estados_;}

/**
 * @brief Devuelve el estado inicial.
 * @return Identificador del estado de arranque.
 */
int Automata::GetEstadoArranque () const { return estado_arranque_;}

/**
 * @brief Genera el nombre del estado.
 * @param id Identificador del estado.
 * @return Nombre del estado.
 */
std::string Automata::NombreEstado(int id) const {
  return std::string(1, static_cast<char>('A' + id));
}

/**
 * @brief Convierte el autómata en una gramática regular.
 * @return Gramática generada.
 */
Gramatica Automata::ConvertToGrammar() const {
  Gramatica gramatica;
  for ( const auto simbolos : alfabeto_.GetSimbolos() ) {
    gramatica.AnadirTerminal(simbolos);
  }
  for (const auto& pareja : estados_) {
    int id = pareja.first;
    const Estado& estado = pareja.second;
    std::string nombre = NombreEstado(id);
    gramatica.AnadirNoTerminal(nombre);
    for (char simbolo : alfabeto_.GetSimbolos()) {
      if (estado.TieneTransicion(simbolo)) {
        std::string destino = NombreEstado(estado.Estado_siguiente(simbolo));
        gramatica.AnadirProduccion(Produccion(nombre, std::string(1, simbolo) + destino));
      }
    }
    if (estado.Es_de_aceptacion()) {
      gramatica.AnadirProduccion(Produccion(nombre, "&"));
    }
  }
  gramatica.SetSimboloArranque(NombreEstado(estado_arranque_));
  return gramatica;
}



/**
 * @brief Lee la siguiente línea ignorando las que empiezan por "//".
 * @param input Flujo de entrada.
 * @param linea Línea leída.
 */
void Automata::LeerLineaUtil(std::istream& input, std::string& linea) {
  std::getline(input, linea);
  while (linea.substr(0, 2) == "//") {
    std::getline(input, linea);
  }
}
