#ifndef BOOKEDITOR_H
#define BOOKEDITOR_H

#include "view/itemEditor.h"

class BookEditor : public ItemEditor {
private:
    EditorLine* tipo, *editore;
public:
    BookEditor(const QString& =QString(),const QString& =QString(),const QString& =QString(),const QString& =QString(),
               const QString& ="./images/",const QString& =QString(),const QString& =QString(),const QString& =QString(),
               const QString& =QString(),const QString& =QString());
    EditorLine* getTipo() const;
    EditorLine* getEditore() const;
private slots:
    void applicaModifiche();
    void aggiungiProdotto();
};

#endif // BOOKEDITOR_H
