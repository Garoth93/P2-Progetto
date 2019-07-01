#include "cardgame.h"

//costrtuttore
cardGame::cardGame(string tit="inserisci il titolo", string casa="inserisci la casa", double prezzo=0, string espa="inserisci espansione", bool edi=0, int numc=11, bool deck=0): itemBase(tit,casa,prezzo), espansione(espa),  primaEdizione(edi), numeroCarte(numc) ,starterDeck(deck) {}

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

//metodi di set
void cardGame::setEspansione(string s){
    espansione = s;
}

void cardGame::setPrimaEd(bool b){
    primaEdizione = b;
}
void cardGame::setNumeroCarte(int n){
    numeroCarte = n;
}
void cardGame::setStarterDeck(bool b){
    starterDeck = b;
}

//costrtuttore di copia
cardGame::cardGame(const cardGame & card): itemBase(card), espansione(card.getEspansione()), primaEdizione(card.getPrimaEdizione()), numeroCarte(card.getNumeroCarte()), starterDeck(card.getStarterDeck()) {}

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
bool cardGame::operator==(const itemBase& i) const
{
    const cardGame *ca = dynamic_cast<const cardGame*>(&i);
    return ca && itemBase::operator==(i) &&
           ( getEspansione() == ca->getEspansione() || getEspansione()=="" || ca->getEspansione()=="" ) &&
           ( getPrimaEdizione() == ca->getPrimaEdizione() || getPrimaEdizione() || ca->getPrimaEdizione() ) &&
           ( getNumeroCarte() == ca->getNumeroCarte() || getNumeroCarte()==0 || ca->getNumeroCarte()==0 ) &&
           ( getStarterDeck() == ca->getStarterDeck() || getStarterDeck() || ca->getStarterDeck() );
}

//operator!=
bool cardGame::operator!=(const itemBase& i) const
{
    const cardGame *ca = dynamic_cast<const cardGame*>(&i);
    if(!ca)
        return true;
    bool ret = false;
    if( itemBase::operator!=(i) )
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
    std::string og = itemBase::infoItem();
        return og.append("\n").append("Espansione: " + getEspansione())
                .append("\nPrima edizione: ").append(getPrimaEdizione() ? "Si" : "No")
                .append("\nNumero carte: " + (QString::number(getNumeroCarte()).toUtf8()) )//uso libreria QT può dare problemi con i compilatori windows il to string
                .append("\nStarter deck: ").append(getStarterDeck() ? "Si" : "No")
                .append("\nPrezzo: " + (QString::number(calcolaPrezzo()).toUtf8()) );//uso libreria QT può dare problemi con i compilatori windows il to string
}

//operator <<
std::ostream& operator<<(std::ostream& os, const cardGame& phy) {
    return operator<<(os, static_cast<const itemBase&>(phy)) << "\nEspansione: " << phy.getEspansione() << "\nPrima edizione: "<< (phy.getPrimaEdizione()? "Si":"No") << "\nNumero di carte presenti: " << phy.getNumeroCarte() << "\nStarter Deck: "<< (phy.getStarterDeck()? "Si":"No") << "\nPrezzo: " << phy.calcolaPrezzo();
}
