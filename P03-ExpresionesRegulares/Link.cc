//MODIFICACION NUEVA CLASE
#include "Link.h"
 
Link::Link(int linea, const std::string& protocolo, const std::string& texto)
    : linea_{linea}, protocolo_{protocolo}, texto_{texto} {}
 
int Link::GetLinea() const {
  return linea_;
}
 
const std::string& Link::GetProtocolo() const {
  return protocolo_;
}
 
const std::string& Link::GetTexto() const {
  return texto_;
}
 
std::ostream& operator<<(std::ostream& output, const Link& enlace) {
  output << "[Line " << enlace.linea_ << "]" << std::endl;
  output << "PROTOCOL: " << enlace.protocolo_ << std::endl;
  output << "TEXT: " << enlace.texto_ << std::endl;
  return output;
}
 
