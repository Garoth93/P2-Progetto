#include "controller.h"

controller::controller(QWidget *parent):
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    mymenu(new menu(this)),
    negl(new negozio(this)),
    tab(new QTabWidget(this)),
    cercapagina(new cercapage(this))
{
    /*setFixedHeight(1000);
    setFixedWidth(1000);*/
    layoutPrincipale->setMenuBar(mymenu);
    tab->setTabPosition(QTabWidget::South);//posiozione del "menù" tab
    tab->addTab(negl,"Negozio");//aggiungo alla tab il mio Qwidget ricorda vuole
    tab->addTab(cercapagina,"Ricerca");
    layoutPrincipale->addWidget(tab);//aggingo la mia tab all layout principale
    setLayout(layoutPrincipale);
}

