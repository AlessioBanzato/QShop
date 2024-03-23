#ifndef ABS_CONST_VISITOR_H
#define ABS_CONST_VISITOR_H

class Album;
class Book;
class Movie;

class absConstVisitor {
public:
    virtual void visit(const Album&) =0;
    virtual void visit(const Book&) =0;
    virtual void visit(const Movie&) =0;
};

#endif // ABS_VISITOR_ITEMS_H
