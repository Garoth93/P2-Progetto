#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <menu.h>
#include <negozio.h>
#include <cercapage.h>
#include <modello.h>

#include <QWidget>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QTabWidget>//libreira per le tab



class controller : public QWidget
{
    Q_OBJECT
private:
    modello * model;//prova per model sistemare
    QString file;//prova per model sistemare

    QVBoxLayout *layoutPrincipale;
    menu * mymenu;
    negozio * negl;
    QTabWidget * tab;
    cercapage * cercapagina;
public:
    controller(QWidget * parent= NULL);
};

#endif // CONTROLLER_H