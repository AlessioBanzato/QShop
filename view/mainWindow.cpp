#include "mainWindow.h"

#include <QApplication>
#include <QScreen>
#include <QMessageBox>

#include "src/inventario.h"

#include "view/visitorEdit.h"
#include "view/albumEditor.h"
#include "view/bookEditor.h"
#include "view/movieEditor.h"


MainWindow::MainWindow() : utente_corrente(new Utente()), name(new QLabel("QSHOP")),
                            search(new SearchWidget()),
                            topBar(new QMenuBar()),
                            results(new ItemsView(this))
{}

MainWindow::MainWindow(Utente* u) : utente_corrente(u), name(new QLabel("QSHOP")),
                            search(new SearchWidget()),
                            topBar(new QMenuBar()),
                            results(new ItemsView(this))
{
    QFont f("Georgia", 30, QFont::Bold);
    name->setFont(f);

    QVBoxLayout* layout = new QVBoxLayout();
    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(layout);

    QSpacerItem* firstSpacer = new QSpacerItem(0, 50);

    layout->insertSpacerItem(0, firstSpacer);
    layout->insertWidget(1, name);
    name->setAlignment(Qt::AlignCenter);

    layout->insertSpacing(2, 25);
    layout->insertWidget(3, search);
    layout->insertSpacing(4, 50);
    layout->insertWidget(5, results);


    QMenu* uname = new QMenu(QString::fromStdString(utente_corrente->getUsername()), this);
    topBar->addMenu(uname);

    QAction* logout = new QAction("Logout", this);
    uname->addAction(logout);

    QMenu* addItem = new QMenu("Aggiungi prodotto", this);
    topBar->addMenu(addItem);

    QAction* album = new QAction("Album", addItem);
    addItem->addAction(album);
    QAction* book = new QAction("Libro", addItem);
    addItem->addAction(book);
    QAction* movie = new QAction("Film", addItem);
    addItem->addAction(movie);

    connect(album, &QAction::triggered, this, [](){
        AlbumEditor* tmp = new AlbumEditor();
        tmp->show();
    });

    connect(book, &QAction::triggered, this, [](){
        BookEditor* tmp = new BookEditor();
        tmp->show();
    });

    connect(movie, &QAction::triggered, this, [](){
        MovieEditor* tmp = new MovieEditor();
        tmp->show();
    });


    connect(logout, &QAction::triggered, this, &MainWindow::close_window);
    connect(search, &SearchWidget::giveResults, results, &ItemsView::createWidgets);

    this->setCentralWidget(centralWidget);
    this->setMenuBar(topBar);
    this->showMaximized();
}

void MainWindow::setUtenteCorrente(Utente* u) {
    utente_corrente = u;
}

Utente* MainWindow::getUtente() const {
    return utente_corrente;
}


// private slots
void MainWindow::close_window() {
    this->close();
}

void MainWindow::mostra_inventario() {
    QLabel* inventario = new QLabel("Inventario");
    inventario->setFixedSize(600, 400);
    inventario->show();
}

// public slots
void MainWindow::modificaOggetto(int codice) {
    Inventario& i = Inventario::getInventario();
    Item* item = i.search(codice);
    if(item) {
        visitorEdit v;
        item->accept(v);
        ItemEditor* tmp = v.getEditor();
        tmp->show();
    }
}

void MainWindow::confermaRimozione(int codice) {
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr,"Conferma rimozione", "Confermi la rimozione del prodotto dall'inventario?", QMessageBox::Yes|QMessageBox::No, QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        this->rimuoviOggetto(codice);
    }
}

void MainWindow::rimuoviOggetto(int codice) {
    Inventario& i = Inventario::getInventario();
    Item* item = i.search(codice);
    if(item) {
        int index = search->removeItem(item);
        results->removeWidget(index);
        i.erase(item);
    }
    search->search();
}
