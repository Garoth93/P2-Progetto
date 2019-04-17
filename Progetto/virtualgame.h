#ifndef VIRTUALGAME_H
#define VIRTUALGAME_H
#include "item.h"

class virtualGame  : public item
{
    private:
        string piattaForma;
        bool seasonPass;
    public:
        //costrtuttori
        virtualGame (string, string, double, string, bool);//costruttore
        virtualGame (const virtualGame &);//costrtuttore di copia

        //metodi di get
        bool getSeasonPass() const;//get season pass
        string getPiattaForma() const;//get piattaforma

        //metodi di set
        void setPiattaForma(string);
        void setSeasonPass(bool);

        double calcolaPrezzo() const;//metodo virtuale calcola prezzo
        string getTipo() const;//metodo virtuale gettipo

        //operator
        bool operator==(const item&) const;//operator==
        bool operator!=(const item&) const;//operator!=
};

//operator
std::ostream& operator<<(std::ostream& , const virtualGame& );//operator << esterno

#endif // VIRTUALGAME_H
