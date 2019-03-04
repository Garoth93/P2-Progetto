#include "virtualgame.h"

//costrtuttore
virtualGame::virtualGame(string tit, string casa, double prezzo, string piatt="inserisci una piattaforma", bool pass=0): item(tit,casa,prezzo), piattaForma(piatt), seasonPass(pass) {}

//getPiattaforma
string virtualGame::getPiattaForma () const
{
    return piattaForma;
}

//getSeasonpass
bool virtualGame::gerSeasonPass () const
{
    return seasonPass;
}

//costrtuttore di copia
virtualGame::virtualGame(const virtualGame & vir): item(vir), piattaForma(vir.getPiattaForma()), seasonPass(vir.seasonPass) {}

//calcola prezzo virtuale
double virtualGame::calcolaPrezzo() const
{

}
