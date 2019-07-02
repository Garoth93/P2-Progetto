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
#include <QCloseEvent>
#include <float.h>

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
    //bootone cerca
    QPushButton * InsButton;//bottone inserimento
    //widget per virtuale fisico e carte
    QWidget * wvirtualgameI;//widget per interfaccia virtual game
    QWidget * wphysicalgameI;//widget per interfaccia virtual game
    QWidget * wcardgameI;//widget card game
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
public slots:
    void pressioneInsInModifica();
public:
    //paginamodifica(QWidget * parent, itemBase * oggM);
    paginamodifica(negozio * cc, itemBase * oggM, modello * mm, QWidget * pc);
    QPushButton * getBottoneModifca() const;
    itemBase * getOggModificabile() const;
    //alla chiusura del widget
    void closeEvent(QCloseEvent *event) override;
    //refresh del mio negozio
    void refreshNeg() const;
    //try controllo
    bool is_number(const std::string& s) const;
};

#endif // PAGINAMODIFICA_H
