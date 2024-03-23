#ifndef VISITORITEMS_H
#define VISITORITEMS_H

#include "absConstVisitor.h"

#include "src/album.h"
#include "src/book.h"
#include "src/movie.h"

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>

class visitorItems : public absConstVisitor {
private:
    QWidget* itemWidget, *parent;
public:
    visitorItems(QWidget*);
    virtual void visit(const Album&) override;
    virtual void visit(const Book&) override;
    virtual void visit(const Movie&) override;

    QWidget* createButton(const Item&);
    QWidget* getParent() const;
    QWidget* getWidget() const;
};

#endif // VISITORITEMS_H
