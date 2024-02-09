#include "mydatastore.h"

using namespace std;

/*
MyDataStore::~MyDataStore()
{
    for (unsigned int i = 0; i < myProducts.size(); i++)
    {
        delete myProducts[i];
        i--;
    }
    
    for (unsigned int i = 0; i < myUsersVect.size(); i++)
    {
        delete myUsersVect[i];
        i--;
    }
}
 */


void MyDataStore::addProduct(Product* p)
{
    myProducts.push_back(p);
    
    set<string> keyWords = p->keywords();
    
    set<string>::iterator it;
    for (it = keyWords.begin(); it != keyWords.end(); it++)
    {
        if (keyWordsMap.find(*it) != keyWordsMap.end()) // Already exists
        {
            keyWordsMap.find(*it)->second.insert(p);
        }
        else    // Does not exist, then create new pair and add to map
        {
            set<Product*> temp;
            temp.insert(p);
            keyWordsMap.insert(make_pair(*it, temp));
        }
    }
}

void MyDataStore::addUser(User* u)
{
    myUsersVect.push_back(u);
    myUsers.insert(make_pair(u->getName(), u));
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
    vector<Product*> ret;
    bool firstAssignment = true;
    set<Product*> retAsSet;
    for (unsigned int i = 0; i < terms.size(); i++)
    {
        if (keyWordsMap.find(terms[i]) != keyWordsMap.end() && firstAssignment)
        {
            firstAssignment = false;
            retAsSet = keyWordsMap.find(terms[i])->second;
            continue;
        }
        if (keyWordsMap.find(terms[i]) != keyWordsMap.end())
        {
            set<Product*> hits = keyWordsMap.find(terms[i])->second;
            if (type == 0) retAsSet = setIntersection(retAsSet, hits);
            if (type == 1) retAsSet = setUnion(retAsSet, hits);
        }
    }
    
    set<Product*>::iterator it;
    for (it = retAsSet.begin(); it != retAsSet.end(); it++)
    {
        ret.push_back(*it);
    }
    return ret;
}

void MyDataStore::dump(ostream& ofile)
{
    ofile << "<products>\n";
    for (unsigned int i = 0; i < myProducts.size(); i++)
    {
        myProducts[i]->dump(ofile);
    }
    ofile << "</products>\n";
    
    ofile << "<users>\n";
    map<string, User*>::iterator it;
    for (it = myUsers.begin(); it != myUsers.end(); it++)
    {
        it->second->dump(ofile);
    }
    ofile << "</users>\n";
}
