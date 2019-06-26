#ifndef NEGOZIO_H
#define NEGOZIO_H

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QListWidget>

#include <itemwidget.h>

class negozio: public QWidget
{
    Q_OBJECT
private:
   QPushButton * videogiochiv;
   QPushButton * videogiochif;
   QPushButton * carte;
   QPushButton * tutte;
   QPushButton * belimina;
   QPushButton * bmodifica;

   itemWidget * lista;

   //campi per i bottoni
   bool infoBottoneTutte = false;
   bool infoBottoneFisico = false;
   bool infoBottoneVirtuale = false;
   bool infoBottoneCarte = false;
   bool infoElimina = false;
   bool infoModifica = false;
   bool infoGeneraleNegozioTotale = false;

public slots:
   void bottoneTutte();
   void bottoneFisico();
   void bottoneVirtuale();
   void bottoneCarte();
   void pressioneLista();
   void bottoneElimina();

public:
    negozio(QWidget* parent);
    //bottone tutte
    bool getInfoBottoneTutte() const;
    QPushButton * getBottoneTutte() const;
    void setFalseBottoneTutte();
    void setTrueBottoneTutte();
    //bottone fisico
    bool getInfoBottoneFisico() const;
    QPushButton * getBottoneFisico() const;
    void setFalseBottoneFisico();
    void setTrueBottoneFisico();
    //bottone virtuale
    bool getInfoBottoneVirtuale() const;
    QPushButton * getBottoneVirtuale() const;
    void setFalseBottoneVirtuale();
    void setTrueBottoneVirtuale();
    //bottone fisico
    bool getInfoBottoneCarte() const;
    QPushButton * getBottoneCarte() const;
    void setFalseBottoneCarte();
    void setTrueBottoneCarte();
    //bottone elimina
    bool getInfoBottoneElimina() const;
    QPushButton * getBottoneElimina() const;
    void setFalseBottoneElimina();
    //bottone elimina
    bool getInfoBottoneModifica() const;
    QPushButton * getBottoneModifica() const;
    void setFalseBottoneModifica();
    //bottone info generale negozio totale
    bool getInfoBottoneGeneraleNeg() const;

    //return della mia lista di item widget
    itemWidget* getLista() const;
};

#endif // NEGOZIO_H
