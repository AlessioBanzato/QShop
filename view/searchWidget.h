#ifndef SEARCHWIDGET_H
#define SEARCHWIDGET_H

#include <QLineEdit>
#include <QPushButton>
#include <QShortcut>
#include <QHBoxLayout>

#include "src/vettore.h"
#include "src/item.h"

class SearchWidget : public QWidget {
    Q_OBJECT
private:
    QLineEdit* searchBar;
    QPushButton* searchButton;
    Vettore<Item*> results;
public:
    SearchWidget();
    Item* getItem(int);
    int resultsNumber() const;
    int removeItem(Item*);
signals:
    void giveResults(SearchWidget*);
public slots:
    void search();
};

#endif // SEARCHWIDGET_H
