#ifndef BOOK_H
#define BOOK_H


#include "product.h"
#include "util.h"

class Book : public Product {
public:
    Book(const std::string name, double price, int qty, std::string ISBN, std::string author);
    
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;
    
private:
    std::string ISBN_;
    std::string author_;
    
};
#endif
