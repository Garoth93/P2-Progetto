#ifndef PHYSICALGAME_H
#define PHYSICALGAME_H
#include "item.h"

class physicalGame : public itemBase
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
        //metodi di set
        void setConsole(string);
        void setEdizione(string);

        bool operator==(const itemBase&) const;//operator==
        bool operator!=(const itemBase&) const;//operator!=

        //altri metodi
        virtual string infoItem();//const?
};

std::ostream& operator<<(std::ostream&, const physicalGame&);//operator << esterno alla classe

#endif // PHYSICALGAME_H
