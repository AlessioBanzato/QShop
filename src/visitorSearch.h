#ifndef VISITOR_SEARCH_H
#define VISITOR_SEARCH_H

#include "absConstVisitor.h"
#include "src/album.h"
#include "src/book.h"
#include "src/movie.h"

#include <string>
#include <algorithm>

class visitorSearch : public absConstVisitor {
private:
    std::string str;
    bool presenza;
public:
    visitorSearch(std::string&);
    virtual void visit(const Album&);
    virtual void visit(const Book&);
    virtual void visit(const Movie&);
    bool getPresenza() const;
    std::string strToLower(std::string);
};

#endif
