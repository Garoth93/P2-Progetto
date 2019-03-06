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
        string getPiattaForma () const;
        bool getSeasonPass () const;
        virtualGame (const virtualGame &);//costrtuttore di copia
        double calcolaPrezzo () const;
};

std::ostream& operator<<(std::ostream& , const virtualGame& );

#endif // VIRTUALGAME_H
