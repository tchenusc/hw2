#ifndef CLOTHING_H
#define CLOTHING_H


#include "product.h"
#include "util.h"

class Clothing : public Product {
public:
    Clothing(const std::string name, double price, int qty, std::string size, std::string brand);
    
    virtual std::set<std::string> keywords() const;
    virtual std::string displayString() const;
    virtual void dump(std::ostream& os) const;
    
private:
    std::string size_;
    std::string brand_;
    
};
#endif
