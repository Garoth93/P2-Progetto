#include "cardgame.h"

//costrtuttore
cardGame::cardGame(string tit, string casa, double prezzo, string espa="inserisci espansione", bool edi=0, int numc=11, bool deck=0): item(tit,casa,prezzo), espansione(espa),  primaEdizione(edi), numeroCarte(numc) ,starterDeck(deck) {}

//getEspansione
string cardGame::getEspansione() const
{
    return espansione;
}

//getEdizione
bool cardGame::getPrimaEdizione() const
{
    return primaEdizione;
}

//Getnumerocarte
int cardGame::getNumeroCarte() const
{
    return numeroCarte;
}

//getStarter
bool cardGame::getStarterDeck() const
{
    return starterDeck;
}

//costrtuttore di copia
cardGame::cardGame(const cardGame & card): item(card), espansione(card.getEspansione()), primaEdizione(card.getPrimaEdizione()), numeroCarte(card.getNumeroCarte()), starterDeck(card.getStarterDeck()) {}

//calcola prezzo virtuale
double cardGame::calcolaPrezzo() const
{

}
