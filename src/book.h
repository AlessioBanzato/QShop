#ifndef BOOK_H
#define BOOK_H

#include "item.h"

class Book : public Item {
private:
  std::string tipo, editore;
public:
  Book(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, unsigned int, int, double, int);
  const std::string& getTipo() const;
  const std::string& getEditore() const;
  void setTipo(const std::string&);
  void setEditore(const std::string&);
  virtual ~Book() =default;

  virtual void accept(absConstVisitor&) const override;
  virtual void accept(absVisitor&) override;
};

std::ostream& operator<<(std::ostream&, const Book&);

#endif
