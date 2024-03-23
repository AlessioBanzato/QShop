#ifndef MOVIE_H
#define MOVIE_H

#include "item.h"

class Movie : public Item {
private:
  unsigned int length; // minuti
public:
  Movie(unsigned int, const std::string&, const std::string&, const std::string&, const std::string&, unsigned int, int, double, int);
  unsigned int getLength() const;
  void setLength(unsigned int);
  virtual ~Movie() =default;

  virtual void accept(absConstVisitor&) const override;
  virtual void accept(absVisitor&) override;
};

std::ostream& operator<<(std::ostream& os, const Movie& m);


#endif
