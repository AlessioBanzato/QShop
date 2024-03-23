#include "book.h"

Book::Book(const std::string& t, const std::string& e, const std::string& a, const std::string& ti, const std::string& g, const std::string& i, unsigned int an, int q, double p, int c) :
  Item(a,ti,g,an,q,p,c,i), tipo(t), editore(e) {}

const std::string& Book::getTipo() const { return tipo; }

const std::string& Book::getEditore() const { return editore; }

void Book::setTipo(const std::string& t) { tipo = t; }

void Book::setEditore(const std::string& e) { editore = e; }

void Book::accept(absConstVisitor& v) const {
  v.visit(*this);
}

void Book::accept(absVisitor& v) {
    v.visit(*this);
}

std::ostream& operator<<(std::ostream& os, const Book& b) {
  os << b.getTitolo() << " - " << b.getAutore() << " - " << b.getTipo() << " - " << b.getGenere() << " - "
     << b.getEditore() << " - " << b.getAnno() << " - " << b.getQuantita();
  return os;
}
