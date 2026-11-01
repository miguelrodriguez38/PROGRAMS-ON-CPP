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
Archivo Dfa.h
**/

#ifndef DFA_H
#define DFA_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "Alfabeto.h"
#include "Estado.h"

class Dfa {
 public:
  Dfa() = default;
  friend std::istream& operator>>(std::istream& input, Dfa& automata);
  bool Simular(const std::string& cadena) const;
  bool Acepta(const std::string& cadena) const;
  std::vector<std::string> GenerarCadenas(int n) const;
  size_t SimularTodas(int n) const;

 private:
  Alfabeto alfabeto_;
  std::map<int, Estado> estados_;
  int estado_arranque_ = -1;
  void LeerLineaUtil(std::istream& input, std::string& linea);
};

#endif
