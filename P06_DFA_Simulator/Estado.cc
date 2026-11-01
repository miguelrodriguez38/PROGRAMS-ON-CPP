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
Archivo Estado.cc
**/

#include "Estado.h"

/**
 * @brief Crea un estado.
 * @param id Identificador del estado.
 * @param es_de_aceptacion true si es un estado de aceptación.
 */
Estado::Estado(int id, bool es_de_aceptacion)
    : Id_{id}, Es_de_aceptacion_{es_de_aceptacion} {}

/**
 * @brief Devuelve el identificador del estado.
 */
int Estado::GetId() const {
  return Id_;
}

/**
 * @brief Cambia el identificador del estado.
 * @param id Nuevo identificador.
 */
void Estado::SetId(int id) {
  Id_ = id;
}

/**
 * @brief Indica si el estado es de aceptación.
 */
bool Estado::Es_de_aceptacion() const {
  return Es_de_aceptacion_;
}

/**
 * @brief Devuelve el estado al que se transita con un símbolo.
 * @param simbolo Símbolo leído.
 * @return Identificador del estado destino (lanza std::out_of_range si no hay transición).
 */
int Estado::Estado_siguiente(char simbolo) const {
  return simbolo_transicion_.at(simbolo);
}

/**
 * @brief Añade una transición.
 * @param simbolo Símbolo que dispara la transición.
 * @param destino Identificador del estado destino.
 */
void Estado::AnadirTransicion(char simbolo, int destino) {
  simbolo_transicion_[simbolo] = destino;
}

/**
 * @brief Comprueba si existe transición con un símbolo.
 * @param simbolo Símbolo a comprobar.
 * @return true si existe la transición, false si no.
 */
bool Estado::TieneTransicion(char simbolo) const {
  return simbolo_transicion_.find(simbolo) != simbolo_transicion_.end();
}

/**
 * @brief Imprime el estado como "id simbolo destino simbolo destino ...".
 * @param output Flujo de salida.
 * @param estado Estado a imprimir.
 * @return El flujo de salida.
 */
std::ostream& operator<<(std::ostream& output, const Estado& estado) {
  output << estado.Id_;
  for (const auto& [simbolo, destino] : estado.simbolo_transicion_) {
    output << " " << simbolo << " " << destino;
  }
  return output;
}
