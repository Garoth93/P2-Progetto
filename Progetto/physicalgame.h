#ifndef PHYSICALGAME_H
#define PHYSICALGAME_H
#include "item.h"

class physicalGame : public item
{
    private:
        string qualeConsole;
        string edizione;
    public:
        physicalGame (string, string, double, string, string);//costruttore
        physicalGame (const physicalGame &);//costruttore di copia
        double calcolaPrezzo () const;//metedo calcola prezzo virtuale
        string getQualeConsole () const;//get
        string getEdizione () const;//get
};

#endif // PHYSICALGAME_H