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
Archivo p02_strings.cc: programa cliente. Lee cadenas con su alfabeto de un
fichero y les aplica la operación indicada por el código de operación.


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include <fstream>
#include <string>

#include "Alfabeto.h"
#include "Cadena.h"
#include "Lenguaje.h"

//bool CheckParameter(int argc, char* argv[]) {
//  if (argc == 2 && std::string(argv[1]) == "--help") {
//    return true;
//  } else if (argc != 4) {
//    std::cerr << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode" << std::endl;
//    std::cerr << "Pruebe './p02_strings --help' para más información." << std::endl;
//    return false;
//  } else {
//    return true;
//  }
//}

void help(void) {
  std::cout << "Este programa lee cadenas con su alfabeto desde un fichero "
            << "y les aplica una operación, escribiendo el resultado en otro fichero."
            << std::endl;
  std::cout << "Formato del fichero de entrada (una cadena por línea):" << std::endl;
  std::cout << "cadena alfabeto" << std::endl;
  std::cout << "Ejemplo: abbab ab" << std::endl;
  std::cout << "Códigos de operación:" << std::endl;
  std::cout << "1 Alfabeto" << std::endl;
  std::cout << "2 Longitud" << std::endl;
  std::cout << "3 Inversa" << std::endl;
  std::cout << "4 Prefijos" << std::endl;
  std::cout << "5 Sufijos" << std::endl;
  std::cout << "6 Validación (OK / ERROR)" << std::endl;
  return;
}


int main (int argc, char* argv[]) {

//  if (!CheckParameter(argc, argv)) {
//    return 1;
//  }
  std::string anadido = argv[4];
  std::string option = argv[1];
  if ( option == "--help") {
    help();
  } else {
   int numero = std::atoi(argv[3]);
   if ( numero > 7|| numero < 1 ) {
    return 1;
   }
   std::ifstream filein(argv[1]);    
   std::ofstream fileout(argv[2]);
	 Cadena cadena;
	 while (filein >> cadena) {
		switch (numero) {
			case 1:
				fileout << cadena << ": " << cadena.GetAlfabeto() << std::endl;
				break;
			case 2:
				fileout << cadena.Longitud() << std::endl;
				break;
			case 3:
				fileout << cadena << " -> " << cadena.Inversa() << std::endl;
				break;
			case 4:
				fileout << Prefijos(cadena) << std::endl;
				break;
			case 5:
				fileout << Sufijos(cadena) << std::endl;
				break;
			case 6:
				if (cadena.EsValida()) {
					fileout << "OK" << std::endl;
				} else {
					fileout << "ERROR" << std::endl;
				}
				break;
      case 7:
        fileout << cadena.Concatenacion(argv[4]) << std::endl;
        break;  
		}
   }
	}
}