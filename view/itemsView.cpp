#include "itemsView.h"
#include "view/visitorItems.h"

#include "mainWindow.h"

#include <QScrollArea>

ItemsView::ItemsView(MainWindow* p) : mainWidget(new QWidget()), widgets(), area(new QScrollArea()),
                                mainLayout(new QVBoxLayout()), gridLayout(new QGridLayout()), parent(p)
{
    mainWidget->setLayout(gridLayout);
    area->setWidgetResizable(true);
    area->setWidget(mainWidget);

    mainLayout->addWidget(area);
    setLayout(mainLayout);
}

void ItemsView::showWidgets() const {
    for(int i = 0; i < widgets.getSize(); i++)
        widgets[i]->show();
    return;
}

void ItemsView::addWidgets() const {
    QLayoutItem* item;
    while ((item = gridLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    int size = widgets.getSize();
    int rows = (size/4)+1;
    int k = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 4; j++) {
            if (k < size) {
                gridLayout->addWidget(widgets[k], i, j, 1, 1);
                k++;
            }
            else break;
        }
    }
    gridLayout->setRowStretch(rows, 1);
}

void ItemsView::removeWidget(int i) {
    widgets.erase(widgets[i]);
}

// slots

void ItemsView::createWidgets(SearchWidget* sw) {
    widgets.clear();
    visitorItems v(parent);
    for(int i = 0; i < sw->resultsNumber(); i++) {
        sw->getItem(i)->accept(v);
        QWidget* w = v.getWidget();
        widgets.insert(w);
    }

    this->addWidgets();
    this->showWidgets();
    return;
}
