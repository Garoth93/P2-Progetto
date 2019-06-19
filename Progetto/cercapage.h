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

class cercapage: public QWidget
{
    Q_OBJECT
private:
    QLabel * nomeUno;
    QLabel * casaProdUno;
    QLineEdit * nomeDue;
    QLineEdit * casaProdDue;
    QPushButton * cercabutton;//bottone cerca

    //radio button
    QGroupBox *contenitoreradio;//contenitore per i radio button
    QRadioButton *rVideoV;//creo tre puntatori a radio button
    QRadioButton *rVideoF;
    QRadioButton *rCarte;
public slots://creo slot per signal
    void radiobuttonslot();
public:
    cercapage(QWidget* parent);
};

#endif // CERCAPAGE_H
