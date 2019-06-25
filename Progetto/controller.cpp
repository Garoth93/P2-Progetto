#include "controller.h"

controller::controller(QWidget *parent):
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    mymenu(new menu(this)),
    negl(new negozio(this)),
    tab(new QTabWidget(this)),
    cercapagina(new cercapage(this)),
    file(QFileDialog::getOpenFileName(this, tr("Scegli FIle"), "Progetto/SalvataggioDati", "File XML(*.xml)")),//prova per model sistemare
    model(new modello(file.toStdString()))//prova per model sistemare
{
    //carico i dati nel model
    model->setNuovoPercorso(file.toStdString());
    model->caricamento();

    layoutPrincipale->setMenuBar(mymenu);
    tab->setTabPosition(QTabWidget::South);//posiozione del "menù" tab
    tab->addTab(negl,"Negozio");//aggiungo alla tab il mio Qwidget ricorda vuole
    tab->addTab(cercapagina,"Ricerca");
    layoutPrincipale->addWidget(tab);//aggingo la mia tab all layout principale

    //connect per bottone visualizzazione videogioco fisico nel negozio
    connect(negl->getBottoneFisico(), SIGNAL(clicked()), this, SLOT(caricaDatiNegozio()));
    connect(negl->getBottoneVirtuale(), SIGNAL(clicked()), this, SLOT(caricaDatiNegozio()));
    connect(negl->getBottoneCarte(), SIGNAL(clicked()), this, SLOT(caricaDatiNegozio()));
    connect(negl->getBottoneTutte(), SIGNAL(clicked()), this, SLOT(caricaDatiNegozio()));

    connect(cercapagina->getBottoneRicerca(), SIGNAL(clicked()), this, SLOT(avviaRicercaOgg()));



    setLayout(layoutPrincipale);

}

//funnzione public slot carica dati
void controller::caricaDatiNegozio(){
    if(file!=""){//se il mio file non è vuoto
        negl->getLista()->clear();//la  mia lista è derivata da qlistwidget posso usare il metodo derivato clear per pilure la lista prec
        if(negl->getInfoBottoneFisico() == true) {//se ho premuto il tasto bottone fisico
            Contenitore<itemBase*>::Constiterator citini = model->mcbegin();
            Contenitore<itemBase*>::Constiterator citfine = model->mcend();
            for(; citini != citfine ; ++citini){
                if( (*citini)->getTipo() == "physicalgame" )
                    negl->getLista()->aggiungiItem(*citini);
            }
            negl->setFalseBottoneFisico();//setto a false il booleano nel negozio
        }
        if(negl->getInfoBottoneVirtuale() == true) {//se ho premuto il tasto bottone virtuale
            Contenitore<itemBase*>::Constiterator citini = model->mcbegin();
            Contenitore<itemBase*>::Constiterator citfine = model->mcend();
            for(; citini != citfine ; ++citini){
                if( (*citini)->getTipo() == "virtualgame" )
                    negl->getLista()->aggiungiItem(*citini);
            }
            negl->setFalseBottoneVirtuale();//setto a false il booleano nel negozio
        }
        if(negl->getInfoBottoneCarte() == true) {//se ho premuto il tasto bottone carte
            Contenitore<itemBase*>::Constiterator citini = model->mcbegin();
            Contenitore<itemBase*>::Constiterator citfine = model->mcend();
            for(; citini != citfine ; ++citini){
                if( (*citini)->getTipo() == "cardgame" )
                    negl->getLista()->aggiungiItem(*citini);
            }
            negl->setFalseBottoneCarte();//setto a false il booleano nel negozio
        }
        if(negl->getInfoBottoneTutte() == true) {//se ho premuto il tasto bottone tutto il negozio
            Contenitore<itemBase*>::Constiterator citini = model->mcbegin();
            Contenitore<itemBase*>::Constiterator citfine = model->mcend();
            for(; citini != citfine ; ++citini){
                    negl->getLista()->aggiungiItem(*citini);
            }
            negl->setFalseBottoneTutte();//setto a false il booleano nel negozio
        }
    }
}

//funzione di ricerca oggetto
void controller::avviaRicercaOgg() {
    cercapagina->getLista()->clear();
    itemBase * provvisorio = cercapagina->creazioneOggRicerca();//creo oggetto da ricercare per poi andare a cercarlo nella  mia lista
    Contenitore<itemBase*>::Constiterator citini = model->mcbegin();
    Contenitore<itemBase*>::Constiterator citfine = model->mcend();
    for(; citini != citfine ; ++citini){
        if( *provvisorio == *(*citini) )
            cercapagina->getLista()->aggiungiItem(*citini);
    }
    delete provvisorio;
}

