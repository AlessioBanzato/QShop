#include "visitorItems.h"

#include "mainWindow.h"

#include <QPushButton>
#include <QObject>
#include <QSignalMapper>

visitorItems::visitorItems(QWidget* p) : itemWidget(), parent(p) {}

void visitorItems::visit(const Album& a) {
    itemWidget = new QWidget();

    QVBoxLayout* layout = new QVBoxLayout();
    itemWidget->setLayout(layout);

    QLabel* coverLabel = new QLabel();
    QPixmap* cover = new QPixmap(QString::fromStdString(a.getImagePath()));
    *cover = cover->scaled(200, 200, Qt::KeepAspectRatio);
    coverLabel->setPixmap(*cover);

    layout->addWidget(coverLabel, 0, Qt::AlignCenter);

    QLabel* title = new QLabel("<b>Titolo:</b> "+QString::fromStdString(a.getTitolo()));
    layout->addWidget(title);

    QLabel* author = new QLabel("<b>Autore:</b> "+QString::fromStdString(a.getAutore()));
    layout->addWidget(author);

    QLabel* genre = new QLabel("<b>Genere:</b> "+QString::fromStdString(a.getGenere()));
    layout->addWidget(genre);

    QLabel* label = new QLabel("<b>Etichetta:</b> "+QString::fromStdString(a.getLabel()));
    layout->addWidget(label);

    QWidget* button = createButton(a);

    layout->addWidget(button);

    itemWidget->setFixedSize(300,400);
}

void visitorItems::visit(const Book& b) {
    itemWidget = new QWidget();

    QHBoxLayout* layout = new QHBoxLayout();
    itemWidget->setLayout(layout);

    QLabel* coverLabel = new QLabel();
    QPixmap* cover = new QPixmap(QString::fromStdString(b.getImagePath()));
    *cover = cover->scaled(150, 250, Qt::KeepAspectRatio);
    coverLabel->setPixmap(*cover);

    layout->addWidget(coverLabel);

    QLabel* info = new QLabel();
    layout->addWidget(info, Qt::AlignLeft);

    QVBoxLayout* infoLayout = new QVBoxLayout();
    info->setLayout(infoLayout);

    QSpacerItem* fromTop = new QSpacerItem(0,70);
    QSpacerItem* fromEnd = new QSpacerItem(0,68);

    infoLayout->addSpacerItem(fromTop);

    QLabel* title = new QLabel("<b>Titolo:</b> "+QString::fromStdString(b.getTitolo()));
    title->setWordWrap(true);
    infoLayout->addWidget(title);

    QLabel* author = new QLabel("<b>Autore:</b> "+QString::fromStdString(b.getAutore()));
    author->setWordWrap(true);
    infoLayout->addWidget(author);

    QLabel* type = new QLabel("<b>Tipo:</b> "+QString::fromStdString(b.getTipo()));
    type->setWordWrap(true);
    infoLayout->addWidget(type);

    QLabel* genre = new QLabel("<b>Genere:</b> "+QString::fromStdString(b.getGenere()));
    genre->setWordWrap(true);
    infoLayout->addWidget(genre);

    QLabel* editor = new QLabel("<b>Editore:</b> "+QString::fromStdString(b.getEditore()));
    editor->setWordWrap(true);
    infoLayout->addWidget(editor);

    QWidget* button(createButton(b));
    infoLayout->addWidget(button);

    infoLayout->addSpacerItem(fromEnd);

    itemWidget->setFixedSize(300,400);
}

void visitorItems::visit(const Movie& m) {
    itemWidget = new QWidget();

    QHBoxLayout* layout = new QHBoxLayout();
    itemWidget->setLayout(layout);

    QLabel* coverLabel = new QLabel();
    QPixmap* cover = new QPixmap(QString::fromStdString(m.getImagePath()));
    *cover = cover->scaled(150, 250, Qt::KeepAspectRatio);
    coverLabel->setPixmap(*cover);

    layout->addWidget(coverLabel);

    QLabel* info = new QLabel();
    layout->addWidget(info, Qt::AlignLeft);

    QVBoxLayout* infoLayout = new QVBoxLayout();
    info->setLayout(infoLayout);

    QSpacerItem* fromTop = new QSpacerItem(0,52);
    QSpacerItem* fromEnd = new QSpacerItem(0,68);

    infoLayout->addSpacerItem(fromTop);

    QLabel* title = new QLabel("<b>Titolo:</b> "+QString::fromStdString(m.getTitolo()));
    title->setWordWrap(true);
    infoLayout->addWidget(title);

    QLabel* author = new QLabel("<b>Regista:</b> "+QString::fromStdString(m.getAutore()));
    author->setWordWrap(true);
    infoLayout->addWidget(author);

    QLabel* genre = new QLabel("<b>Genere:</b> "+QString::fromStdString(m.getGenere()));
    genre->setWordWrap(true);
    infoLayout->addWidget(genre);

    QLabel* length = new QLabel("<b>Durata:</b> "+QString::number(m.getLength())+"'");
    infoLayout->addWidget(length);

    QWidget* button(createButton(m));
    infoLayout->addWidget(button);

    infoLayout->addSpacerItem(fromEnd);

    itemWidget->setFixedSize(300,400);
}

QWidget* visitorItems::createButton(const Item& item) {
    QWidget* tmp = new QWidget();
    QHBoxLayout* buttonsLayout = new QHBoxLayout(tmp);

    QPushButton* edit = new QPushButton();
    buttonsLayout->addWidget(edit);

    QPushButton* remove = new QPushButton();
    buttonsLayout->addWidget(remove);


    QSignalMapper* editMapper = new QSignalMapper(parent);

    QObject::connect(edit, SIGNAL(clicked()), editMapper, SLOT(map()));
    editMapper->setMapping(edit, item.getCodice());

    QObject::connect(editMapper, SIGNAL(mappedInt(int)), parent, SLOT(modificaOggetto(int)));


    QSignalMapper* removeMapper = new QSignalMapper(parent);

    QObject::connect(remove, SIGNAL(clicked()), removeMapper, SLOT(map()));
    removeMapper->setMapping(remove, item.getCodice());

    QObject::connect(removeMapper, SIGNAL(mappedInt(int)), parent, SLOT(confermaRimozione(int)));


    QIcon editIcon;
    editIcon.addFile("./images/icons/edit.png");

    edit->setIcon(editIcon);
    edit->setIconSize(QSize(32,32));

    QIcon binIcon;
    binIcon.addFile("./images/icons/bin.png");

    remove->setIcon(binIcon);
    remove->setIconSize(QSize(32,32));

    return tmp;
}

QWidget* visitorItems::getParent() const {
    return parent;
}

QWidget* visitorItems::getWidget() const {
    return itemWidget;
}
