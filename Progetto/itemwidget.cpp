#include "itemwidget.h"

//costrtuttore
itemWidget::itemWidget(QWidget* p) :
    parent(p)
{
    addScrollBarWidget(new QScrollBar(parent),Qt::AlignRight);
}

void itemWidget::aggiungiItem(itemBase * gioco){
    listaditem* oggetto = new listaditem(parent, gioco);
    addItem(oggetto);
}

//oggetto corrente nella lista
listaditem * itemWidget::itemCorrente() const{
    return static_cast<listaditem*>(QListWidget::currentItem());
}

