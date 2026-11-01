/**
Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 2: Cadenas y lenguajes
Autor: Miguel Rodríguez Reyes
Correo: alu0101794976@ull.edu.es
Fecha: 20/09/2026
Archivo Cadena.cc: Clase cadena (metodos)


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include "Alfabeto.h"
#include <string>
#include "Cadena.h"

/**
 * @brief Constructor por defecto.
 */
Cadena::Cadena() = default;
/**
 * @brief Constructor de una cadena.
 * @param cadena Cadena de caracteres.
 * @param alfabeto Alfabeto al que pertenece.
 */
Cadena::Cadena(const std::string& cadena, const Alfabeto& alfabeto) : cadena_{cadena}, alfabeto_{alfabeto} {}

/**
 * @brief Devuelve la longitud de la cadena.
 * @return Longitud de la cadena.
 */
int Cadena::Longitud() const {
  int count = 0;
  for ( size_t i = 0; i < cadena_.size(); i++) {
    count++;
  }
  return count;
}
/**
 * @brief Devuelve el alfabeto de la cadena.
 * @return Referencia al alfabeto.
 */
const Alfabeto& Cadena::GetAlfabeto() const {
  return alfabeto_;
}
/**
 * @brief Devuelve la cadena.
 * @return Referencia a la cadena.
 */
const std::string& Cadena::GetCadena() const {
  return cadena_;
}
/**
 * @brief Comprueba si la cadena es válida.
 * @return true si todos los caracteres pertenecen al alfabeto.
 */
bool Cadena::EsValida() const {
  for ( char c : cadena_) {
    if ( !alfabeto_.Contiene(c)) {
      return false;
    }
  }
	return true;
}
/**
 * @brief Devuelve la cadena invertida.
 * @return Una nueva cadena con los caracteres en orden inverso.
 */
Cadena Cadena::Inversa() const {
  std::string al_reves;
  int empiezo = cadena_.size() - 1;
  for ( int i = empiezo; i >= 0; i-- ) {
    al_reves += cadena_[i];
  }
  return Cadena(al_reves, alfabeto_);
}
/**
 * @brief Calcula la potencia de una cadena.
 * @param numero Número de veces que se repite la cadena.
 * @return Nueva cadena repetida.
 */
Cadena Cadena::Potencia(int numero) const {
  std::string nueva_cadena;
  for ( int i = 0; i < numero; i++ ) {
    nueva_cadena += cadena_;
  }
  return Cadena(nueva_cadena, alfabeto_);
}
/**
 * @brief Escribe una cadena en un flujo de salida.
 * @param output Flujo de salida.
 * @param cadena Cadena que se quiere mostrar.
 * @return Referencia al flujo de salida.
 */
std::ostream& operator<<(std::ostream& output, const Cadena& cadena ) {
  if (cadena.cadena_.empty()) {
  output << "&";
  } else {
  output << cadena.cadena_;
  }
  return output;
}
/**
 * @brief Lee una cadena desde un flujo de entrada.
 * @param input Flujo de entrada.
 * @param cadena Cadena que se quiere modificar.
 * @return Referencia al flujo de entrada.
 */

std::istream& operator>>(std::istream& input, Cadena& cadena ) {
	input >> cadena.cadena_ >> cadena.alfabeto_;
	return input;
}
/**
 * @brief Compara dos cadenas.
 *
 * Primero compara su longitud y, si son iguales,
 * compara su contenido.
 *
 * @param a Primera cadena.
 * @param b Segunda cadena.
 * @return true si a es menor que b.
 */
bool operator<(const Cadena& a, const Cadena& b) {
  if (a.cadena_.size() != b.cadena_.size()) {
    return a.cadena_.size() < b.cadena_.size();  // compara longitud
  }
  return a.cadena_ < b.cadena_; // compara alfabeto
} 

