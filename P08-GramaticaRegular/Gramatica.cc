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

Gramatica::Gramatica() = default;
void Gramatica::AnadirTerminal(char simbolo) {
  terminales_.insert(simbolo);
}
void Gramatica::AnadirNoTerminal(const std::string& simbolo) {
  no_terminales_.insert(simbolo);
}
void Gramatica::SetSimboloArranque(const std::string& simbolo) {
  simbolo_arranque_ = simbolo;
}
void Gramatica::AnadirProduccion(const Produccion& produccion) {
  producciones_.push_back(produccion);
}
void Gramatica::EscribirEnFichero(const std::string& nombre_fichero) const {
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
    archivo << producciones_[i] << std::endl;
  }

}

  

