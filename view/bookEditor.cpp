#include "bookEditor.h"

#include "src/inventario.h"
#include "src/book.h"

BookEditor::BookEditor(const QString& t, const QString& a, const QString& g, const QString& an, const QString& i, const QString& q, const QString& p, const QString& c, const QString& tp, const QString& e) :
                        ItemEditor(t,a,g,i,an,q,p,c), tipo(new EditorLine("Tipo", tp)), editore(new EditorLine("Editore", e))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(getTitolo());
    layout->addWidget(getAutore());
    layout->addWidget(tipo);
    layout->addWidget(getGenere());
    layout->addWidget(getAnno());
    layout->addWidget(editore);
    layout->addWidget(getImage());
    layout->addWidget(getQuantita());
    layout->addWidget(getPrezzo());
    layout->addWidget(getCodice());
    layout->addWidget(getButton());

    if(getTitolo()->getText() == QString()) {
        connect(getButton(), &QPushButton::clicked, this, &BookEditor::aggiungiProdotto);
    }
    else {
        connect(getButton(), &QPushButton::clicked, this, &BookEditor::applicaModifiche);
    }}

EditorLine* BookEditor::getTipo() const {
    return tipo;
}

EditorLine* BookEditor::getEditore() const {
    return editore;
}

// private slots
void BookEditor::applicaModifiche() {
    Inventario& i = Inventario::getInventario();
    Book* tmp = dynamic_cast<Book*>(i.search(getCodice()->getText().toInt()));
    if(!tmp) return;
    tmp->setTitolo(getTitolo()->getText().toStdString());
    tmp->setAutore(getAutore()->getText().toStdString());
    tmp->setTipo(getTipo()->getText().toStdString());
    tmp->setGenere(getGenere()->getText().toStdString());
    tmp->setAnno(getAnno()->getText().toInt());
    tmp->setEditore(getEditore()->getText().toStdString());
    tmp->setImagePath(getImage()->getText().toStdString());
    tmp->setQuantita(getQuantita()->getText().toInt());
    tmp->setPrezzo(getPrezzo()->getText().toDouble());
    tmp->setCodice(getCodice()->getText().toInt());
    if(!i.hasUnsavedChanges()) i.setUnsaved(true);
    delete this;
    return;
}

void BookEditor::aggiungiProdotto() {
    Inventario& i = Inventario::getInventario();
    Item* tmp = new Book(
                getTipo()->getText().toStdString(),
                getEditore()->getText().toStdString(),
                getAutore()->getText().toStdString(),
                getTitolo()->getText().toStdString(),
                getGenere()->getText().toStdString(),
                getImage()->getText().toStdString(),
                getAnno()->getText().toInt(),
                getQuantita()->getText().toInt(),
                getPrezzo()->getText().toDouble(),
                getCodice()->getText().toInt()
                );
    i.insert(tmp);
    delete this;
    return;
}
