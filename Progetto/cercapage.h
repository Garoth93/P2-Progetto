#ifndef CERCAPAGE_H
#define CERCAPAGE_H

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QListWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QRadioButton>
#include <QGroupBox>
#include <QCheckBox>

#include "cardgame.h"
#include "virtualgame.h"
#include "physicalgame.h"
#include "itemwidget.h"

class cercapage: public QWidget
{
    Q_OBJECT
private:
    //per item base
    QLabel * nomeUno;
    QLabel * casaProdUno;
    QLineEdit * nomeDue;
    QLineEdit * casaProdDue;
    //lista da visualizzare
    itemWidget * lista;
    //bootone cerca
    QPushButton * cercabutton;//bottone cerca
    //widget per virtuale fisico e carte
    QWidget * wvirtualgame;//widget per interfaccia virtual game
    QWidget * wphysicalgame;//widget per interfaccia virtual game
    QWidget * wcardgame;//widget card game
    //radio button
    QGroupBox *contenitoreradio;//contenitore per i radio button
    QRadioButton *rVideoV;//creo tre puntatori a radio button
    QRadioButton *rVideoF;
    QRadioButton *rCarte;
    //checkbox
    QCheckBox * seasonpassv;//checkbox per gioco virtuale
    QCheckBox * primaedc;
    QCheckBox * starterdeckc;
    //gioco virtuale
    QLineEdit * lipiattaformav;//line edit per inseriemtno piattaforma
    //gioco fisico
    QLineEdit * liconsolephy;
    QLineEdit * liedizionephy;
    //gioco di carte
    QLineEdit * liespansione;
    QLineEdit * linumerocarte;

    //bool per radiobutton
    bool brVideov = false;
    bool brVideof = false;
    bool brCarte = false;
    bool statoRicerca = false;
public slots://creo slot per signal
    void radiobuttonslot();
    void pressTastoRicerca();
public:
    //creo un metodo che guarda tutti i checkbox per con is cecked e nel mentre mi cambia le variabili
    cercapage(QWidget* parent);
    //creo oggetto per la ricerca
    itemBase * creazioneOggRicerca();
    //info per lo stato e bottone ricerca
    bool infoStatoRicerca() const;
    QPushButton * getBottoneRicerca() const;
    //per lista
    itemWidget * getLista() const;
};

#endif // CERCAPAGE_H
