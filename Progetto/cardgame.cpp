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

//get tipo virtuale
string cardGame::getTipo() const
{
    return "cardgame";
}

//operator==
bool cardGame::operator==(const item& i) const
{
    const cardGame *ca = dynamic_cast<const cardGame*>(&i);
    return ca && item::operator==(i) &&
           ( getEspansione() == ca->getEspansione() || getEspansione()=="" || ca->getEspansione()=="" ) &&
           ( getPrimaEdizione() == ca->getPrimaEdizione() || getPrimaEdizione() || ca->getPrimaEdizione() ) &&
           ( getNumeroCarte() == ca->getNumeroCarte() || getNumeroCarte()==0 || ca->getNumeroCarte()==0 ) &&
           ( getStarterDeck() == ca->getStarterDeck() || getStarterDeck() || ca->getStarterDeck() );
}

//operator!=
bool cardGame::operator!=(const item& i) const
{
    const cardGame *ca = dynamic_cast<const cardGame*>(&i);
    if(!ca)
        return true;
    bool ret = false;
    if( item::operator!=(i) )
    {
        return true;
    }
    if( getEspansione()=="" || ca->getEspansione()=="" )
    {
        ret = true;
    }
    if(!ret && getEspansione()!=ca->getEspansione()  )
    {
        return true;
    }else{
        ret = false;
    }
    if( getPrimaEdizione() || ca->getPrimaEdizione() )
    {
        ret = true;
    }
    if(!ret && getPrimaEdizione() != ca->getPrimaEdizione()  )
    {
        return true;
    }else{
        ret = false;
    }
    if( getNumeroCarte()==0 || ca->getNumeroCarte()==0 )
    {
        ret = true;
    }
    if(!ret && getNumeroCarte() != ca->getNumeroCarte()  )
    {
        return true;
    }else{
        ret = false;
    }
    if( getStarterDeck() || ca->getStarterDeck() )
    {
        ret = true;
    }
    if(!ret && getStarterDeck() != ca->getStarterDeck()  )
    {
        return true;
    }else{
        return false;
    }
    /*return !ca || item::operator!=(i) ||
           ( getEspansione() != ca->getEspansione() ) ||
           ( getPrimaEdizione() != ca->getPrimaEdizione() ) ||
           ( getNumeroCarte() != ca->getNumeroCarte() ) ||
           ( getStarterDeck() != ca->getStarterDeck() );*/
}

//metodo virtuale per prendere i dati
std::string cardGame::infoItem() {
    std::string og = item::infoItem();
        return og.append("\n").append("Espansione: " + getEspansione())
                .append("\nPrima edizione: ").append(getPrimaEdizione() ? "Si" : "No")
                //.append("\nNumero carte: " + std::to_string(getNumeroCarte()))
                .append("\nStarter deck: ").append(getStarterDeck() ? "Si" : "No");
                //.append("\nPrezzo: " + std::to_string(calcolaPrezzo()));
}

//operator <<
std::ostream& operator<<(std::ostream& os, const cardGame& phy) {
    return operator<<(os, static_cast<const item&>(phy)) << "\nEspansione: " << phy.getEspansione() << "\nPrima edizione: "<< (phy.getPrimaEdizione()? "Si":"No") << "\nNumero di carte presenti: " << phy.getNumeroCarte() << "\nStarter Deck: "<< (phy.getStarterDeck()? "Si":"No") << "\nPrezzo: " << phy.calcolaPrezzo();
}
