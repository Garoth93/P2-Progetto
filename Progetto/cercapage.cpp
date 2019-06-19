#include "cercapage.h"

cercapage::cercapage(QWidget* parent):
    QWidget(parent),
    nomeUno(new QLabel("Nome",this)),
    casaProdUno(new QLabel("Casa produttrice",this)),
    nomeDue(new QLineEdit(this)),
    casaProdDue(new QLineEdit(this)),
    cercabutton(new QPushButton("Cerca",this)),
    contenitoreradio(new QGroupBox(tr("Scegli l'oggetto"),this)),
    rVideoV(new QRadioButton(tr("Videogioco virtuale"),this)),
    rVideoF(new QRadioButton(tr("Videogioco fisico"),this)),
    rCarte(new QRadioButton(tr("Gioco di carte"),this))

{
    QGridLayout * mainl = new QGridLayout;//layout come matrices
    mainl->addWidget(nomeUno,0,0,1,1);
    mainl->addWidget(casaProdUno,1,0,1,1);
    mainl->addWidget(nomeDue,0,1,1,1);
    mainl->addWidget(casaProdDue,1,1,1,1);

    QVBoxLayout *vbox = new QVBoxLayout;//creo vbox per contenere i radio button
    rVideoV->setChecked(true);//imposto radio button predefinito
    vbox->addWidget(rVideoV);
    vbox->addWidget(rVideoF);
    vbox->addWidget(rCarte);
    vbox->addStretch(1);
    contenitoreradio->setLayout(vbox);
    contenitoreradio->setFixedHeight(110);
    mainl->addWidget(contenitoreradio,2,0,1,1);

    mainl->addWidget(cercabutton,3,0,1,1);

    connect(rVideoV,SIGNAL(clicked()),this,SLOT(radiobuttonslot()));
    connect(rVideoF,SIGNAL(clicked()),this,SLOT(radiobuttonslot()));
    connect(rCarte,SIGNAL(clicked()),this,SLOT(radiobuttonslot()));

    setLayout(mainl);
}

void cercapage::radiobuttonslot() {
        QRadioButton* srb = qobject_cast<QRadioButton*>(sender());
        std::string name = srb->text().toStdString();
        if(name=="Videogioco virtuale"){
        }
}

