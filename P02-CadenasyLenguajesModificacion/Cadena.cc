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


Cadena::Cadena() = default;
Cadena::Cadena(const std::string& cadena, const Alfabeto& alfabeto) : cadena_{cadena}, alfabeto_{alfabeto} {}
int Cadena::Longitud() const {
  int count = 0;
  for ( size_t i = 0; i < cadena_.size(); i++) {
    count++;
  }
  return count;
}

const Alfabeto& Cadena::GetAlfabeto() const {
  return alfabeto_;
}

const std::string& Cadena::GetCadena() const {
  return cadena_;
}
bool Cadena::EsValida() const {
  for ( char c : cadena_) {
    if ( !alfabeto_.Contiene(c)) {
      return false;
    }
  }
	return true;
}

Cadena Cadena::Inversa() const {
  std::string al_reves;
  int empiezo = cadena_.size() - 1;
  for ( int i = empiezo; i >= 0; i-- ) {
    al_reves += cadena_[i];
  }
  return Cadena(al_reves, alfabeto_);
}

Cadena Cadena::Concatenacion(const std::string& otra) const {
  std::string nueva_cadena;
  for ( int i = 0; i < cadena_.size(); i++ ) {
    nueva_cadena += cadena_[i];
  }
  nueva_cadena += otra;
  return Cadena(nueva_cadena, alfabeto_);
}

std::ostream& operator<<(std::ostream& output, const Cadena& cadena ) {
  if (cadena.cadena_.empty()) {
  output << "&";
  } else {
  output << cadena.cadena_;
  }
  return output;
}

std::istream& operator>>(std::istream& input, Cadena& cadena ) {
	input >> cadena.cadena_ >> cadena.alfabeto_;
	return input;
}

bool operator<(const Cadena& a, const Cadena& b) {
  if (a.cadena_.size() != b.cadena_.size()) {
    return a.cadena_.size() < b.cadena_.size();  // compara longitud
  }
  return a.cadena_ < b.cadena_; // compara alfabeto
} 

