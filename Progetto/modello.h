#ifndef MODELLO_H
#define MODELLO_H

#include <cardgame.h>
#include <physicalgame.h>
#include <virtualgame.h>
#include <contenitore.h>


class modello
{
private:
    Contenitore<itemBase *>* lista;
    std::string Path;
    bool datiSalvati;//controllo per vedere se ci sono i dati salvati
public:
    modello(std::string = ":/Salvataggio dati");
    ~modello();

    //void salvataggio(); //Salvataggio dei dati
    void caricamento(); //Caricamento dei dati
    void setNuovoPercorso(std::string);
    void salvataggio();

    Contenitore<itemBase*>::Iterator mbegin();//return iteratore begin
    Contenitore<itemBase*>::Iterator mend();//return itaratore end
    Contenitore<itemBase*>::Constiterator mcbegin() const;
    Contenitore<itemBase*>::Constiterator mcend() const;

    Contenitore<itemBase*>* getlista() const;//return di puntatore al mio contenitore

    //rimozione
    //getlista

};

#endif // MODELLO_H
