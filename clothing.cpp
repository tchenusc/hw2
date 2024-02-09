#include "clothing.h"
#include <iomanip>
#include <sstream>

using namespace std;


Clothing::Clothing(const string name, double price, int qty, string size, string brand) :
    Product("clothing", name, price, qty)
{
    size_ = size;
    brand_ = brand;
}

set<string> Clothing::keywords() const
{
    set<string> keywordsFromBrand = parseStringToWords(brand_);
    set<string> keywordsFromName = parseStringToWords(name_);
    
    return setUnion(keywordsFromBrand, keywordsFromName);
}

string Clothing::displayString() const
{
    string ret = "";
    
    ret += name_;
    ret += "\nSize: ";
    ret += size_;
    ret += " Brand: ";
    ret += brand_;
    ret += "\n";
    
    stringstream stream;
    stream << fixed << setprecision(2) << price_;
    string priceAsString = stream.str();
    ret += priceAsString;
    ret += " ";
    ret += to_string(qty_);
    ret += " left.\n";
    
    return ret;
}

void Clothing::dump(ostream& os) const
{
    Product::dump(os);
    os << size_ << "\n";
    os << brand_ << "\n";
}
