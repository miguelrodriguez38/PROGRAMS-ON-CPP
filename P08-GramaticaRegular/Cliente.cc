#include <fstream>
#include <iostream>
#include <string>

#include "Automata.h"
#include "Gramatica.h"

/**
 * @brief Muestra el uso del programa.
 */
void MostrarModoDeEmpleo() {
  std::cout << "Modo de empleo: ./dfa2grammar input.dfa output.gra [lineal]\n"
            << "Pruebe 'dfa2grammar --help' para más información.\n";
}

/**
 * @brief Muestra la ayuda del programa.
 */
void MostrarAyuda() {
  std::cout << "dfa2grammar: genera una gramática regular a partir de un DFA.\n"
            << "Uso: ./dfa2grammar input.dfa output.gra [lineal]\n"
            << "  input.dfa   fichero con la especificación del DFA.\n"
            << "  output.gra  fichero donde se escribe la gramática regular G,\n"
            << "              tal que L(G) = L(M).\n"
            << "  lineal      (opcional) muestra junto a cada produccion si es lineal\n"
            << "              por la izquierda, por la derecha o ambas.\n";
}

int main(int argc, char* argv[]) {
  if (argc == 1) {
    MostrarModoDeEmpleo();
    return 0;
  }
  if (argc == 2 && std::string(argv[1]) == "--help") {
    MostrarAyuda();
    return 0;
  }
  if (argc != 3 && argc != 4) {
    MostrarModoDeEmpleo();
    return 1;
  }
  std::ifstream fichero_entrada(argv[1]);
  if (!fichero_entrada.is_open()) {
    std::cerr << "No se pudo abrir el fichero " << argv[1] << std::endl;
    return 1;
  }
  bool mostrar_lineal = false;
  if (argc == 4) {
    if (std::string(argv[3]) != "lineal") {
      MostrarModoDeEmpleo();
      return 1;
    }
    mostrar_lineal = true;
  }
  Automata automata;
  if (!(fichero_entrada >> automata)) {
    std::cerr << "El fichero " << argv[1] << " no tiene un DFA válido" << std::endl;
    return 1;
  }
  Gramatica gramatica = automata.ConvertToGrammar();
  gramatica.EscribirEnFichero(argv[2], mostrar_lineal);
  return 0;
}