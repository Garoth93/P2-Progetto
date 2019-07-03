#include "listaditem.h"

//costrtuttore
listaditem::listaditem(QWidget* p , itemBase* ogg):
    parent(p),
    oggetto(ogg)
{
    update();
}

//serve per ritornare il mio oggetto presente in questo widget
itemBase* listaditem::prelevaItem() const{
    return oggetto;
}

void listaditem::update() {
    setText(QString::fromStdString(oggetto->infoItem()));
}

