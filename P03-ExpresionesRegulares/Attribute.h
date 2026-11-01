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
Archivo Attribute.h


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
 
#include <iostream>
#include <string>
 
class Attribute {
 public:
  Attribute() = default;
  Attribute(const std::string& nombre, const std::string& valor);
 
  const std::string& GetNombre() const;
  const std::string& GetValor() const;
  void SetNombre(const std::string& nombre);
  void SetValor(const std::string& valor);
 
  friend std::istream& operator>>(std::istream& input, Attribute& atributo);
  friend std::ostream& operator<<(std::ostream& output, const Attribute& atributo);
 
 private:
  std::string nombre_;
  std::string valor_;
};
 
#endif
 
