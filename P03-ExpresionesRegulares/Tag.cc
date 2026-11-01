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
Archivo Tag.cc
 
 
Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include "Tag.h"
 
Tag::Tag(const std::string& nombre, int linea, bool es_de_cierre)
    : nombre_{nombre}, linea_{linea}, es_de_cierre_{es_de_cierre} {}
 
void Tag::IntroducirAtributo(const Attribute& atributo) {
  atributos_.push_back(atributo);
}
 
const std::string& Tag::GetNombre() const {
  return nombre_;
}
 
int Tag::GetLinea() const {
  return linea_;
}
 
bool Tag::EsDeCierre() const {
  return es_de_cierre_;
}
 
int Tag::GetNumAtributos() const {
  return atributos_.size();
}
 
bool Tag::TieneAtributos() const {
  return !atributos_.empty();
}
 
const std::vector<Attribute>& Tag::GetAtributos() const {
  return atributos_;
}
 
void Tag::ImprimirAtributos(std::ostream& output) const {
  output << *this << std::endl;
  for (const auto& atributo : atributos_) {
    output << atributo << std::endl;
  }
  output << std::endl;
}
 
std::ostream& operator<<(std::ostream& output, const Tag& tag) {
  output << "[Line " << tag.linea_ << "] ";
  if (!tag.es_de_cierre_) {
    output << tag.nombre_;
  } else {
    output << "/ " << tag.nombre_;
  }
  return output;
}
 
