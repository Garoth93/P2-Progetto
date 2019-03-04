#include "physicalgame.h"

//costruttore
physicalGame::physicalGame(string tit, string casa, double prezzo, string qualeCons="Inserisci per quale console è questa versione", string ediz="Inserisci edizione"): item(tit,casa,prezzo), qualeconsole(qualeCons), edizione(ediz){}

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
double physicalGame::calcolaPrezzo () const
{

}
