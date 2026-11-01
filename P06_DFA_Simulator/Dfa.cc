/**
Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 6: Simulador de DFAs
Autor: Miguel Rodríguez Reyes
Correo: alu0101794976@ull.edu.es
Fecha: 21/10/2026
Archivo Dfa.cc
**/

#include "Dfa.h"

#include <iomanip>
#include <sstream>
#include <utility>

/**
 * @brief Lee un DFA desde un flujo con el formato del fichero .dfa.
 * @param input Flujo de entrada.
 * @param automata Autómata que se rellena.
 * @return El flujo, con failbit activado si el estado de arranque no existe.
 */
std::istream& operator>>(std::istream& input, Dfa& automata) {
  int numero_estados;
  std::string linea;
  automata.LeerLineaUtil(input, linea);
  for (char simbolo : linea) {
    automata.alfabeto_.AnadirSimbolo(simbolo);
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
    linea_stream >> id >> aceptacion;
    Estado estado(id, aceptacion == 1);
    char simbolo;
    int destino;
    while (linea_stream >> simbolo >> destino) {
      estado.AnadirTransicion(simbolo, destino);
    }
    automata.estados_.emplace(id, estado);
  }
  return input;
}

/**
 * @brief Simula el autómata con una cadena e imprime la traza.
 * @param cadena Cadena de entrada ("&" es la cadena vacía).
 * @return true si la cadena es aceptada, false si no.
 */
bool Dfa::Simular(const std::string& cadena) const {
  int actual = estado_arranque_;
  std::cout << "Est. Actual   Entrada   Nuevo Est." << std::endl;
  if (cadena != "&") {
    for (char simbolo : cadena) {
      if (!alfabeto_.Pertenece(simbolo)) {
        std::cout << "Cadena de entrada RECHAZADA" << std::endl;
        return false;
      }
      int siguiente = estados_.at(actual).Estado_siguiente(simbolo);
      std::cout << std::setw(5) << actual << std::setw(12) << simbolo
                << std::setw(12) << siguiente << std::endl;
      actual = siguiente;
    }
  }
  bool aceptada = estados_.at(actual).Es_de_aceptacion();
  if (aceptada) {
    std::cout << "Cadena de entrada ACEPTADA" << std::endl;
  } else {
    std::cout << "Cadena de entrada RECHAZADA" << std::endl;
  }
  return aceptada;
}

/**
 * @brief Comprueba si una cadena es aceptada, sin imprimir la traza.
 * @param cadena Cadena de entrada ("&" es la cadena vacía).
 * @return true si es aceptada, false si no.
 */
bool Dfa::Acepta(const std::string& cadena) const {
  int actual = estado_arranque_;
  if (cadena != "&") {
    for (char simbolo : cadena) {
      if (!alfabeto_.Pertenece(simbolo) || !estados_.at(actual).TieneTransicion(simbolo)) {
        return false;
      }
      actual = estados_.at(actual).Estado_siguiente(simbolo);
    }
  }
  return estados_.at(actual).Es_de_aceptacion();
}

/**
 * @brief Genera todas las cadenas del alfabeto de longitud <= n.
 * @param n Longitud máxima. La cadena vacía se representa como "&".
 * @return Cadenas ordenadas por longitud y, dentro de cada longitud, alfabéticamente.
 */
std::vector<std::string> Dfa::GenerarCadenas(int n) const {
  std::vector<std::string> todas = {"&"};
  std::vector<std::string> nivel = {""};
  for (int longitud = 1; longitud <= n; longitud++) {
    std::vector<std::string> siguiente;
    for (const std::string& prefijo : nivel) {
      for (char simbolo : alfabeto_.GetSimbolos()) {
        siguiente.push_back(prefijo + simbolo);
      }
    }
    todas.insert(todas.end(), siguiente.begin(), siguiente.end());
    nivel = std::move(siguiente);
  }
  return todas;
}

/**
 * @brief Genera todas las cadenas de longitud <= n, las simula y muestra el resultado.
 * @param n Longitud máxima de las cadenas.
 * @return Número total de cadenas generadas.
 */
size_t Dfa::SimularTodas(int n) const {
  std::vector<std::string> cadenas = GenerarCadenas(n);
  for (const std::string& cadena : cadenas) {
    std::cout << std::left << std::setw(n + 2) << cadena << std::right
              << (Acepta(cadena) ? "ACEPTADA" : "RECHAZADA") << std::endl;
  }
  std::cout << "Total de cadenas generadas: " << cadenas.size() << std::endl;
  return cadenas.size();
}

/**
 * @brief Lee la siguiente línea ignorando las que empiezan por "//".
 * @param input Flujo de entrada.
 * @param linea Línea leída.
 */
void Dfa::LeerLineaUtil(std::istream& input, std::string& linea) {
  std::getline(input, linea);
  while (linea.substr(0, 2) == "//") {
    std::getline(input, linea);
  }
}
