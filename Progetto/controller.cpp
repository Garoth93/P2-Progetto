#include "controller.h"

controller::controller(QWidget *parent):
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    mymenu(new menu(this)),
    negl(new negozio(this)),
    tab(new QTabWidget(this)),
    cercapagina(new cercapage(this)),
    model(new modello()),//prova per model sistemare
    file(QFileDialog::getOpenFileName(this, tr("Scegli FIle"), "Progetto/SalvataggioDati", "File XML(*.xml)"))//prova per model sistemare
{
    layoutPrincipale->setMenuBar(mymenu);
    tab->setTabPosition(QTabWidget::South);//posiozione del "menù" tab
    tab->addTab(negl,"Negozio");//aggiungo alla tab il mio Qwidget ricorda vuole
    tab->addTab(cercapagina,"Ricerca");
    layoutPrincipale->addWidget(tab);//aggingo la mia tab all layout principale

    //prova di inserimento e visualizzazione tramite cout modificato
    /*
    model->setNuovoPercorso(file.toStdString());
    model->caricamento();
    Contenitore<item*>::Iterator it = (model->mbegin());
    std::cout << *(*it);
    ++it;
    std::cout << *(*it);*/


    setLayout(layoutPrincipale);
}

