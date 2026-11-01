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
Archivo Alfabeto.cc: Clase alfabeto, metodos


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include <set>
#include <string>
#include "Alfabeto.h"



Alfabeto::Alfabeto() = default;
Alfabeto::Alfabeto(const std::string& cadena) {
	for ( char c : cadena ) {
		if(c != '&') {
			simbolos_.insert(c);  // insert es propio de la libreria set
		}
	}
}

bool Alfabeto::Contiene(char presente) const {
	if (simbolos_.count(presente)) {   // count es propio de la libreria set devuleve 1 si esta y 0 si no esta
		return true;
	} else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& output, const Alfabeto& alfabeto)  {
	bool primero = true;
	output << "{";
	for ( const auto& alfabeto : alfabeto.simbolos_ ) {
		if (!primero) {
			output << ", ";
		}
		output << alfabeto;
		primero = false;
	}
	output << "}";
	return output;
}

std::istream& operator>>(std::istream& input, Alfabeto& alfabeto) {
	std::string aux;
	input >> aux;
	alfabeto = Alfabeto(aux); // usamos el constructor
	return input;
}



