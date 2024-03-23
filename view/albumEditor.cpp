#include "albumEditor.h"

#include "src/inventario.h"
#include "src/album.h"

AlbumEditor::AlbumEditor(const QString& t, const QString& a, const QString& g, const QString& an, const QString& i, const QString& q, const QString& p, const QString& c, const QString& l) :
                            ItemEditor(t,a,g,i,an,q,p,c), label(new EditorLine("Label", l))
{
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(getTitolo());
    layout->addWidget(getAutore());
    layout->addWidget(getGenere());
    layout->addWidget(getAnno());
    layout->addWidget(label);
    layout->addWidget(getImage());
    layout->addWidget(getQuantita());
    layout->addWidget(getPrezzo());
    layout->addWidget(getCodice());
    layout->addWidget(getButton());

    if(getTitolo()->getText() == QString()) {
        connect(getButton(), &QPushButton::clicked, this, &AlbumEditor::aggiungiProdotto);
    }
    else {
        connect(getButton(), &QPushButton::clicked, this, &AlbumEditor::applicaModifiche);
    }
}

EditorLine* AlbumEditor::getLabel() const {
    return label;
}

// private slots
void AlbumEditor::applicaModifiche() {
    Inventario& i = Inventario::getInventario();
    Album* tmp = dynamic_cast<Album*>(i.search(getCodice()->getText().toInt()));
    if(!tmp) return;
    tmp->setTitolo(getTitolo()->getText().toStdString());
    tmp->setAutore(getAutore()->getText().toStdString());
    tmp->setGenere(getGenere()->getText().toStdString());
    tmp->setAnno(getAnno()->getText().toInt());
    tmp->setImagePath(getImage()->getText().toStdString());
    tmp->setQuantita(getQuantita()->getText().toInt());
    tmp->setPrezzo(getPrezzo()->getText().toDouble());
    tmp->setCodice(getCodice()->getText().toInt());
    tmp->setLabel(getLabel()->getText().toStdString());
    if(!i.hasUnsavedChanges()) i.setUnsaved(true);
    delete this;
    return;
}

void AlbumEditor::aggiungiProdotto() {
    Inventario& i = Inventario::getInventario();
    Item* tmp = new Album(
                getLabel()->getText().toStdString(),
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
