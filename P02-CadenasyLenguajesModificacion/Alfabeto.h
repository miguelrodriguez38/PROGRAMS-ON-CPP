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
Archivo Alfabeto.h: Clase alfabeto


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include <iostream>
#include <set>
#include <string>

#ifndef ALFABETO_H
#define ALFABETO_H

class Alfabeto{
 public:
  Alfabeto();
	Alfabeto(const std::string& cadena);
	bool Contiene(char presente) const;
	friend std::ostream& operator<<(std::ostream& output, const Alfabeto& alfabeto);
	friend std::istream& operator>>(std::istream& input, Alfabeto& alfabeto);

 private:
	std::set<char> simbolos_;


};

#endif