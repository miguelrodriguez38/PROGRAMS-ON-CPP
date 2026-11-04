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
Archivo Gramatica.h
**/

#ifndef Gramatica_H
#define Gramatica_H

#include <set>
#include <string>
#include <vector>
#include "Produccion.h"

class Gramatica {
 public:
  Gramatica();
  void AnadirTerminal(char simbolo);
  void AnadirNoTerminal(const std::string& simbolo);
  void SetSimboloArranque(const std::string& simbolo);
  void AnadirProduccion(const Produccion& produccion);
  void EscribirEnFichero(const std::string& nombre_fichero, bool mostrar_lineal = false) const;

  

 private:
  std::set<char> terminales_;
  std::set<std::string> no_terminales_;
  std::string simbolo_arranque_;
  std::vector<Produccion> producciones_;
};

#endif