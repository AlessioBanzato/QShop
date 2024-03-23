#ifndef ITEMEDITOR_H
#define ITEMEDITOR_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

#include "view/editorLine.h"

class ItemEditor : public QWidget {
    Q_OBJECT
private:
    EditorLine* titolo, *autore, *genere, *anno, *imagePath, *quantita, *prezzo, *codice;
    QPushButton* edit;
public:
    ItemEditor(const QString& =QString(),const QString& =QString(),const QString& =QString(),const QString& =QString(),
               const QString& ="./images/", const QString& =QString(),const QString& =QString(),const QString& =QString());
    EditorLine* getTitolo() const;
    EditorLine* getAutore() const;
    EditorLine* getGenere() const;
    EditorLine* getAnno() const;
    EditorLine* getImage() const;
    EditorLine* getQuantita() const;
    EditorLine* getPrezzo() const;
    EditorLine* getCodice() const;
    QPushButton* getButton() const;
};

#endif // ITEMEDITOR_H
