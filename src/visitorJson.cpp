#include "visitorJson.h"

#include "src/album.h"
#include "src/book.h"
#include "src/movie.h"

visitorJson::visitorJson() : obj(QJsonObject()) {}

void visitorJson::visit(const Album& a) {
    obj = QJsonObject();
    obj["objtype"] = "Album";
    obj["record_label"] = QString::fromStdString(a.getLabel());
    addItemFields(a);
}

void visitorJson::visit(const Book& b) {
    obj = QJsonObject();
    obj["objtype"] = "Book";
    obj["tipo"] = QString::fromStdString(b.getTipo());
    obj["editore"] = QString::fromStdString(b.getEditore());
    addItemFields(b);
}

void visitorJson::visit(const Movie& m) {
    obj = QJsonObject();
    obj["objtype"] = "Movie";
    obj["length"] = static_cast<int>(m.getLength());
    addItemFields(m);
}

void visitorJson::addItemFields(const Item& i) {
    obj["autore"] = QString::fromStdString(i.getAutore());
    obj["titolo"] = QString::fromStdString(i.getTitolo());
    obj["genere"] = QString::fromStdString(i.getGenere());
    obj["imagePath"] = QString::fromStdString(i.getImagePath());
    obj["anno"] = static_cast<int>(i.getAnno());
    obj["quantita"] = i.getQuantita();
    obj["prezzo"] = i.getPrezzo();
    obj["codice"] = i.getCodice();
    return;
}

QJsonObject& visitorJson::getObject() {
    return obj;
}
