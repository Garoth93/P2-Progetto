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
                nodo(const T &, nodo * =nullptr, nodo * =nullptr);
                //~nodo();

        };
        //---FINE NODO--

        //CAMPI DATO CONTENITORE
        nodo * first;//puntatore primo nodo
        nodo * last;//puntatore ultimo nodo

    //PUBLIC CLASSE CONTENITORE
    public:
        void PushBegin(const T &);
        void PushEnd(const T &);
        Contenitore(nodo * =nullptr, nodo* =nullptr);

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
            Iterator &operator--();
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
        void erasenoi(Iterator);
        //erase return un iteratore rif costante
};

//---NODO---
//Costruttore nodo inline def
template <typename T>
Contenitore<T>::nodo::nodo(const T & t, nodo * pr, nodo * ne): info(t), prev(pr), next(ne) {}

//Distruttore di nodo ridefinito
/*template <typename T>
Contenitore<T>::nodo::~nodo()
{
    if(next)
    {
        delete next;
    }
}*/

//---CONTENITORE---
//Costruttore
template <typename T>
Contenitore<T>::Contenitore(nodo * f, nodo * l): first(f), last(l) {}

//Push begin inserisce, inserimento a inzio lista.
template <typename T>
void Contenitore<T>::PushBegin(const T & t)
{
    first = new nodo(t, nullptr, first);
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
template <typename T>
void Contenitore<T>::PushEnd(const T & t)
{
    last = new nodo(t, last, nullptr);
    if (first == nullptr)
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
    if(first == nullptr)
        return Constiterator(nullptr);
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
    if(first == nullptr)
        return Iterator(nullptr);
    return Iterator(last + 1, true);
}

//---CONSTITERATOR---
//costrtuttore constiterator
template< typename T>
Contenitore<T>::Constiterator::Constiterator(nodo * p, bool b) : pt(p), pte(b) {}

//costrtuttore constiterator
template< typename T>
Contenitore<T>::Constiterator::Constiterator() : pt(nullptr), pte(false) {}

//operatore ++
template< typename T>
typename Contenitore<T>::Constiterator& Contenitore<T>::Constiterator::operator ++()
{
    if (!pte && pt)
    {
        if (pt->next == nullptr)
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
Contenitore<T>::Iterator::Iterator() : pt(nullptr), pte(false) {}

//operatore ++
template< typename T>
typename Contenitore<T>::Iterator& Contenitore<T>::Iterator::operator ++()
{
    if (!pte && pt)
    {
        if (pt->next == nullptr)
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

//CONTENITORE
//erasae Iterator
template<typename T>
typename Contenitore<T>::Iterator Contenitore<T>::erase(Iterator it)
{
    Iterator rit;
    if( (!(it.pt)->prev) && (!(it.pt)->next))//se è unico nodo presente nella lista
    {
        first=nullptr;
        last=nullptr;
        rit.pt=nullptr;
        rit.pte=true;
        return rit;
    }
    if(!(it.pt)->next)//caso se è l'ultimo nodo presente nella lista
    {
        rit=(it.pt)->prev;
    }
    if( (it.pt)->prev )//caso se esiste il nodo precendente
        ((it.pt)->prev)->next=(it.pt)->next;
    else{//se non esiste aggioranre primo nodo dentro al contenitore
        if((it.pt)->next){
            first=(it.pt)->next;
        }else{
            first=nullptr;
        }
    }
    if( (it.pt)->next )//caso se esiste il nodo sucessivo
        ((it.pt)->next)->prev=(it.pt)->prev;
    else//se non esiste aggiornare ultimo nodo presente dentro il contenitore
    {
        last=(rit.pt);
        return rit;
    }
    ++it;//incremento iteratore
    return it;
}

//erasaenoi Iterator
template<typename T>
void Contenitore<T>::erasenoi(Iterator it)
{
    if( (!(it.pt)->prev) && (!(it.pt)->next))//se è unico nodo presente nella lista
    {
        first=nullptr;
        last=nullptr;
    }else{

        if(!(it.pt)->next)//caso se è l'ultimo nodo presente nella lista
        {
            last=(it.pt)->prev;
        }
        if(!(it.pt)->prev)//caso se è il primo nodo presente nella lista
        {
            first=(it.pt)->next;
        }
        if( (it.pt)->prev ){//caso se esiste il nodo precendente
            ((it.pt)->prev)->next=(it.pt)->next;
        }
       if( (it.pt)->next ){//caso se esiste il nodo sucessivo
            ((it.pt)->next)->prev=(it.pt)->prev;
        }
    }
    (it.pt)->next=nullptr;
    (it.pt)->prev=nullptr;
    delete (it.pt);
}
#endif // CONTENITORE_H
