#ifndef ITEM_H
#define ITEM_H
#include <string.h>
#include <iostream>

#include <QString>

using std::string;

class itemBase
{
    private:
        string titolo;
        string casaProduttrice;
        double prezzoBase;
    public:
        //costrtuttori
        itemBase (string, string, double);//costruttore
        itemBase (const itemBase &);//costruttore di copia
        virtual ~itemBase() = default;//distruttore virtuale

        virtual double calcolaPrezzo() const = 0; //metodo virtuale per calcolare il prezzo
        virtual string getTipo() const =0;//metodo virtuale per il sottotipo

        //metodi di get
        string getTitolo() const;//metodo get per il titolo
        string getCasaProdruttrice() const;//metodo get per la casa produttrice
        double getPrezzoBase() const;//metodo get per il prezzo base

        //metodi di set
        void setTitolo(string);//set titolo
        void setCasaProduttrice(string);//set casa
        void setPrezzoBase(double);//set prezzo base

        //operator
        virtual bool operator==(const itemBase&) const;//operator==
        virtual bool operator!=(const itemBase&) const;//operator!=

        //metodo per estrappolare i dati e metterli in stringa
        virtual string infoItem();//const?
};

std::ostream& operator<<(std::ostream& , const itemBase& );//operator << esterno alla classe

#endif // ITEM_H
