#include "Book.h"
#include <sstream>
#include <iomanip>

using namespace std;


Book::Book(const string name, double price, int qty, string ISBN, string author) :
    Product("book", name, price, qty)
{
    ISBN_ = ISBN;
    author_ = author;
}

set<string> Book::keywords() const
{
    set<string> keywordsFromAuthor = parseStringToWords(author_);
    keywordsFromAuthor.insert(ISBN_);
    set<string> keywordsFromName = parseStringToWords(name_);
    
    return setUnion(keywordsFromName, keywordsFromAuthor);
}

string Book::displayString() const
{
    //cout << "Test: " << getPrice() << endl;
    //cout << endl;
    string ret = "";
    
    ret += name_;
    ret += "\nAuthor: ";
    ret += author_;
    ret += " ISBN: ";
    ret += ISBN_;
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

void Book::dump(ostream& os) const
{
    Product::dump(os);
    os << ISBN_ << "\n";
    os << author_ << "\n";
}
