#include "physicalgame.h"

//costruttore
physicalGame::physicalGame(string tit, string casa, double prezzo, string qualeCons="Inserisci per quale console è questa versione", string ediz="Inserisci edizione"): item(tit,casa,prezzo), qualeConsole(qualeCons), edizione(ediz){}

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
physicalGame::physicalGame(const physicalGame & phy): item(phy), qualeConsole(phy.getQualeConsole()), edizione(phy.getEdizione()) {}

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
