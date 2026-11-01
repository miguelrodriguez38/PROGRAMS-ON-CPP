/**
Universidad de La Laguna
Escuela Superior de Ingeniería y Tecnología
Grado en Ingeniería Informática
Asignatura: Computabilidad y Algoritmia
Curso: 2º
Práctica 3: Regex
Autor: Miguel Rodríguez Reyes
Correo: alu0101794976@ull.edu.es
Fecha: 06/10/2026
Archivo Attribute.cc


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/


#include "Attribute.h"
 
Attribute::Attribute(const std::string& nombre, const std::string& valor) : nombre_{nombre}, valor_{valor} {}
 
const std::string& Attribute::GetNombre() const {
  return nombre_;
}
 
const std::string& Attribute::GetValor() const {
  return valor_;
}
 
void Attribute::SetNombre(const std::string& nombre) {
  nombre_ = nombre;
}
 
void Attribute::SetValor(const std::string& valor) {
  valor_ = valor;
}
 
std::istream& operator>>(std::istream& input, Attribute& atributo) {
  input >> atributo.nombre_;
  input >> atributo.valor_;
  return input;
}
 
std::ostream& operator<<(std::ostream& output, const Attribute& atributo) {
  output << atributo.nombre_ << " = " << atributo.valor_;
  return output;
}
 

