#ifndef CONTENITORE_H
#define CONTENITORE_H
#include <iostream>

template <class T>
class Contenitore
{
    private:
        class nodo
        {
            public:
                T info;//Campo dati all' interno del mio nodo
                nodo * prev;//puntatore al nodo precedente
                nodo * next;//puntatore al nodo sucessivo
                nodo(const T &, nodo *pr, nodo *ne);
                ~nodo();

        };
        nodo * first;//puntatore primo nodo
        nodo * last;//puntatore ultimo nodo
    public:
        void PushBegin(const T &);
        void PushEnd(const T &);
};

//Costruttore nodo inline def
Contenitore::nodo::nodo(const T & t, nodo * pr = 0, nodo * ne = 0): info(t), prev(pr), next(ne) {}

//Distruttore di nodo ridefinito
Contenitore::nodo::~nodo()
{
    if(next)
    {
        delete next;
    }
}

//Push begin inserisce, inserimento a inzio lista.
Contenitore::PushBegin(const T & info)
{
    first = new nodo(info, nullptr, first);
    if (last == nullptr)
    {
        last = first;
    }
    else
    {
        (first->next)->prev = first;
    }
}

//Push end, inserimento a fine lista.
Contenitore::PushEnd(const T & info)
{
    last = new nodo(info, last, nullptr);
    if (first == nullptr)
    {
        first = last;
    }
    else
    {
        (last->prev)->next = last;
    }
}


#endif // CONTENITORE_H
