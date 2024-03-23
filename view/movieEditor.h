#ifndef MOVIEEDITOR_H
#define MOVIEEDITOR_H

#include "view/itemEditor.h"

class MovieEditor : public ItemEditor {
private:
    EditorLine* lunghezza;
public:
    MovieEditor(const QString& =QString(),const QString& =QString(),const QString& =QString(),const QString& =QString(),
                const QString& ="./images/",const QString& =QString(),const QString& =QString(),const QString& =QString(),
                const QString& =QString());
    EditorLine* getLength() const;
private slots:
    void applicaModifiche();
    void aggiungiProdotto();
};

#endif // MOVIEEDITOR_H
