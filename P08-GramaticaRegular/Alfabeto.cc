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
Archivo Alfabeto.cc
**/

#include "Alfabeto.h"

/**
 * @brief Devuelve el conjunto de símbolos del alfabeto.
 * @return Copia del conjunto de símbolos.
 */
const std::set<char> Alfabeto::GetSimbolos() const {
  return simbolos_;
}

/**
 * @brief Añade un símbolo al alfabeto (si ya existe no hace nada).
 * @param simbolo Símbolo a añadir.
 */
void Alfabeto::AnadirSimbolo(char simbolo) {
  simbolos_.insert(simbolo);
}

/**
 * @brief Comprueba si un símbolo pertenece al alfabeto.
 * @param simbolo Símbolo a comprobar.
 * @return true si pertenece, false si no.
 */
bool Alfabeto::Pertenece(char simbolo) const {
  return simbolos_.find(simbolo) != simbolos_.end();
}

/**
 * @brief Comprueba si todos los símbolos de una cadena pertenecen al alfabeto.
 * @param cadena Cadena a comprobar.
 * @return true si todos sus símbolos pertenecen al alfabeto, false si no.
 */
bool Alfabeto::CadenaPertenece(const std::string& cadena) const {
  for (size_t i = 0; i < cadena.size(); i++) {
    if (!simbolos_.count(cadena[i])) {
      return false;
    }
  }
  return true;
}
