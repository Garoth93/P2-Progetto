#ifndef VIRTUALGAME_H
#define VIRTUALGAME_H
#include "item.h"

class virtualGame  : public item
{
    private:
        string piattaForma;
        bool seasonPass;
    public:
        virtualGame (string, string, double, string, bool);//costruttore
        string getPiattaForma() const;//get piattaforma
        bool getSeasonPass() const;//get season pass
        virtualGame (const virtualGame &);//costrtuttore di copia
        double calcolaPrezzo() const;//metodo virtuale calcola prezzo

        bool operator==(const item&) const;//operator==
};

//operator << esterno
std::ostream& operator<<(std::ostream& , const virtualGame& );

#endif // VIRTUALGAME_H
