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
Archivo Automata.h
**/

#ifndef Automata_H
#define Automata_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Alfabeto.h"
#include "Estado.h"
#include "Gramatica.h"

class Automata {
 public:
  Automata() = default;
  friend std::istream& operator>>(std::istream& input, Automata& automata);
  const Alfabeto& GetAlfabeto() const;
  const std::map<int, Estado>& GetEstados() const;
  int GetEstadoArranque() const;
  Gramatica ConvertToGrammar() const;
  std::string NombreEstado(int id) const;

 private:
  Alfabeto alfabeto_;
  std::map<int, Estado> estados_;
  int estado_arranque_ = -1;
  void LeerLineaUtil(std::istream& input, std::string& linea);
};

#endif
