#include "virtualgame.h"

//costrtuttore
virtualGame::virtualGame(string tit="inserisci il titolo", string casa="inserisci la casa", double prezzo=0, string piatt="inserisci una piattaforma", bool pass=0): itemBase(tit,casa,prezzo), piattaForma(piatt), seasonPass(pass) {}

//getPiattaforma
string virtualGame::getPiattaForma() const
{
    return piattaForma;
}

//getSeasonpass
bool virtualGame::getSeasonPass() const
{
    return seasonPass;
}

//costrtuttore di copia
virtualGame::virtualGame(const virtualGame & vir): itemBase(vir), piattaForma(vir.getPiattaForma()), seasonPass(vir.seasonPass) {}

//calcola prezzo virtuale
double virtualGame::calcolaPrezzo() const
{
    if( piattaForma=="steam" )
    {
        if( seasonPass )
            return getPrezzoBase() + 15 + 20;
        return getPrezzoBase() + 15;
    }
    if( piattaForma=="origin" )
    {
        if( seasonPass )
            return getPrezzoBase() + 30 + 40;
        return getPrezzoBase() + 30;
    }
    if( piattaForma=="uplay" )
    {
        if( seasonPass )
            return getPrezzoBase() + 25 + 30;
        return getPrezzoBase() + 25;
    }
    if( piattaForma=="epic games" || piattaForma=="epicgames" )
    {
        if( seasonPass )
            return getPrezzoBase() + 20 + 25;
        return getPrezzoBase() + 20;
    }
    return getPrezzoBase();
}

//get tipo virtuale
string virtualGame::getTipo() const
{
    return "virtualgame";
}

//set piatta forma
void virtualGame::setPiattaForma(string s)
{
    piattaForma=s;
}

//set season pass
void virtualGame::setSeasonPass(bool b)
{
    seasonPass=b;
}

//operator==
bool virtualGame::operator==(const itemBase& i) const
{
    const virtualGame *vi = dynamic_cast<const virtualGame*>(&i);
    return vi && itemBase::operator==(i) &&
           ( getPiattaForma() == vi->getPiattaForma() || getPiattaForma()=="" || vi->getPiattaForma()=="" ) &&
           ( getSeasonPass() == vi->getSeasonPass() || getSeasonPass() || vi->getSeasonPass() );
}

//operator!=
bool virtualGame::operator!=(const itemBase& i) const
{
    const virtualGame *vi = dynamic_cast<const virtualGame*>(&i);
    if(!vi)
        return true;
    bool ret = false;
    if( itemBase::operator!=(i) )
    {
        return true;
    }
    if( getPiattaForma()=="" || vi->getPiattaForma()=="" )
    {
        ret = true;
    }
    if(!ret && getPiattaForma() != vi->getPiattaForma()  )
    {
        return true;
    }else{
        ret = false;
    }
    if( getSeasonPass() || vi->getSeasonPass() )
    {
        ret = true;
    }
    if(!ret && getSeasonPass() != vi->getSeasonPass()  )
    {
        return true;
    }else{
        return false;
    }
    /*return !vi && item::operator!=(i) ||
           ( getPiattaForma() != vi->getPiattaForma() ) ||
           ( getSeasonPass() != vi->getSeasonPass() );*/
}

//metodo virtuale per prendere i dati
std::string virtualGame::infoItem() {
    std::string og = itemBase::infoItem();
        return og.append("\n").append("Piattaforma: " + getPiattaForma())
                .append("\nSeason Pass: ").append(getSeasonPass() ? "Si" : "No")
                .append("\nPrezzo: " + (QString::number(calcolaPrezzo()).toUtf8()) );//uso libreria QT può dare problemi con i compilatori windows il to string
}


//operator <<
std::ostream& operator<<(std::ostream& os, const virtualGame& phy)
{
    return operator<<(os, static_cast<const itemBase&>(phy)) << "\nPiattaforma: " << phy.getPiattaForma() << "\nSeason pass: "<< (phy.getSeasonPass()? "Si":"No") << "\nPrezzo: " << phy.calcolaPrezzo();
}
