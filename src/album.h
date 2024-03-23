#ifndef ALBUM_H
#define ALBUM_H

#include "item.h"

class Album : public Item {
private:
  std::string record_label;
public:
  Album(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, unsigned int, int, double, int);
  const std::string& getLabel() const;
  void setLabel(const std::string&);
  virtual ~Album() =default;

  virtual void accept(absConstVisitor&) const override;
  virtual void accept(absVisitor&) override;
};

std::ostream& operator<<(std::ostream& os, const Album& a);

#endif
