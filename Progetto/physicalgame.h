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
        string getTipo() const;//metodo virtuale gettipo
        string getQualeConsole () const;//get console
        string getEdizione () const;//get edizione

        bool operator==(const item&) const;//operator==
        bool operator!=(const item&) const;//operator!=

        //altri metodi
        virtual string infoItem();//const?
};

std::ostream& operator<<(std::ostream&, const physicalGame&);//operator << esterno alla classe

#endif // PHYSICALGAME_H
