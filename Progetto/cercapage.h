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

class cercapage: public QWidget
{
    Q_OBJECT
private:
    //per item base
    QLabel * nomeUno;
    QLabel * casaProdUno;
    QLineEdit * nomeDue;
    QLineEdit * casaProdDue;
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
public slots://creo slot per signal
    void radiobuttonslot();
public:
    //creo un metodo che guarda tutti i checkbox per con is cecked e nel mentre mi cambia le variabili
    cercapage(QWidget* parent);
};

#endif // CERCAPAGE_H
