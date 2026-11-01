/**
Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 1: Contenedores asociativos
Autor: Miguel Rodríguez Reyes
Correo: alu0101794976@ull.edu.es
Fecha: 15/09/2026
Archivo alumnos.h: clase declarada
Desarrolla la clase alumno

Historial de revisiones
15/09/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include <string>
#include <map>

#ifndef ALUMNOS_H
#define ALUMNOS_H

class alumnos {
 public:
  alumnos(std::string alumnos, double nota);
  double GetNota();
  std::string GetAlumnos();
  void SetNota(double nota);
  void SetAlumnos(std::string alumnos);
  bool Mayor(double nota);
  void MostrarNota(std::map<std::string, double> notas);
  void MostarNota2(std::multimap<std::string, double> notas2);
  friend std::istream& operator>>(std::istream& input, alumnos& alumno);
  friend std::ostream& operator<<(std::ostream& output, const alumnos& alumno);

 private:
  std::string alumnos_;
  double nota_;
};

#endif