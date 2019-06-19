#ifndef NEGOZIO_H
#define NEGOZIO_H

#include <QPushButton>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QListWidget>

class negozio: public QWidget
{
    Q_OBJECT
private:
   QPushButton * videogiochiv;
   QPushButton * videogiochif;
   QPushButton * carte;
   /*QHBoxLayout * mainl;
   QVBoxLayout * buttonl;
   QListWidget * vislist;*/

public:
    negozio(QWidget* parent);
};

#endif // NEGOZIO_H
