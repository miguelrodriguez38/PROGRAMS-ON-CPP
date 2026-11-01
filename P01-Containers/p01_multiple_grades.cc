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
Archivo p01_multiple_grades.cc: programa dado multiples notas


Historial de revisiones
15/09/2026 - Creación (primera versión) del código
**/

#include "alumnos.h"
#include <iostream>
#include <fstream>
#include <map>



bool CheckParameter(int argc) {
  if (argc != 2) {
    std::cerr << "Modo de empleo: ./p01_single_grades grades.txt" << std::endl;
    std::cerr << "Pruebe ’p01_single_grades --help’ para más información." << std::endl;
    return false;
  } else {
    return true;
  }
}

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

  if (!CheckParameter(argc)) {
    return 1;
  }
  std::string option = argv[1];
  if ( option == "--help") {
    help();
  } else {
    error(argv);
  }

  std::ifstream file(argv[1]);
  alumnos alumno(" ",0); // Creamos el objeto
  std::multimap<std::string, double> notas2;
  while ( file >> alumno ) {
    notas2.insert({alumno.GetAlumnos(), alumno.GetNota()});  // Insert es muy util en multimap
  }
  alumno.MostarNota2(notas2);
}