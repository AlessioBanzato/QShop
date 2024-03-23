#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMenu>
#include <QMenuBar>
#include <QVBoxLayout>

#include "src/utente.h"
#include "view/searchWidget.h"
#include "view/itemsView.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    Utente* utente_corrente;
    QLabel* name;
    SearchWidget* search;
    QMenuBar* topBar;
    ItemsView* results;
public:
    MainWindow();
    MainWindow(Utente*);
    void setUtenteCorrente(Utente* u);
    Utente* getUtente() const;
private slots:
    void close_window();
    void mostra_inventario();
public slots:
    void modificaOggetto(int);
    void confermaRimozione(int);
    void rimuoviOggetto(int);
};

#endif // MAINWINDOW_H
