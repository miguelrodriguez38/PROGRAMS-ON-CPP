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
Archivo Produccion.cc
**/

#include "Produccion.h"
#include <string>
#include <iostream>

/**
 * @brief Crea una producción.
 * @param parte_izquierda Lado izquierdo.
 * @param parte_derecha Lado derecho.
 */
Produccion::Produccion(std::string parte_izquierda, std::string parte_derecha) : parte_izquierda_{parte_izquierda}, 
        parte_derecha_{parte_derecha} {}

/**
 * @brief Escribe la producción en un flujo.
 * @param salida Flujo de salida.
 * @param produccion Producción a escribir.
 * @return Flujo modificado.
 */
std::ostream& operator<<(std::ostream& salida, const Produccion& produccion) {
    salida << produccion.parte_izquierda_ << " -> " << produccion.parte_derecha_;
    return salida;
}

/**
 * @brief Devuelve el tipo de linealidad.
 * @return Tipo de la producción.
 */
std::string Produccion::TipoLineal() const {
  if (parte_derecha_.size() == 2) {
    bool primero_mayuscula = (parte_derecha_[0] >= 'A' && parte_derecha_[0] <= 'Z');
    bool segundo_mayuscula = (parte_derecha_[1] >= 'A' && parte_derecha_[1] <= 'Z');
    if (primero_mayuscula && !segundo_mayuscula) {
      return "Lineal por la izquierda";
    }
    if (!primero_mayuscula && segundo_mayuscula) {
      return "Lineal por la derecha";
    }
  }
  return "Ambas";
}
