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


/**
 * @brief Constructor por defecto.
 */
Lenguaje::Lenguaje() = default;
/**
 * @brief Inserta una cadena en el lenguaje.
 * @param cadena Cadena que se quiere insertar.
 */
void Lenguaje::Insertar(const Cadena& cadena) {
  cadenas_.insert(cadena);
}
/**
 * @brief Muestra el lenguaje por pantalla.
 * @param output Flujo de salida.
 * @param lenguaje Lenguaje que se quiere mostrar.
 * @return Flujo de salida.
 */
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

