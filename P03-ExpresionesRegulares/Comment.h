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
Archivo Comment.h


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#ifndef COMMENT_H
#define COMMENT_H
 
#include <iostream>
#include <string>
 
class Comment {
 public:
  Comment(int linea_inicio, int linea_fin, const std::string& texto,
          bool es_descripcion);
 
  int GetLineaInicio() const;
  int GetLineaFin() const;
  const std::string& GetTexto() const;
  bool EsDescripcion() const;
 
  friend std::ostream& operator<<(std::ostream& output,
                                  const Comment& comentario);
 
 private:
  int linea_inicio_;
  int linea_fin_;
  std::string texto_;
  bool es_descripcion_;
};
 
#endif


