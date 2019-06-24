#ifndef LISTADITEM_H
#define LISTADITEM_H

#include<QListWidgetItem>

#include "physicalgame.h"
#include "cardgame.h"
#include "virtualgame.h"


class listaditem : public QListWidgetItem
{
private:
    QWidget* parent;//puntatore a qwidget che sarà il mio widget per inserire i dati
    item* oggetto;//puntatore polimorfo al mio oggetto
public:
    listaditem(QWidget*, item* = NULL);//costrtuttore
    item* prelevaItem() const;//serve per prendere il mio item da inserire poi
    void update();
};

#endif // LISTADITEM_H
