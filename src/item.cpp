#include "item.h"

Item::Item(const std::string& a, const std::string& t, const std::string& g, unsigned int an, int q, double p, int c, const std::string& i) :
  autore(a), titolo(t), genere(g), imagePath(i), anno(an), quantita(q), prezzo(p), codice(c) {}

const std::string& Item::getAutore() const { return autore; }

const std::string& Item::getTitolo() const { return titolo; }

const std::string& Item::getGenere() const { return genere; }

const std::string& Item::getImagePath() const { return imagePath; }

unsigned int Item::getAnno() const { return anno; }

int Item::getCodice() const { return codice; }

int Item::getQuantita() const { return quantita; }

double Item::getPrezzo() const { return prezzo; }

void Item::setAutore(const std::string& a) { autore = a; }

void Item::setTitolo(const std::string& t) { titolo = t; }

void Item::setGenere(const std::string& g) { genere = g; }

void Item::setImagePath(const std::string& i) { imagePath = i; }

void Item::setAnno(unsigned int a) { anno = a; }

void Item::setQuantita(int q) { quantita = q; }

void Item::setPrezzo(double p) { prezzo = p; }

void Item::setCodice(int c) { codice = c; }
