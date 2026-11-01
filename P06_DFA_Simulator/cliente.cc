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
Archivo cliente.cc
**/

#include <iostream>
#include <string>
#include <cstdlib>
#include "Dfa.h"
#include <fstream>

/**
 * @brief Comprueba los parámetros de la línea de comandos y muestra la ayuda si hace falta.
 * @param argc Número de argumentos.
 * @param argv Argumentos: fichero .dfa, fichero de cadenas y, opcionalmente, n.
 * @return true si los parámetros son válidos, false si no.
 */
bool CheckParameters(int argc, char* argv[]) {
	std::string help = "--help";
	if ( argc < 3 || argv[1] == help ) {
		std::cout << "Modo de empleo: ./p06_DFA_simulator input.dfa input.txt [n]" << std::endl;
		std::cout << "  input.dfa  Fichero con la definición del DFA" << std::endl;
		std::cout << "  input.txt  Fichero con las cadenas a simular (se ignora si se indica n)" << std::endl;
		std::cout << "  n          (opcional) Genera y simula todas las cadenas de longitud <= n" << std::endl;
		std::cout << "Pruebe 'p06_DFA_simulator --help' para más información." << std::endl;
		return false;
	}
	return true;
}


/**
 * @brief Simula un DFA con las cadenas de un fichero o con todas las de longitud <= n.
 */
int main(int argc, char* argv[]) {
	if (!CheckParameters(argc, argv)) {
		return 1;
	}
	std::ifstream fichero_dfa(argv[1]);
	if ( !fichero_dfa ) {
		std::cerr << "No se pudo abrir el fichero " << argv[1] << std::endl;
		return 1;
	}
	Dfa automata;
	if ( !(fichero_dfa >> automata) ) {
		return 1;
	}

	if ( argc >= 4 ) {
		int longitud_cadena = std::atoi(argv[3]);
		if ( longitud_cadena < 0 ) {
			std::cerr << "n debe ser un entero mayor o igual que 0" << std::endl;
			return 1;
		}
		automata.SimularTodas(longitud_cadena);
		return 0;
	}

	std::ifstream fichero_cadenas(argv[2]);
	if ( !fichero_cadenas ) {
		std::cerr << "No se pudo abrir el fichero " << argv[2] << std::endl;
		return 1;
	}
	std::string cadena;
	while ( std::getline(fichero_cadenas, cadena) ) {
		automata.Simular(cadena);
	}
	return 0;
}
