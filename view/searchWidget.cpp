#include "searchWidget.h"

#include "src/inventario.h"

SearchWidget::SearchWidget() : searchBar(new QLineEdit()), searchButton(new QPushButton("Cerca")),
                                results() {
    QHBoxLayout* layout = new QHBoxLayout(this);
    this->setLayout(layout);

    QSpacerItem* spacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Preferred);

    layout->addItem(spacer);
    layout->addWidget(searchBar);
    layout->addWidget(searchButton);
    layout->addItem(spacer);

    QShortcut *searchShortcut = new QShortcut(QKeySequence("Return"),this);

    connect(searchShortcut, &QShortcut::activated, searchButton, &QPushButton::click);
    connect(searchButton, &QPushButton::clicked, this, &SearchWidget::search);
}

Item* SearchWidget::getItem(int i) {
    return results[i];
}

int SearchWidget::resultsNumber() const {
    return results.getSize();
}

int SearchWidget::removeItem(Item* i) {
    int index = results.find(i);
    results.erase(i);
    return index;
}

// slots
void SearchWidget::search() {
    results.clear();
    std::string q = (searchBar->text()).toStdString();
    Inventario& i = Inventario::getInventario();
    results = i.search(q);

    emit giveResults(this);
}
