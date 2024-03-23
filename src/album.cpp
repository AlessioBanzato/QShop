#include "album.h"

Album::Album(const std::string& l, const std::string& a, const std::string& t, const std::string& g, const std::string& i, unsigned int an, int q, double p, int c) :
  Item(a,t,g,an,q,p,c,i), record_label(l) {}

const std::string& Album::getLabel() const { return record_label; }

void Album::setLabel(const std::string& l) { record_label = l; }

void Album::accept(absConstVisitor& v) const {
    v.visit(*this);
}

void Album::accept(absVisitor& v) {
    v.visit(*this);
}

std::ostream& operator<<(std::ostream& os, const Album& a) {
  os << a.getTitolo() << " - " << a.getAutore() << " - " << a.getGenere() << " - " << a.getLabel()
     << " - " << a.getAnno() << " - " << a.getQuantita();
  return os;
}
