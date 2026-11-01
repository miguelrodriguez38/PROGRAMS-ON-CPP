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
Archivo p01_single_grades.cc: programa dado la mayor nota


Historial de revisiones
15/09/2026 - Creación (primera versión) del código
**/

#include "alumnos.h"
#include <iostream>
#include <fstream>
#include <map>



//bool CheckParameter(int argc) {
//  if (argc != 2) {
//    std::cerr << "Modo de empleo: ./p01_single_grades grades.txt" << std::endl;
//    std::cerr << "Pruebe ’p01_single_grades --help’ para más información." << std::endl;
//    return false;
//  } else {
//    return true;
//  }
//}

void help(void) {
  std::cout << "Este programa lee las calificaciones de los estudiantes "
        << "desde un fichero y almacena la nota maxima de cada alumno."
        << std::endl;
    std::cout << "Formato del fichero:" << std::endl;
    std::cout << "aluXXXXXXXXXX nota" << std::endl;
    std::cout << "Ejemplo: alu0101010101 9.25" << std::endl;
    return;
}

void error(char* argv[]) {
  std::ifstream file(argv[1]);
  if (!file) {
    std::cerr << "Error: cannot open file." << std::endl;
    return;
  } else {
    std::cout << "File opened successfully." << std::endl;
  }
}

int main (int argc, char* argv[]) {

//if (!CheckParameter(argc)) {
//    return 1;
//  }

  std::string option = argv[1];
  if ( option == "--help") {
    help();
  } else {
    error(argv);
  }
  std::ifstream file(argv[1]);
  alumnos alumno(" ",0);
  std::map<std::string, double> notas;
  while ( file >> alumno ) {
    if ( notas.find(alumno.GetAlumnos()) == notas.end()) {  // si no estaba en el map
      notas[alumno.GetAlumnos()] = alumno.GetNota(); // actualizo el map
    } else {
      if (alumno.Mayor(notas[alumno.GetAlumnos()])) { // si ya estaba en el map comparo la nueva nota con la antigua 
        notas[alumno.GetAlumnos()] = alumno.GetNota(); // si se cumple se asigna una nueva nota
      }
    }
  }
  std::string alumnoenbusqueda = argv[3];

  alumno.MostrarNota(notas);
  std::string option2 = argv[2];
  if ( option2 == "--search") {
    if ( notas.find(alumnoenbusqueda) == notas.end()) {  // si no estaba en el map
      std::cout << "No se ha encontrado el estudiante" << std::endl;
    } else {
      std::cout << notas[alumnoenbusqueda]; // si lo encuentro imprimo su nota   
    }
  }
}