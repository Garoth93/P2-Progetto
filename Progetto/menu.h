#ifndef MENU_H
#define MENU_H

#include <qmenubar.h>
#include <qwidget.h>
#include <QAction>
#include <QFileDialog>
#include <QLineEdit>



class menu: public QMenuBar
{
    Q_OBJECT
private:
    QWidget* parent;
    QAction *negozio;
    QAction *ricerca;
    QAction *inserisci;
public:
    menu(QWidget *parent = NULL);
};

#endif // MENU_H
