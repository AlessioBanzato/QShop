#ifndef ITEMSVIEW_H
#define ITEMSVIEW_H

#include <QWidget>
#include <QScrollArea>

#include "view/searchWidget.h"

class MainWindow;

class ItemsView : public QWidget {
    Q_OBJECT
private:
    QWidget* mainWidget;
    Vettore<QWidget*> widgets;
    QScrollArea* area;
    QVBoxLayout* mainLayout;
    QGridLayout* gridLayout;
    MainWindow* parent;
public:
    ItemsView(MainWindow*);
    void showWidgets() const;
    void addWidgets() const;
    void removeWidget(int);
public slots:
    void createWidgets(SearchWidget*);
};

#endif // ITEMSVIEW_H
