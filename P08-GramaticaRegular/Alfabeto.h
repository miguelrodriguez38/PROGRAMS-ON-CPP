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
Archivo Alfabeto.h
**/

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include <string>

class Alfabeto {
 public:
  Alfabeto() = default;
  const std::set<char> GetSimbolos() const;
  void AnadirSimbolo(char simbolo);
  bool Pertenece(char simbolo) const;
  bool CadenaPertenece(const std::string& cadena) const;

 private:
  std::set<char> simbolos_;
};

#endif
