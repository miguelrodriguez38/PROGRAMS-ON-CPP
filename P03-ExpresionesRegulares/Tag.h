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
Archivo Tag.h


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/
 
#ifndef TAG_H
#define TAG_H
 
#include <iostream>
#include <string>
#include <vector>
 
#include "Attribute.h"
 
class Tag {
 public:
  Tag(const std::string& nombre, int linea, bool es_de_cierre);
 
  void IntroducirAtributo(const Attribute& atributo);
  const std::string& GetNombre() const;
  int GetLinea() const;
  bool EsDeCierre() const;
  int GetNumAtributos() const;
  bool TieneAtributos() const;
  const std::vector<Attribute>& GetAtributos() const;
 
  void ImprimirAtributos(std::ostream& output) const;
 
  friend std::ostream& operator<<(std::ostream& output, const Tag& tag);
 
 private:
  std::string nombre_;
  int linea_;
  bool es_de_cierre_;
  std::vector<Attribute> atributos_;
};
 
#endif
 
