#include "itemEditor.h"

#include <QShortcut>

ItemEditor::ItemEditor(const QString& t, const QString& a, const QString& g, const QString& i, const QString& an, const QString& q, const QString& p, const QString& c) :
                        titolo(new EditorLine("Titolo",t)), autore(new EditorLine("Autore",a)), genere(new EditorLine("Genere",g)), anno(new EditorLine("Anno",an)),
                        imagePath(new EditorLine("Image Path",i)), quantita(new EditorLine("Quantità",q)), prezzo(new EditorLine("Prezzo",p)),
                        codice(new EditorLine("Codice",c)), edit(new QPushButton())
{
    if (titolo->getText() == QString()) {
        edit->setText("Aggiungi");
    }
    else {
        edit->setText("Modifica");
    }
    QShortcut *editShortcut = new QShortcut(QKeySequence("Return"),this);

    connect(editShortcut, &QShortcut::activated, edit, &QPushButton::click);
}

EditorLine* ItemEditor::getTitolo() const {
    return titolo;
}

EditorLine* ItemEditor::getAutore() const {
    return autore;
}

EditorLine* ItemEditor::getGenere() const {
    return genere;
}

EditorLine* ItemEditor::getAnno() const {
    return anno;
}

EditorLine* ItemEditor::getImage() const {
    return imagePath;
}

EditorLine* ItemEditor::getQuantita() const {
    return quantita;
}

EditorLine* ItemEditor::getPrezzo() const {
    return prezzo;
}

EditorLine* ItemEditor::getCodice() const {
    return codice;
}

QPushButton* ItemEditor::getButton() const {
    return edit;
}
