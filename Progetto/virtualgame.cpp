#include "virtualgame.h"

//costrtuttore
virtualGame::virtualGame(string tit="inserisci il titolo", string casa="inserisci la casa", double prezzo=0, string piatt="inserisci una piattaforma", bool pass=0): item(tit,casa,prezzo), piattaForma(piatt), seasonPass(pass) {}

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
virtualGame::virtualGame(const virtualGame & vir): item(vir), piattaForma(vir.getPiattaForma()), seasonPass(vir.seasonPass) {}

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
bool virtualGame::operator==(const item& i) const
{
    const virtualGame *vi = dynamic_cast<const virtualGame*>(&i);
    return vi && item::operator==(i) &&
           ( getPiattaForma() == vi->getPiattaForma() || getPiattaForma()=="" ) &&
           ( getSeasonPass() == vi->getSeasonPass() || getSeasonPass() );
}

//operator <<
std::ostream& operator<<(std::ostream& os, const virtualGame& phy)
{
    return operator<<(os, static_cast<const item&>(phy)) << "\nPiattaforma: " << phy.getPiattaForma() << "\nSeason pass: "<< (phy.getSeasonPass()? "Si":"No") << "\nPrezzo: " << phy.calcolaPrezzo();
}
