// MODIFICACION NUEVA CLASE
#ifndef LINK_H
#define LINK_H
 
#include <iostream>
#include <string>
 
class Link {
 public:
  Link(int linea, const std::string& protocolo, const std::string& texto);
 
  int GetLinea() const;
  const std::string& GetProtocolo() const;
  const std::string& GetTexto() const;
 
  friend std::ostream& operator<<(std::ostream& output, const Link& enlace);
 
 private:
  int linea_;
  std::string protocolo_;
  std::string texto_;
};
 
#endif
 
