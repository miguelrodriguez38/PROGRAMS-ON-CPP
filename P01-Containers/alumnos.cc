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
Archivo alumnos.cc: clase definida
Desarrolla la clase alumno

Historial de revisiones
15/09/2026 - Creación (primera versión) del código
**/


#include <iostream>
#include <string>
#include <map>
#include "alumnos.h"


alumnos::alumnos(std::string alumnos, double nota) : alumnos_{alumnos}, nota_{nota} {};
double alumnos::GetNota(){ return nota_;}
std::string alumnos::GetAlumnos() { return alumnos_;}
void alumnos::SetNota(double nota) { nota_ = nota;}
void alumnos::SetAlumnos(std::string alumnos) { alumnos_ = alumnos;}
bool alumnos::Mayor(double nota) { //nota es la del map ya que la estas pasando
  return nota_ > nota;
}
void alumnos::MostrarNota(std::map<std::string, double> notas) {
  for (const auto& elemento : notas) {
    std::cout << elemento.first << " " << elemento.second << std::endl;
  }
}

void alumnos::MostarNota2(std::multimap<std::string, double> notas2) {
  std::string aluAnterior = "";
  for (const auto& elemento : notas2) {
    if (elemento.first != aluAnterior) {
      std::cout << std::endl;
      std::cout << elemento.first << ": " << elemento.second;
      aluAnterior = elemento.first;  //Actualizamos el alu
    } else {
      std::cout << " " << elemento.second;
    }
  }
  std::cout << std::endl;
}




std::istream& operator>>(std::istream& input, alumnos& alumno) {  
  input >> alumno.alumnos_ >> alumno.nota_;
  return input;
}
std::ostream& operator<<(std::ostream& output, const alumnos& alumno) {
  output << alumno.alumnos_ << " " << alumno.nota_ << std::endl;
  return output;
}

