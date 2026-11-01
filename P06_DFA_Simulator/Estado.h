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
Archivo Estado.h
**/

#ifndef ESTADO_H
#define ESTADO_H

#include <iostream>
#include <map>

class Estado {
 public:
  Estado(int id, bool es_de_aceptacion);
  int GetId() const;
  void SetId(int id);
  bool Es_de_aceptacion() const;
  int Estado_siguiente(char simbolo) const;
  void AnadirTransicion(char simbolo, int destino);
  bool TieneTransicion(char simbolo) const;
  friend std::ostream& operator<<(std::ostream& output, const Estado& estado);

 private:
  int Id_;
  bool Es_de_aceptacion_ = false;
  std::map<char, int> simbolo_transicion_;
};

#endif
