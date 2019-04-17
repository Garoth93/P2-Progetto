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

//set titolo
void item::setTitolo(string s)
{
    titolo=s;
}

//set casa produttrice
void item::setCasaProduttrice(string s)
{
    casaProduttrice=s;
}

//set prezzo base
void item::setPrezzoBase(double d)
{
    prezzoBase=d;
}

//operator ==
bool item::operator==(const item& i) const
{
    return ( titolo==i.titolo || titolo=="" || i.titolo=="") &&
           ( casaProduttrice==i.casaProduttrice || casaProduttrice=="" || i.casaProduttrice=="" ) &&
           ( prezzoBase==i.prezzoBase || prezzoBase==0 || i.prezzoBase==0 );
}

//operator !=
bool item::operator!=(const item& i) const
{
    bool ret = false;
    if(titolo=="" || i.titolo=="")
    {
        ret = true;
    }
    if(!ret && titolo!=i.titolo )
    {
        return true;
    }else{
        ret = false;
    }
    if(casaProduttrice=="" || i.casaProduttrice=="")
    {
        ret = true;
    }
    if(!ret && casaProduttrice!=i.casaProduttrice )
    {
        return true;
    }else{
        ret = false;
    }
    if(prezzoBase==0 || i.prezzoBase==0)
    {
        ret = true;
    }
    if(!ret && prezzoBase!=i.prezzoBase )
    {
        return true;
    }else{
        return false;
    }

    /*return ( titolo!=i.titolo) ||
           ( casaProduttrice!=i.casaProduttrice ) ||
           ( prezzoBase!=i.prezzoBase);*/
}

//operator <<
std::ostream& operator<<(std::ostream& os, const item& ite)
{
    return os<< "Titolo: " << ite.getTitolo() << "\nProdotto da: " << ite.getCasaProdruttrice();
}
