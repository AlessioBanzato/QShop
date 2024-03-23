#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "src/vettore.h"
#include "src/item.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Inventario {
private:
    Vettore<Item*> items;
    bool unsavedChanges;
    static Inventario* instance;

    Inventario();
public:
    Inventario(const Inventario&) =delete;
    Inventario& operator=(const Inventario&) =delete;

    static Inventario& getInventario();
    static void destruct();
    Item& operator[](unsigned int);
    int getSize() const;
    int getCapacity() const;
    bool hasUnsavedChanges() const;
    void setUnsaved(bool);
    bool isEmpty() const;
    void insert(Item*);
    void erase(Item*);
    Vettore<Item*> search(std::string) const;
    Item* search(int) const;
    void saveInventario();
};

#endif // INVENTARIO_H
