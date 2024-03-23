#include "visitorEdit.h"

#include "src/album.h"
#include "src/book.h"
#include "src/movie.h"

#include "view/albumEditor.h"
#include "view/bookEditor.h"
#include "view/movieEditor.h"

#include <QGridLayout>
#include <QVBoxLayout>

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

void visitorEdit::visit(Album& a) {
    editor = new AlbumEditor(QString::fromStdString(a.getTitolo()),QString::fromStdString(a.getAutore()),QString::fromStdString(a.getGenere()),
                             QString::number(a.getAnno()),QString::fromStdString(a.getImagePath()),QString::number(a.getQuantita()),
                             QString::number(a.getPrezzo()),QString::number(a.getCodice()),QString::fromStdString(a.getLabel()));
    return;
}

void visitorEdit::visit(Book& b) {
    editor = new BookEditor(QString::fromStdString(b.getTitolo()),QString::fromStdString(b.getAutore()),QString::fromStdString(b.getGenere()),
                             QString::number(b.getAnno()),QString::fromStdString(b.getImagePath()),QString::number(b.getQuantita()),
                             QString::number(b.getPrezzo()),QString::number(b.getCodice()),QString::fromStdString(b.getTipo()),QString::fromStdString(b.getEditore()));
    return;
}

void visitorEdit::visit(Movie& m) {
    editor = new MovieEditor(QString::fromStdString(m.getTitolo()),QString::fromStdString(m.getAutore()),QString::fromStdString(m.getGenere()),
                             QString::number(m.getAnno()),QString::fromStdString(m.getImagePath()),QString::number(m.getQuantita()),
                             QString::number(m.getPrezzo()),QString::number(m.getCodice()),QString::number(m.getLength()));
    return;
}

ItemEditor* visitorEdit::getEditor() const {
    return editor;
}
