#ifndef ITEM_H
#define ITEM_H
#include <string.h>
#include <iostream>

using std::string;

class item
{
    private:
        string titolo;
        string casaProduttrice;
        double prezzoBase;
    public:
        item(string, string, double);//costruttore
        item(const item &);//costruttore di copia
        virtual ~item () = default;//distruttore virtuale
};

#endif // ITEM_H
