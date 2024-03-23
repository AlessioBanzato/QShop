#ifndef ABSVISITOR_H
#define ABSVISITOR_H

class Album;
class Book;
class Movie;

class absVisitor {
public:
    virtual void visit(Album&) =0;
    virtual void visit(Book&) =0;
    virtual void visit(Movie&) =0;
};

#endif // ABSVISITOR_H
