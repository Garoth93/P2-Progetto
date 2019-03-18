#ifndef CONTENITORE_H
#define CONTENITORE_H
#include <iostream>

template <class T>
class Contenitore
{
    private:
        //---CLASSE NODO---
        class nodo
        {
            public:
                T info;//Campo dati all' interno del mio nodo
                nodo * prev;//puntatore al nodo precedente
                nodo * next;//puntatore al nodo sucessivo
                nodo(const T &, nodo * =NULL, nodo * =NULL);
                ~nodo();

        };
        //---FINE NODO--

        nodo * first;//puntatore primo nodo
        nodo * last;//puntatore ultimo nodo

    //PUBLIC CLASSE CONTENITORE
    public:
        void PushBegin(const T &);
        void PushEnd(const T &);
        Contenitore(nodo * =NULL, nodo* =NULL);

    //---CONSTITERATOR
    class Constiterator
    {
        friend class Contenitore<T>;
        private:
            const nodo * pt;
            bool pte;//serve per pass the end.
            Constiterator(nodo *, bool =false);
        public:
            Constiterator();
            Constiterator &operator++();
            //operator ++(int)
            Constiterator &operator--();
            //operator --(int)
            const T &operator*() const;
            const T *operator->() const;
            bool operator==(const Constiterator &) const;
            bool operator!=(const Constiterator &) const;
    };
    //---FINE CONSTITERATOR

    //---ITERATOR
    class Iterator
    {
        friend class Contenitore<T>;
        private:
            nodo * pt;
            bool pte;
            Iterator(nodo *, bool=false);
        public:
            Iterator();
            Iterator &operator++();
            //do anche ++(int)
            Iterator &operator--();
            //do annche --(int)
            const T &operator*() const;
            const T *operator->() const;
            bool operator==(const Iterator &) const;
            bool operator!=(const Iterator &) const;
    };
    //---FINE ITITERATOR
        //METODI PUBBLICI CONTENITORE
        //METODI PER CONSTITERATOR
        Constiterator cbegin() const;
        Constiterator cend() const;
        //erase solo per non const iterator

        //METODI PER ITERATOR
        Iterator begin() const;
        Iterator end() const;
        Iterator erase(Iterator);
        //erase return un iteratore rif costante
};

//---NODO---
//Costruttore nodo inline def
template <typename T>
Contenitore<T>::nodo::nodo(const T & t, nodo * pr, nodo * ne): info(t), prev(pr), next(ne) {}

//Distruttore di nodo ridefinito
template <typename T>
Contenitore<T>::nodo::~nodo()
{
    if(next)
    {
        delete next;
    }
}

//---CONTENITORE---
//Costruttore
template <typename T>
Contenitore<T>::Contenitore(nodo * f, nodo * l): first(f), last(l) {}

//Push begin inserisce, inserimento a inzio lista.
template <typename T>
void Contenitore<T>::PushBegin(const T & t)
{
    first = new nodo(t, NULL, first);
    if (last == NULL)
    {
        last = first;
    }
    else
    {
        (first->next)->prev = first;
    }
}

//Push end, inserimento a fine lista.
template <typename T>
void Contenitore<T>::PushEnd(const T & t)
{
    last = new nodo(t, last, NULL);
    if (first == NULL)
    {
        first = last;
    }
    else
    {
        (last->prev)->next = last;
    }
}

//begin constiterator
template<typename T>
typename Contenitore<T>::Constiterator Contenitore<T>::cbegin() const
{
    return Constiterator(first);
}

//end constiterator
template<typename T>
typename Contenitore<T>::Constiterator Contenitore<T>::cend() const
{
    if(first == NULL)
        return Constiterator(NULL);
    return Constiterator(last + 1, true);
}

//begin iterator
template<typename T>
typename Contenitore<T>::Iterator Contenitore<T>::begin() const
{
    return Iterator(first);
}

//end iterator
template<typename T>
typename Contenitore<T>::Iterator Contenitore<T>::end() const
{
    if(first == NULL)
        return Iterator(NULL);
    return Iterator(last + 1, true);
}

//sistemare erase
//erasae Iterator
template<typename T>
typename Contenitore<T>::Iterator Contenitore<T>::erase(Iterator it)
{
    if( it.pt->prev )
        it.pt->prev->next=it.pt->next;
    if( it.pt->next )
        it.pt->next->prev=it.pt->prev;
    ++it;
    return it;
}

//---CONSTITERATOR---
//costrtuttore constiterator
template< typename T>
Contenitore<T>::Constiterator::Constiterator(nodo * p, bool b) : pt(p), pte(b) {}

//costrtuttore constiterator
template< typename T>
Contenitore<T>::Constiterator::Constiterator() : pt(NULL), pte(false) {}

//operatore ++
template< typename T>
typename Contenitore<T>::Constiterator& Contenitore<T>::Constiterator::operator ++()
{
    if (!pte && pt)
    {
        if (pt->next == NULL)
        {
            pt = pt + 1;
            pte = true;
        }
        else
            pt = pt->next;
    }
    return *this;
}

//operator --
template< typename T>
typename Contenitore<T>::Constiterator& Contenitore<T>::Constiterator::operator --()
{
    if (pte)
    {
        pt = pt - 1;
        pte = false;
    }
    else if (pt)
    {
        pt = pt->prev;
    }
    return *this;
}

//operator *
template< typename T>
const T & Contenitore<T>::Constiterator::operator *() const
{
    return pt->info;
}

//operator ->
template< typename T>
const T * Contenitore<T>::Constiterator::operator ->() const
{
    return &(pt->info);
}

//operator ==
template< typename T>
bool Contenitore<T>::Constiterator::operator ==(const Constiterator & x) const
{
    return pt == x.pt;
}

//operator !=
template< typename T>
bool Contenitore<T>::Constiterator::operator !=(const Constiterator & x) const
{
    return pt != x.pt;
}
//ITERATOR
//costrtuttore iterator
template< typename T>
Contenitore<T>::Iterator::Iterator(nodo * p, bool b) : pt(p), pte(b) {}

//costrtuttore iterator
template< typename T>
Contenitore<T>::Iterator::Iterator() : pt(NULL), pte(false) {}

//operatore ++
template< typename T>
typename Contenitore<T>::Iterator& Contenitore<T>::Iterator::operator ++()
{
    if (!pte && pt)
    {
        if (pt->next == NULL)
        {
            pt = pt + 1;
            pte = true;
        }
        else
            pt = pt->next;
    }
    return *this;
}

//operator --
template< typename T>
typename Contenitore<T>::Iterator& Contenitore<T>::Iterator::operator --()
{
    if (pte)
    {
        pt = pt - 1;
        pte = false;
    }
    else if (pt)
    {
        pt = pt->prev;
    }
    return *this;
}

//operator *
template< typename T>
const T & Contenitore<T>::Iterator::operator *() const
{
    return pt->info;
}

//operator ->
template< typename T>
const T * Contenitore<T>::Iterator::operator ->() const
{
    return &(pt->info);
}

//operator ==
template< typename T>
bool Contenitore<T>::Iterator::operator ==(const Iterator & x) const
{
    return pt == x.pt;
}

//operator !=
template< typename T>
bool Contenitore<T>::Iterator::operator !=(const Iterator & x) const
{
    return pt != x.pt;
}
#endif // CONTENITORE_H
