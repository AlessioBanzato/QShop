#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

#include "absConstVisitor.h"
#include "absVisitor.h"

class Item {
private:
    std::string autore, titolo, genere, imagePath;
    unsigned int anno;
    int quantita;
    double prezzo;
    int codice; // codice identificativo del prodotto
public:
    Item(const std::string&, const std::string&, const std::string&, unsigned int, int, double, int, const std::string& ="");
    const std::string& getAutore() const;
    const std::string& getTitolo() const;
    const std::string& getGenere() const;
    const std::string& getImagePath() const;
    unsigned int getAnno() const;
    int getQuantita() const;
    double getPrezzo() const;
    int getCodice() const;
    void setAutore(const std::string&);
    void setTitolo(const std::string&);
    void setGenere(const std::string&);
    void setImagePath(const std::string&);
    void setAnno(unsigned int);
    void setQuantita(int);
    void setPrezzo(double);
    void setCodice(int);
    virtual ~Item() =default;

    virtual void accept(absConstVisitor&) const =0;
    virtual void accept(absVisitor&) =0;
};

#endif
