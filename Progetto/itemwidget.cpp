#include "itemwidget.h"

//costrtuttore
itemWidget::itemWidget(QWidget* p) :
    parent(p)
{
    //per inserire immagine
    //setIconSize(QSize(150,150));
    //addScrollBarWidget(new QScrollBar(Qt::Orientation::Vertical,parent), Qt::AlignRight);
    addScrollBarWidget(new QScrollBar(parent),Qt::AlignRight);
}

void itemWidget::aggiungiItem(itemBase * gioco){
    listaditem* oggetto = new listaditem(parent, gioco);
    addItem(oggetto);
}

