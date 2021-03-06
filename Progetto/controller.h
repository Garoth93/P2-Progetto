#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <menu.h>
#include <negozio.h>
#include <cercapage.h>
#include <modello.h>
#include <paginainserimento.h>
#include <paginamodifica.h>

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
    paginainserimento * pagins;
    QTabWidget * tab;
    cercapage * cercapagina;
public slots:
    //carica i dati nel negozio
    void caricaDatiNegozio();
    void avviaRicercaOgg();
    void avviaIns();
    void eliminaOggetto();
    void pressioneSalva();
    void chiudiProgramma();
    void pressioneModifica();
public:
    controller(QWidget * parent= nullptr);
};

#endif // CONTROLLER_H
