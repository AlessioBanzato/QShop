#include "movieEditor.h"

#include "src/inventario.h"
#include "src/movie.h"

MovieEditor::MovieEditor(const QString& t, const QString& a, const QString& g, const QString& an, const QString& i, const QString& q, const QString& p, const QString& c, const QString& l) :
                            ItemEditor(t,a,g,i,an,q,p,c), lunghezza(new EditorLine("Lunghezza (minuti)", l))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(getTitolo());
    layout->addWidget(getAutore());
    layout->addWidget(getGenere());
    layout->addWidget(getAnno());
    layout->addWidget(lunghezza);
    layout->addWidget(getImage());
    layout->addWidget(getQuantita());
    layout->addWidget(getPrezzo());
    layout->addWidget(getCodice());
    layout->addWidget(getButton());

    if(getTitolo()->getText() == QString()) {
        connect(getButton(), &QPushButton::clicked, this, &MovieEditor::aggiungiProdotto);
    }
    else {
        connect(getButton(), &QPushButton::clicked, this, &MovieEditor::applicaModifiche);
    }
}

EditorLine* MovieEditor::getLength() const {
    return lunghezza;
}

// private slots
void MovieEditor::applicaModifiche() {
    Inventario& i = Inventario::getInventario();
    Movie* tmp = dynamic_cast<Movie*>(i.search(getCodice()->getText().toInt()));
    if(!tmp) return;
    tmp->setTitolo(getTitolo()->getText().toStdString());
    tmp->setAutore(getAutore()->getText().toStdString());
    tmp->setGenere(getGenere()->getText().toStdString());
    tmp->setAnno(getAnno()->getText().toInt());
    tmp->setLength(getLength()->getText().toInt());
    tmp->setImagePath(getImage()->getText().toStdString());
    tmp->setQuantita(getQuantita()->getText().toInt());
    tmp->setPrezzo(getPrezzo()->getText().toDouble());
    tmp->setCodice(getCodice()->getText().toInt());
    if(!i.hasUnsavedChanges()) i.setUnsaved(true);
    delete this;
    return;
}

void MovieEditor::aggiungiProdotto() {
    Inventario& i = Inventario::getInventario();
    Item* tmp = new Movie(
                getLength()->getText().toInt(),
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
