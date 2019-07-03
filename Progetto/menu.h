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
    QAction *salvaDati;
    QAction *esciDalProgramma;
public:
    menu(QWidget *parent = nullptr);
    QAction * getSalva()const;
    QAction * getEsci()const;
};

#endif // MENU_H
