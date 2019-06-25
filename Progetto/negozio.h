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

   itemWidget * lista;

   //campi per i bottoni
   bool infoBottoneTutte = false;
   bool infoBottoneFisico = false;
   bool infoBottoneVirtuale = false;
   bool infoBottoneCarte = false;

public slots:
   void bottoneTutte();
   void bottoneFisico();
   void bottoneVirtuale();
   void bottoneCarte();

public:
    negozio(QWidget* parent);
    //bottone tutte
    bool getInfoBottoneTutte() const;
    QPushButton * getBottoneTutte() const;
    void setFalseBottoneTutte();
    //bottone fisico
    bool getInfoBottoneFisico() const;
    QPushButton * getBottoneFisico() const;
    void setFalseBottoneFisico();
    //bottone virtuale
    bool getInfoBottoneVirtuale() const;
    QPushButton * getBottoneVirtuale() const;
    void setFalseBottoneVirtuale();
    //bottone fisico
    bool getInfoBottoneCarte() const;
    QPushButton * getBottoneCarte() const;
    void setFalseBottoneCarte();

    //return della mia lista di item widget
    itemWidget* getLista() const;
};

#endif // NEGOZIO_H
