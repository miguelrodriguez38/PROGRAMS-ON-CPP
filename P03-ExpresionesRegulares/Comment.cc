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
Archivo Comment.cc


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#include "Comment.h"
 
Comment::Comment(int linea_inicio, int linea_fin, const std::string& texto, bool es_descripcion)
 : linea_inicio_{linea_inicio}, linea_fin_{linea_fin}, texto_{texto}, es_descripcion_{es_descripcion} {}
 
int Comment::GetLineaInicio() const {
  return linea_inicio_;
}
 
int Comment::GetLineaFin() const {
  return linea_fin_;
}
 
const std::string& Comment::GetTexto() const {
  return texto_;
}
 
bool Comment::EsDescripcion() const {
  return es_descripcion_;
}
 
std::ostream& operator<<(std::ostream& output, const Comment& comentario) {
  if (comentario.es_descripcion_) {
    output << "[Line " << comentario.linea_inicio_ << "] DESCRIPTION";
  } else if (comentario.linea_fin_ != comentario.linea_inicio_) {
    output << "[Line " << comentario.linea_inicio_ << "-"
           << comentario.linea_fin_ << "]";
  } else {
    output << "[Line " << comentario.linea_inicio_ << "]";
  }
  output << std::endl;
  output << comentario.texto_ << std::endl;
  return output;
}
 
