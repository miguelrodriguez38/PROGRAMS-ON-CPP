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
Archivo Gramatica.cc
**/

#include "Gramatica.h"
#include <set>
#include <string>
#include <vector>
#include "Produccion.h"
#include <fstream>
#include <iostream>

/**
 * @brief Crea una gramática vacía.
 */
Gramatica::Gramatica() = default;

/**
 * @brief Añade un terminal.
 * @param simbolo Símbolo a añadir.
 */
void Gramatica::AnadirTerminal(char simbolo) {
  terminales_.insert(simbolo);
}

/**
 * @brief Añade un no terminal.
 * @param simbolo No terminal a añadir.
 */
void Gramatica::AnadirNoTerminal(const std::string& simbolo) {
  no_terminales_.insert(simbolo);
}

/**
 * @brief Define el símbolo de arranque.
 * @param simbolo Símbolo inicial.
 */
void Gramatica::SetSimboloArranque(const std::string& simbolo) {
  simbolo_arranque_ = simbolo;
}

/**
 * @brief Añade una producción.
 * @param produccion Producción a incluir.
 */
void Gramatica::AnadirProduccion(const Produccion& produccion) {
  producciones_.push_back(produccion);
}

/**
 * @brief Escribe la gramática en un fichero.
 * @param nombre_fichero Nombre del fichero.
 * @param mostrar_lineal Indica si se muestra la linealidad.
 */
void Gramatica::EscribirEnFichero(const std::string& nombre_fichero, bool mostrar_lineal) const {
  std::ofstream archivo(nombre_fichero);
  if (!archivo.is_open()) {
    std::cerr << "No se pudo abrir" << std::endl;
    return;
  }
  archivo << terminales_.size() << std::endl;
  for ( const auto terminal : terminales_ ) {
    archivo << terminal << std::endl;
  }
  archivo << no_terminales_.size() << std::endl;
  for ( const auto & noterminal : no_terminales_ ) {
    archivo << noterminal << std::endl;
  }
  archivo << simbolo_arranque_ << std::endl;
  archivo << producciones_.size() << std::endl;
  for ( size_t i = 0; i < producciones_.size(); i++) {
    archivo << producciones_[i];
    if (mostrar_lineal) {
      archivo << " (" << producciones_[i].TipoLineal() << ")";
    }
    archivo << std::endl;
  }

}

  

