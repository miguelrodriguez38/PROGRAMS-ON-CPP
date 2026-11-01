/**
Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 6: Simulador de Automatas
Autor: Miguel Rodríguez Reyes
Correo: alu0101794976@ull.edu.es
Fecha: 21/10/2026
Archivo Produccion.cc
**/

#include "Produccion.h"
#include <string>
#include <iostream>

Produccion::Produccion(std::string parte_izquierda, std::string parte_derecha) : parte_izquierda_{parte_izquierda}, 
        parte_derecha_{parte_derecha} {}


std::ostream& operator<<(std::ostream& salida, const Produccion& produccion) {
    salida << produccion.parte_izquierda_ << " --> " << produccion.parte_derecha_;
    return salida;
}