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
Archivo Alfabeto.h: Clase alfabeto


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#ifndef CADENA_H
#define CADENA_H

#include <iostream>
#include "Alfabeto.h"
#include <string>


class Cadena {
 public:
  Cadena();
  Cadena(const std::string& cadena, const Alfabeto& alfabeto);
  int Longitud() const;
  const Alfabeto& GetAlfabeto() const;
  const std::string& GetCadena() const;
  Cadena Potencia(int numero) const;
  bool EsValida() const;
  Cadena Inversa() const;

  friend std::ostream& operator<<(std::ostream& output, const Cadena& cadena );
  friend std::istream& operator>>(std::istream& input, Cadena& cadena );
	friend bool operator<(const Cadena& a, const Cadena& b);


 private:
  std::string cadena_;
  Alfabeto alfabeto_;
};

#endif