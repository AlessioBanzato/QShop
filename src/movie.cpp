#include "movie.h"

Movie::Movie(unsigned int l, const std::string& a, const std::string& t, const std::string& g, const std::string& i, unsigned int an, int q, double p, int c) :
  Item(a,t,g,an,q,p,c,i), length(l) {}

unsigned int Movie::getLength() const { return length; }

void Movie::setLength(unsigned int l) { length = l; }

void Movie::accept(absConstVisitor& v) const {
  v.visit(*this);
}

void Movie::accept(absVisitor& v) {
    v.visit(*this);
}

std::ostream& operator<<(std::ostream& os, const Movie& m) {
  os << m.getTitolo() << " - " << m.getAutore() << " - " << m.getLength() << " - " << m.getGenere() << " - " << m.getAnno()
     << " - " << m.getQuantita();
  return os;
}
