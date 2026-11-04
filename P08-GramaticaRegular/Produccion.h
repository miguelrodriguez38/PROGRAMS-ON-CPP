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
Archivo Produccion.h
**/

#ifndef PRODUCCION_H
#define PRODUCCION_H

#include <iostream>
#include <set>
#include <string>

class Produccion {
 public:
  Produccion(std::string parte_izquierda, std::string parte_derecha);
  std::string TipoLineal() const;
  friend std::ostream& operator<<(std::ostream& salida, const Produccion& produccion);

 private:
  std::string parte_izquierda_;
  std::string parte_derecha_;
};

#endif
