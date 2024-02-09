#include "Movie.h"
#include "util.h"
#include <iomanip>
#include <sstream>

using namespace std;


Movie::Movie(const string name, double price, int qty, string genre, string rating) :
    Product("movie", name, price, qty)
{
    genre_ = genre;
    rating_ = rating;
}

set<string> Movie::keywords() const
{
    set<string> keywordsFromName = parseStringToWords(name_);
    keywordsFromName.insert(convToLower(genre_));
    
    return keywordsFromName;
}

string Movie::displayString() const
{
    string ret = "";
    
    ret += name_;
    ret += "\nGenre: ";
    ret += genre_;
    ret += " Rating: ";
    ret += rating_;
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

void Movie::dump(ostream& os) const
{
    Product::dump(os);
    os << genre_ << "\n";
    os << rating_ << "\n";
}
