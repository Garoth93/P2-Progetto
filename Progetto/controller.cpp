#include "controller.h"

controller::controller(QWidget *parent):
    QWidget(parent),
    layoutPrincipale(new QVBoxLayout(this)),
    mymenu(new menu(this)),
    negl(new negozio(this)),
    pagins(new paginainserimento(this)),
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
    tab->addTab(pagins,"Inserisci nuovo oggetto");

    layoutPrincipale->addWidget(tab);//aggingo la mia tab all layout principale

    //connect per bottone visualizzazione videogioco fisico nel negozio
    connect(negl->getBottoneFisico(), SIGNAL(clicked()), this, SLOT(caricaDatiNegozio()));
    connect(negl->getBottoneVirtuale(), SIGNAL(clicked()), this, SLOT(caricaDatiNegozio()));
    connect(negl->getBottoneCarte(), SIGNAL(clicked()), this, SLOT(caricaDatiNegozio()));
    connect(negl->getBottoneTutte(), SIGNAL(clicked()), this, SLOT(caricaDatiNegozio()));

    connect(cercapagina->getBottoneRicerca(), SIGNAL(clicked()), this, SLOT(avviaRicercaOgg()));

    //dopo aver premuto il tasto elimina
    connect(negl->getBottoneElimina(), SIGNAL(clicked()), this, SLOT(eliminaOggetto()));

    //dopo aver premuto il tasto ins
    connect(pagins->getBottoneInserimento(), SIGNAL(clicked()), this, SLOT(avviaIns()));


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
    negl->getBottoneElimina()->setEnabled(false);
    negl->getBottoneModifica()->setEnabled(false);
}

//funzione di ricerca oggetto
void controller::avviaRicercaOgg() {
    bool cercaOggetto = false;
    cercapagina->getLista()->clear();
    itemBase * provvisorio = cercapagina->creazioneOggRicerca();//creo oggetto da ricercare per poi andare a cercarlo nella  mia lista
    Contenitore<itemBase*>::Constiterator citini = model->mcbegin();
    Contenitore<itemBase*>::Constiterator citfine = model->mcend();
    for(; citini != citfine ; ++citini){
        if( *provvisorio == *(*citini) ){
            cercaOggetto = true;
            cercapagina->getLista()->aggiungiItem(*citini);
        }
    }
    if(cercaOggetto)
        QMessageBox::warning(this, "Esito positivo!", "La ricerca ha dato risultato");
    else
        QMessageBox::warning(this, "Esito negativo!", "La ricerca non ha dato risultato");
    delete provvisorio;
}

//funzione elimina oggett
void controller::eliminaOggetto(){
    if(negl->getInfoBottoneElimina() == true){
        bool eliminazioneFatta = false;
        listaditem * prov = NULL;
        itemBase * del = NULL;
        prov = negl->getLista()->itemCorrente();
        del = prov->prelevaItem();
        Contenitore<itemBase*>::Iterator itini = model->mbegin();
        Contenitore<itemBase*>::Iterator itfine = model->mend();
        string tipoogg= del->getTipo();
        for(; itini != itfine ; ++itini){
            if( *del == *(*itini) ){
                eliminazioneFatta = true;
                delete del;
                model->meliminanoi(itini);
            }
        }
        if(eliminazioneFatta)
            QMessageBox::warning(this, "Esito positivo!", "L'oggetto è stato rimosso dal catalogo!");
        else
            QMessageBox::warning(this, "Esito negativo!", "L'oggetto non è stato rimosso dal catalogo!");
        negl->setFalseBottoneElimina();
        negl->getBottoneElimina()->setEnabled(false);
        negl->getBottoneModifica()->setEnabled(false);
        if(negl->getInfoBottoneGeneraleNeg() == true){
            negl->setTrueBottoneTutte();
        }else{
            if(tipoogg == "virtualgame")
                negl->setTrueBottoneVirtuale();
            if(tipoogg == "cardgame")
                negl->setTrueBottoneCarte();
            if(tipoogg == "physicalgame")
                negl->setTrueBottoneFisico();
        }
        model->salvataggio();
        model->setNuovoPercorso(file.toStdString());
        model->caricamento();
        caricaDatiNegozio();
    }
}

//funzione di ins oggetto
void controller::avviaIns() {
    itemBase * provvisorio = pagins->creazioneOggIns();//creo oggetto da ricercare per poi andare a cercarlo nella  mia lista
    model->getlista()->PushEnd(provvisorio);
    QMessageBox::warning(this, "Esito positivo!", "Oggetto inserito");
    model->salvataggio();
    model->setNuovoPercorso(file.toStdString());
    model->caricamento();
}
