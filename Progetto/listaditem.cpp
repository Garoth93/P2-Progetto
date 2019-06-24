#include "listaditem.h"

//costrtuttore
listaditem::listaditem(QWidget* p , item* ogg):
    parent(p),
    oggetto(ogg)
{
    update();
}

//serve per ritornare il mio oggetto presente in questo widget
item* listaditem::prelevaItem() const{
    return oggetto;
}

void listaditem::update() {
    //codise per inserire un immagine
    /*QString path = QString::fromStdString(oggetto->getPath());
    QPixmap p(path);
    setIcon(p.scaled(500,600,Qt::AspectRatioMode::KeepAspectRatio)); //Per l'immagine*/

    /*puntatore al mio oggetto nella gerarchia,
     * prendo i dati attraverso la mio infoitem presente nella mia gerarchia.
     * Questa prende i dati e returna una stringa
     * con i dati presenti all'interno del mio oggetto*/
    setText(QString::fromStdString(oggetto->infoItem()));
}

