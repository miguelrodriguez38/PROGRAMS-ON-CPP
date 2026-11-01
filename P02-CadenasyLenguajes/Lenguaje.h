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
Archivo Lenguaje.h: Clase Lenguaje


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <iostream>
#include <set>
#include "Cadena.h"


class Lenguaje {
 public:
  Lenguaje();
  void Insertar(const Cadena& cadena);

	friend std::ostream& operator<<(std::ostream& output, const Lenguaje& lenguaje);

 private:
  std::set<Cadena> cadenas_; //Un Lenguaje es la combinacion de muchas cadenas
 
};

inline Lenguaje Prefijos(const Cadena& cadena) {
  Lenguaje prefijos;
  const std::string& texto = cadena.GetCadena();
  for (size_t i = 0; i <= texto.size(); i++) {
    prefijos.Insertar(Cadena(texto.substr(0, i), cadena.GetAlfabeto())); // donde empiezas y cuantas letras coges
  }
  return prefijos;
}

inline Lenguaje Sufijos(const Cadena& cadena) {
  Lenguaje sufijos;
  const std::string& texto = cadena.GetCadena();
  for (size_t i = 0; i <= texto.size(); i++) {
    sufijos.Insertar(Cadena(texto.substr(i), cadena.GetAlfabeto())); // donde empiezas y coges todo desde ahi hasta el final
  }
  return sufijos;
}




#endif