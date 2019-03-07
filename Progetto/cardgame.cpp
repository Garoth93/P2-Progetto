#include "cardgame.h"

//costrtuttore
cardGame::cardGame(string tit="inserisci il titolo", string casa="inserisci la casa", double prezzo=0, string espa="inserisci espansione", bool edi=0, int numc=11, bool deck=0): item(tit,casa,prezzo), espansione(espa),  primaEdizione(edi), numeroCarte(numc) ,starterDeck(deck) {}

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
    if( primaEdizione )
    {
        if( starterDeck )
            return getPrezzoBase() + 5 + 5;
        if( numeroCarte > 10)
            return getPrezzoBase() + 4;
        else
            return getPrezzoBase() + 3;
    }
    if( !primaEdizione )
    {
        if( starterDeck )
            return getPrezzoBase() + 5;
        if( numeroCarte > 10)
            return getPrezzoBase() + 2;
        else
            return getPrezzoBase() + 1;
    }
    return getPrezzoBase();
}

//operator==
bool cardGame::operator==(const item& i) const
{
    const cardGame *ca = dynamic_cast<const cardGame*>(&i);
    return ca && item::operator==(i) &&
           ( getEspansione() == ca->getEspansione() || getEspansione()=="" ) &&
           ( getPrimaEdizione() == ca->getPrimaEdizione() || getPrimaEdizione() ) &&
           ( getNumeroCarte() == ca->getNumeroCarte() || getNumeroCarte()==0 ) &&
           ( getStarterDeck() == ca->getStarterDeck() || getStarterDeck() );
}

std::ostream& operator<<(std::ostream& os, const cardGame& phy) {
    return operator<<(os, static_cast<const item&>(phy)) << "\nEspansione: " << phy.getEspansione() << "\nPrima edizione: "<< (phy.getPrimaEdizione()? "Si":"No") << "\nNumero di carte presenti: " << phy.getNumeroCarte() << "\nStarter Deck: "<< (phy.getStarterDeck()? "Si":"No") << "\nPrezzo: " << phy.calcolaPrezzo();
}
