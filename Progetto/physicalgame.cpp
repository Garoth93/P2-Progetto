#include "physicalgame.h"


//costruttore
physicalGame::physicalGame(string tit="inserisci il titolo", string casa="inserisci la casa", double prezzo=0, string qualeCons="Inserisci per quale console è questa versione", string ediz="Inserisci edizione"): itemBase(tit,casa,prezzo), qualeConsole(qualeCons), edizione(ediz){}

//getQualeconsole
string physicalGame::getQualeConsole()const
{
    return qualeConsole;
}
//getedizione
string physicalGame::getEdizione()const
{
    return edizione;
}
//costrtuttore di copia
physicalGame::physicalGame(const physicalGame & phy): itemBase(phy), qualeConsole(phy.getQualeConsole()), edizione(phy.getEdizione()) {}


//calcola prezzo virtuale
double physicalGame::calcolaPrezzo()const
{
    if( qualeConsole=="ps4" || qualeConsole=="playstation4" )
        return getPrezzoBase() + 30;
    if( qualeConsole=="ps3" || qualeConsole=="playstation3" )
        return getPrezzoBase() + 5;
    if( qualeConsole=="nintendo switch" )
        return getPrezzoBase() + 20;
    if( qualeConsole=="xbox one" )
        return getPrezzoBase() + 30;
    if( qualeConsole=="xbox 360" )
        return getPrezzoBase() + 10;
    if( qualeConsole=="nintendo 3ds" )
        return getPrezzoBase() + 15;
    return getPrezzoBase();
}

//get tipo virtuale
string physicalGame::getTipo() const
{
    return "physicalgame";
}

//metodi di set
void physicalGame::setConsole(string s){
    qualeConsole=s;
}

void physicalGame::setEdizione(string s){
    edizione=s;
}

//operator==
bool physicalGame::operator==(const itemBase& i) const
{
    const physicalGame *ph = dynamic_cast<const physicalGame*>(&i);
    return ph && itemBase::operator==(i) &&
           ( getQualeConsole() == ph->getQualeConsole() || getQualeConsole()=="" || ph->getQualeConsole()=="" ) &&
           ( getEdizione() == ph->getEdizione() || getEdizione()=="" || ph->getEdizione()=="" );
}

//operator!=
bool physicalGame::operator!=(const itemBase& i) const
{
    const physicalGame *ph = dynamic_cast<const physicalGame*>(&i);
    if(!ph)
        return true;
    bool ret = false;
    if( itemBase::operator!=(i) )
    {
        return true;
    }
    if( getQualeConsole()=="" || ph->getQualeConsole()=="" )
    {
        ret = true;
    }
    if(!ret && getQualeConsole()!=ph->getQualeConsole()  )
    {
        return true;
    }else{
        ret = false;
    }
    if( getEdizione()=="" || ph->getEdizione()=="" )
    {
        ret = true;
    }
    if(!ret && getEdizione()!=ph->getEdizione()  )
    {
        return true;
    }else{
        return false;
    }
}

//metodo virtuale per prendere i dati
std::string physicalGame::infoItem() {
    std::string og = itemBase::infoItem();
        return og.append("\n").append("Console: " + getQualeConsole())
                .append("\nEdizione: " + getEdizione())
                .append("\nPrezzo: " + (QString::number(calcolaPrezzo()).toUtf8()) );//uso libreria QT può dare problemi con i compilatori windows il to string
}


//operator <<
std::ostream& operator<<(std::ostream& os, const physicalGame& phy)
{
    return operator<<(os, static_cast<const itemBase&>(phy)) << "\nConsole: " << phy.getQualeConsole() << "\nEdizione: "<< phy.getEdizione() << "\nPrezzo: " << phy.calcolaPrezzo();
}
