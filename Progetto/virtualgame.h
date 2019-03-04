#ifndef VIRTUALGAME_H
#define VIRTUALGAME_H


class virtualGame  : public item
{
    private:
        string piattaForma;
        bool seasonPass;
    public:
        virtualGame (string, string, double, string, bool);//costruttore
        string getPiattaForma () const;
        bool gerSeasonPass () const;
        virtualGame (const virtualGame &);//costrtuttore di copia
        double calcolaPrezzo () const;
};

#endif // VIRTUALGAME_H
