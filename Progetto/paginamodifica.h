#ifndef PAGINAMODIFICA_H
#define PAGINAMODIFICA_H


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
#include <QMessageBox>

#include "cardgame.h"
#include "virtualgame.h"
#include "physicalgame.h"
#include "itemwidget.h"
#include "negozio.h"
#include "modello.h"


class paginamodifica: public QWidget
{
    Q_OBJECT
private:
    //campo oggetto
    itemBase * oggModifica;
    negozio * pNegL;
    modello * pMod;
    QWidget * pCont;
    //per item base
    QLabel * nomeUnoI;
    QLabel * casaProdUnoI;
    QLineEdit * nomeDueI;
    QLineEdit * casaProdDueI;
    QLineEdit * prezzoBaseI;
    //lista da visualizzare
    //itemWidget * listaI;
    //bootone cerca
    QPushButton * InsButton;//bottone inserimento
    //widget per virtuale fisico e carte
    QWidget * wvirtualgameI;//widget per interfaccia virtual game
    QWidget * wphysicalgameI;//widget per interfaccia virtual game
    QWidget * wcardgameI;//widget card game
    //radio button
    /*QGroupBox *contenitoreradioI;//contenitore per i radio button
    QRadioButton *rVideoVI;//creo tre puntatori a radio button
    QRadioButton *rVideoFI;
    QRadioButton *rCarteI;*/
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
    /*bool brVideovI = false;
    bool brVideofI = false;
    bool brCarteI = false;
    bool statoIns = false;*/
public slots:
    void pressioneInsInModifica();
public:
    //paginamodifica(QWidget * parent, itemBase * oggM);
    paginamodifica(negozio * cc, itemBase * oggM, modello * mm, QWidget * pc);
    QPushButton * getBottoneModifca() const;
    itemBase * getOggModificabile() const;
};

#endif // PAGINAMODIFICA_H
