#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "Book.h"
#include "Clothing.h"
#include "Movie.h"
#include <vector>
#include <map>
#include <set>


class MyDataStore : public DataStore{
public:
    //~MyDataStore();

    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream& ofile);
    
    std::vector<Product*> myProducts;
    std::vector<User*> myUsersVect;
    std::map<std::string, User*> myUsers;
    
    std::map<std::string, std::set<Product*>> keyWordsMap;


};

#endif
