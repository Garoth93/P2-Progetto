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
        item (string, string, double);//costruttore
        item (const item &);//costruttore di copia
        virtual ~item() = default;//distruttore virtuale
        virtual double calcolaPrezzo() const = 0; //metodo virtuale per calcolare il prezzo
        string getTitolo() const;//metodo get per il titolo
        string getCasaProdruttrice() const;//metodo get per la casa produttrice
        double getPrezzoBase() const;//metodo get per il prezzo base

        virtual bool operator==(const item&) const;//operator==
        //virtual bool operator!=(const item&) const;//operator!=
};

std::ostream& operator<<(std::ostream& , const item& );//operator << esterno alla classe

#endif // ITEM_H
