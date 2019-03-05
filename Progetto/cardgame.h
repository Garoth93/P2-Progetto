#ifndef CARDGAME_H
#define CARDGAME_H
#include "item.h"

class cardGame : public item
{
    private:
        string espansione;
        bool primaEdizione;
        int numeroCarte;
        bool starterDeck;
    public:
        cardGame (string, string, double, string, bool, int, bool);//costrtuttore
        cardGame (const cardGame &);//costrtuttore di copia
        string getEspansione () const;
        bool getPrimaEdizione () const;
        int getNumeroCarte () const;
        bool getStarterDeck () const;
        double calcolaPrezzo () const;
};

#endif // CARDGAME_H
