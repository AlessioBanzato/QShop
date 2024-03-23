#ifndef VISITORJSON_H
#define VISITORJSON_H

#include "absConstVisitor.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

#include "src/item.h"

class visitorJson : public absConstVisitor {
    QJsonObject obj;
public:
    visitorJson();
    virtual void visit(const Album&) override;
    virtual void visit(const Book&) override;
    virtual void visit(const Movie&) override;
    void addItemFields(const Item&);
    QJsonObject& getObject();
};

#endif // VISITORJSON_H
