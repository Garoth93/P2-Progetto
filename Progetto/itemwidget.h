#ifndef ITEMWIDGET_H
#define ITEMWIDGET_H

#include <QListWidget>
#include <QScrollBar>

#include "listaditem.h"
#include "physicalgame.h"
#include "cardgame.h"
#include "virtualgame.h"


class itemWidget: public QListWidget
{
    Q_OBJECT
private:
    QWidget* parent;
public:
    itemWidget(QWidget* = NULL);
    void aggiungiItem(itemBase *);//aggiungere un item passando il puntatore di quell oggetto
    //listaditem* itemCorrente() const;//da aggiungere item corrente
};

#endif // ITEMWIDGET_H
