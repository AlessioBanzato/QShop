#ifndef VISITOREDIT_H
#define VISITOREDIT_H

#include "absVisitor.h"

#include "view/itemEditor.h"

class visitorEdit : public absVisitor {
private:
    ItemEditor* editor;
public:
    virtual void visit(Album&) override;
    virtual void visit(Book&) override;
    virtual void visit(Movie&) override;

    ItemEditor* getEditor() const;
};

#endif // EDITITEM_H
