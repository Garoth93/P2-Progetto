#include "item.h"

//costruttore item
itemBase::itemBase (string tit, string casa, double prezzoB): titolo(tit), casaProduttrice(casa), prezzoBase(prezzoB) {}

//costruttore di copia
itemBase::itemBase (const itemBase & ite): titolo(ite.getTitolo()), casaProduttrice(ite.getCasaProdruttrice()), prezzoBase(ite.getPrezzoBase()) {}

//getTiolo
string itemBase::getTitolo() const
{
    return titolo;
}

//getCasaProduttrice
string itemBase::getCasaProdruttrice() const
{
    return casaProduttrice;
}

//getPrezzoBase
double itemBase::getPrezzoBase() const
{
    return prezzoBase;
}

//set titolo
void itemBase::setTitolo(string s)
{
    titolo=s;
}

//set casa produttrice
void itemBase::setCasaProduttrice(string s)
{
    casaProduttrice=s;
}

//set prezzo base
void itemBase::setPrezzoBase(double d)
{
    prezzoBase=d;
}

//operator ==
bool itemBase::operator==(const itemBase& i) const
{
    return ( titolo==i.titolo || titolo=="" || i.titolo=="") &&
           ( casaProduttrice==i.casaProduttrice || casaProduttrice=="" || i.casaProduttrice=="" ) &&
           ( prezzoBase==i.prezzoBase || prezzoBase==0 || i.prezzoBase==0 );
}

//operator !=
bool itemBase::operator!=(const itemBase& i) const
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

//metodo per estrappolare i dati e metterli in stringa
std::string itemBase::infoItem() {
    std::string str = "";
    return str.append("\n").append("Tipologia prodotto: " + getTipo())
            .append("\nTitolo: " + getTitolo())
            .append("\nCasaProduttrice: " + getCasaProdruttrice());
}

//operator <<
std::ostream& operator<<(std::ostream& os, const itemBase& ite)
{
    return os<< "Titolo: " << ite.getTitolo() << "\nProdotto da: " << ite.getCasaProdruttrice();
}
