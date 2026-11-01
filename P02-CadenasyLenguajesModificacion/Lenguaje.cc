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
Archivo Lenguaje.cc: Clase Lenguaje (metodos)


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include <set>
#include "Cadena.h"
#include "Lenguaje.h"



Lenguaje::Lenguaje() = default;
void Lenguaje::Insertar(const Cadena& cadena) {
  cadenas_.insert(cadena);
}
std::ostream& operator<<(std::ostream& output, const Lenguaje& lenguaje) {
  bool primero = true;
	output << "{";
	  for (const auto& cadena : lenguaje.cadenas_) {
			if (!primero) {
				output << ", ";
			}
		output << cadena;
		primero = false;
		}
  output << "}";
	return output;
}

