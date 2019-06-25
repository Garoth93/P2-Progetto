#ifndef CARDGAME_H
#define CARDGAME_H
#include "item.h"

class cardGame : public itemBase
{
    private:
        string espansione;
        bool primaEdizione;
        int numeroCarte;
        bool starterDeck;
    public:
        cardGame (string, string, double, string, bool, int, bool);//costrtuttore
        cardGame (const cardGame &);//costrtuttore di copia
        string getEspansione () const;//getespansione
        bool getPrimaEdizione () const;//getprimaed
        int getNumeroCarte () const;//getnumerocarte
        bool getStarterDeck () const;//getstarter
        double calcolaPrezzo () const;//metodo virtuale
        string getTipo() const;//metodo virtuale

        bool operator==(const itemBase&) const;//operator==
        bool operator!=(const itemBase&) const;//operator==

        //metodo virtuale per prendere i dati
        virtual string infoItem();//const?
};

std::ostream& operator<<(std::ostream& , const cardGame& );//operator << esterno

#endif // CARDGAME_H
