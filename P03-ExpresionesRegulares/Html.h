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
Archivo Html.h: Clase alfabeto, metodos


Historial de revisiones
20/09/2026 - Creación (primera versión) del código
**/

#ifndef HTML_H
#define HTML_H
 
#include <iostream>
#include <string>
#include <vector>
 
#include "Attribute.h"
#include "Comment.h"
#include "Link.h"
#include "Tag.h"
 
class Html {
 public:
  explicit Html(const std::string& nombre);
 
  void AñadirEtiquetas(const Tag& tag);
  void AñadirEnlace(const Link& enlace);
  void AñadirComentario(const Comment& comentario);
  void SetDescripcion(const std::string& descripcion);
  void SetDoctype(const std::string& doctype);
 
  void Escribir(std::ostream& output) const;
 
 private:
  std::string nombre_fichero_;
  std::string descripcion_;
  bool tiene_html_;
  bool tiene_head_;
  bool tiene_body_;
  std::string doctype_;
  std::vector<Tag> etiquetas_;
  std::vector<Comment> comentarios_;
  std::vector<Link> enlaces_;
};
 
#endif
