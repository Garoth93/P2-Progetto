#include "item.h"

//costruttore item
item::item (string tit, string casa, double prezzoB): titolo(tit), casaProduttrice(casa), prezzoBase(prezzoB) {}

//costruttore di copia
item::item (const item & ite): titolo(ite.getTitolo()), casaProduttrice(ite.getCasaProdruttrice()), prezzoBase(ite.getPrezzoBase()) {}

//getTiolo
string item::getTitolo() const
{
    return titolo;
}

//getCasaProduttrice
string item::getCasaProdruttrice() const
{
    return casaProduttrice;
}

//getPrezzoBase
double item::getPrezzoBase() const
{
    return prezzoBase;
}

//operator ==
bool item::operator==(const item& i) const
{
    return ( titolo==i.titolo || titolo=="" ) &&
           ( casaProduttrice==i.casaProduttrice || casaProduttrice=="" ) &&
           ( prezzoBase==i.prezzoBase || prezzoBase==0 );
}

//operator <<
std::ostream& operator<<(std::ostream& os, const item& ite)
{
    return os<< "Titolo: " << ite.getTitolo() << "\nProdotto da: " << ite.getCasaProdruttrice();
}
