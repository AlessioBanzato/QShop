#include "inventario.h"

#include "src/visitorSearch.h"
#include "src/visitorJson.h"

Inventario* Inventario::instance = nullptr;

// metodi privati

Inventario::Inventario() : items(), unsavedChanges(false) {
    QFile inventario("inventario.json");

    if(!inventario.open(QIODevice::ReadOnly)) {
        qDebug() << "Errore nell'apertura del file 'inventario.json'";
        exit(1);
    }

    QByteArray jsonData = inventario.readAll();
    inventario.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    if (!jsonDocument.isArray()) {
        qDebug() << "'inventario.json' non contiene array";
        exit(1);
    }

    QJsonArray itemsArray = jsonDocument.array();

    for (const QJsonValue& value : itemsArray) {
        if (!value.isObject()) {
          qDebug() << "L'elemento non è un itemObject JSON";
          continue;
        }

        QJsonObject itemObject = value.toObject();

        if (itemObject["objtype"] == "Album") {
            Item* tmp = new Album(
                itemObject["record_label"].toString().toStdString(),
                itemObject["autore"].toString().toStdString(),
                itemObject["titolo"].toString().toStdString(),
                itemObject["genere"].toString().toStdString(),
                itemObject["imagePath"].toString().toStdString(),
                itemObject["anno"].toInt(),
                itemObject["quantita"].toInt(),
                itemObject["prezzo"].toDouble(),
                itemObject["codice"].toInt()
            );
            items.insert(tmp);
        }
        else if (itemObject["objtype"] == "Book") {
            Item* tmp = new Book(
                itemObject["tipo"].toString().toStdString(),
                itemObject["editore"].toString().toStdString(),
                itemObject["autore"].toString().toStdString(),
                itemObject["titolo"].toString().toStdString(),
                itemObject["genere"].toString().toStdString(),
                itemObject["imagePath"].toString().toStdString(),
                itemObject["anno"].toInt(),
                itemObject["quantita"].toInt(),
                itemObject["prezzo"].toDouble(),
                itemObject["codice"].toInt()
            );
            items.insert(tmp);
        }
        else if (itemObject["objtype"] == "Movie") {
            Item* tmp = new Movie(
                itemObject["length"].toInt(),
                itemObject["autore"].toString().toStdString(),
                itemObject["titolo"].toString().toStdString(),
                itemObject["genere"].toString().toStdString(),
                itemObject["imagePath"].toString().toStdString(),
                itemObject["anno"].toInt(),
                itemObject["quantita"].toInt(),
                itemObject["prezzo"].toDouble(),
                itemObject["codice"].toInt()
            );
            items.insert(tmp);
        }
    }
}


// metodi pubblici

Inventario& Inventario::getInventario() {
    if (!instance)
        instance = new Inventario();
    return *instance;
}

void Inventario::destruct() {
    delete instance;
    instance = nullptr;
}

Item& Inventario::operator[](unsigned int i) {
    return *(items[i]);
}

int Inventario::getSize() const {
    return items.getSize();
}

int Inventario::getCapacity() const {
    return items.getCapacity();
}

bool Inventario::hasUnsavedChanges() const {
    return unsavedChanges;
}

void Inventario::setUnsaved(bool b) {
    unsavedChanges = b;
    return;
}

bool Inventario::isEmpty() const {
    return items.isEmpty();
}

void Inventario::insert(Item* i) {
    items.insert(i);
    if(!unsavedChanges) unsavedChanges = true;
}

void Inventario::erase(Item* i) {
    items.erase(i);
    if(!unsavedChanges) unsavedChanges = true;
}

Vettore<Item*> Inventario::search(std::string s) const {
    visitorSearch v(s);
    Vettore<Item*> tmp;
    int size = items.getSize();
    for(int i = 0; i < size; i++) {
        items[i]->accept(v);
        if (v.getPresenza()) tmp.insert(items[i]);
    }
    return tmp;
}

Item* Inventario::search(int c) const {
    for(int i = 0; i < items.getSize(); i++)
        if (items[i]->getCodice() == c) return items[i];
    return nullptr;
}

void Inventario::saveInventario() {
    QString fileName = "inventario.json";
    QJsonArray jsonArray;
    visitorJson v;

    for (int i = 0; i < getSize(); i++) {
        (this->operator[](i)).accept(v);
        QJsonObject itemObject = v.getObject();
        jsonArray.append(itemObject);
    }

    QJsonDocument jsonDocument(jsonArray);

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonDocument.toJson());
        file.close();
    }
}
