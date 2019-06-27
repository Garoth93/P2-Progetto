#ifndef PAGINAINSERIMENTO_H
#define PAGINAINSERIMENTO_H

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


class paginainserimento: public QWidget
{
    Q_OBJECT
private:
    //per item base
    QLabel * nomeUnoI;
    QLabel * casaProdUnoI;
    QLineEdit * nomeDueI;
    QLineEdit * casaProdDueI;
    //lista da visualizzare
    //itemWidget * listaI;
    //bootone cerca
    QPushButton * InsButton;//bottone inserimento
    //widget per virtuale fisico e carte
    QWidget * wvirtualgameI;//widget per interfaccia virtual game
    QWidget * wphysicalgameI;//widget per interfaccia virtual game
    QWidget * wcardgameI;//widget card game
    //radio button
    QGroupBox *contenitoreradioI;//contenitore per i radio button
    QRadioButton *rVideoVI;//creo tre puntatori a radio button
    QRadioButton *rVideoFI;
    QRadioButton *rCarteI;
    //checkbox
    QCheckBox * seasonpassvI;//checkbox per gioco virtuale
    QCheckBox * primaedcI;
    QCheckBox * starterdeckcI;
    //gioco virtuale
    QLineEdit * lipiattaformavI;//line edit per inseriemtno piattaforma
    //gioco fisico
    QLineEdit * liconsolephyI;
    QLineEdit * liedizionephyI;
    //gioco di carte
    QLineEdit * liespansioneI;
    QLineEdit * linumerocarteI;

    //bool per radiobutton
    bool brVideovI = false;
    bool brVideofI = false;
    bool brCarteI = false;
    bool statoIns = false;
public slots:
    void radiobuttonslotI();
    void pressTastoInserimento();
public:
    paginainserimento(QWidget* parent);
    //creo oggetto da ins
    itemBase * creazioneOggIns();
    //info per lo stato e bottone ins
    bool infoStatoIns() const;
    QPushButton * getBottoneInserimento() const;

};

#endif // PAGINAINSERIMENTO_H
