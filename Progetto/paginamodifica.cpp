#include "paginamodifica.h"

paginamodifica::paginamodifica(negozio * p , itemBase * oggM, modello * mm, QWidget * pcc):
    QWidget(nullptr),
    oggModifica(oggM),
    pNegL(p),
    pMod(mm),
    pCont(pcc),
    nomeUnoI(new QLabel("Nome",this)),//creazione label per Nome
    casaProdUnoI(new QLabel("Casa produttrice",this)),//creazione label per casa produttrice
    nomeDueI(new QLineEdit(this)),//creazione edit line per inserimento nome
    casaProdDueI(new QLineEdit(this)),//creazione edit line per inserimento casa produttrice
    prezzoBaseI(new QLineEdit(this)),
    InsButton(new QPushButton("Inserisci",this)),//creazione bottone ins
    wvirtualgameI(new QWidget(this)),//crazione widget per i dati del gioco virtuale
    wphysicalgameI(new QWidget(this)),//crazione widget per i dati del gioco fisico
    wcardgameI(new QWidget(this)),//crazione widget per i dati del gioco dic arte
    seasonpassvI(new QCheckBox(this)),//ceckbox per bool seasonpass gioco virtuale
    primaedcI(new QCheckBox(this)),
    starterdeckcI(new QCheckBox(this)),
    lipiattaformavI(new QLineEdit(this)),//creazione line per piattaforma gioco virtuale
    liconsolephyI(new QLineEdit(this)),
    liedizionephyI(new QLineEdit(this)),
    liespansioneI(new QLineEdit(this)),
    linumerocarteI(new QLineEdit(this))
{
    QGridLayout * mainl = new QGridLayout;//layout principale come matrice
    QWidget * witem = new QWidget(this);//widget per inizio ins
    //imposto i line edit per oggetto base
    nomeDueI->setText(QString::fromStdString(oggModifica->getTitolo()));
    casaProdDueI->setText(QString::fromStdString(oggModifica->getCasaProdruttrice()));
    prezzoBaseI->setText(QString::number(oggModifica->getPrezzoBase()));
    //andiamo a contralle che tipo di oggetto è
    string tipoogg = oggModifica->getTipo();
    if(tipoogg == "physicalgame"){
        liconsolephyI->setText(QString::fromStdString( dynamic_cast<physicalGame*>(oggModifica)->getQualeConsole()));
        liedizionephyI->setText(QString::fromStdString( dynamic_cast<physicalGame*>(oggModifica)->getEdizione()));;
    }
    if(tipoogg == "virtualgame"){
        lipiattaformavI->setText(QString::fromStdString( dynamic_cast<virtualGame*>(oggModifica)->getPiattaForma()));
        if(dynamic_cast<virtualGame*>(oggModifica)->getSeasonPass())
            seasonpassvI->setChecked(true);
    }
    if(tipoogg == "cardgame"){
        if(dynamic_cast<cardGame*>(oggModifica)->getPrimaEdizione())
            primaedcI->setChecked(true);
        if(dynamic_cast<cardGame*>(oggModifica)->getStarterDeck())
            starterdeckcI->setChecked(true);

        liespansioneI->setText(QString::fromStdString( dynamic_cast<cardGame*>(oggModifica)->getEspansione()));;
        linumerocarteI->setText(QString::number(dynamic_cast<cardGame*>(oggModifica)->getNumeroCarte()));
    }
    //oggetto base item
    QLabel * prezzoBaseIL = new QLabel("Prezzo Base",this);
    QGridLayout * litem = new QGridLayout;
    litem->addWidget(nomeUnoI,0,0,1,1);//aggiunta al mainl
    litem->addWidget(casaProdUnoI,1,0,1,1);
    litem->addWidget(nomeDueI,0,1,1,1);
    litem->addWidget(casaProdDueI,1,1,1,1);
    litem->addWidget(prezzoBaseIL,2,0,1,1);
    litem->addWidget(prezzoBaseI,2,1,1,1);
    witem->setLayout(litem);
    mainl->addWidget(witem,0,0,1,1);
    //bottone inserimento
    mainl->addWidget(InsButton,4,0,1,1);//aggiunta a mainl bottone cerca
    //ins videogioco virtuale
    QGridLayout * lvirtualgame = new QGridLayout;//layout come matrice per virtual game
    QLabel * lpiattaformav = new QLabel("Piattaforma",this);//creazione label per piattaforma gioco virtuale
    QLabel * lseasonpassv = new QLabel("Season pass",this);
    lvirtualgame->addWidget(lpiattaformav,0,0,1,1);
    lvirtualgame->addWidget(lipiattaformavI,0,1,1,1);
    lvirtualgame->addWidget(lseasonpassv,1,0,1,1);
    lvirtualgame->addWidget(seasonpassvI,1,1,1,1);
    wvirtualgameI->setLayout(lvirtualgame);
    mainl->addWidget(wvirtualgameI,3,0,1,1);
    //ins videogioco fisico
    QGridLayout * lphygame = new QGridLayout;//layout come matrice per gioco fisico
    QLabel * lconsolephy = new QLabel("Nome console",this);
    QLabel * ledizionephy = new QLabel("Edizione",this);
    lphygame->addWidget(lconsolephy,0,0,1,1);
    lphygame->addWidget(liconsolephyI,0,1,1,1);
    lphygame->addWidget(ledizionephy,1,0,1,1);
    lphygame->addWidget(liedizionephyI,1,1,1,1);
    wphysicalgameI->setLayout(lphygame);
    wphysicalgameI->setVisible(false);
    mainl->addWidget(wphysicalgameI,3,0,1,1);
    //ins gioco di carte
    QGridLayout * lcardgame = new QGridLayout;//layout come matrice per gioco fisico
    QLabel * lespansione = new QLabel("Espansione",this);
    QLabel * lnumerocarte = new QLabel("Numero delle carte",this);
    QLabel * lprimaedc = new QLabel("Prima edizione",this);
    QLabel * lstarterdeckc = new QLabel("Starter deck",this);
    lcardgame->addWidget(lespansione,0,0,1,1);
    lcardgame->addWidget(liespansioneI,0,1,1,1);
    lcardgame->addWidget(lnumerocarte,1,0,1,1);
    lcardgame->addWidget(linumerocarteI,1,1,1,1);
    lcardgame->addWidget(lstarterdeckc,2,0,1,1);
    lcardgame->addWidget(starterdeckcI,2,1,1,1);
    lcardgame->addWidget(lprimaedc,3,0,1,1);
    lcardgame->addWidget(primaedcI,3,1,1,1);
    wcardgameI->setLayout(lcardgame);
    wcardgameI->setVisible(false);
    mainl->addWidget(wcardgameI,3,0,1,1);
    //aggiornamento layout principale
    if(tipoogg == "physicalgame"){
        wvirtualgameI->setVisible(false);
        wphysicalgameI->setVisible(true);
        wcardgameI->setVisible(false);
    }
    if(tipoogg == "virtualgame"){
        wvirtualgameI->setVisible(true);
        wphysicalgameI->setVisible(false);
        wcardgameI->setVisible(false);
    }
    if(tipoogg == "cardgame"){
        wvirtualgameI->setVisible(false);
        wphysicalgameI->setVisible(false);
        wcardgameI->setVisible(true);
    }
    //pressione tasto inserisci dentro la tab modifica
    connect(InsButton, SIGNAL(clicked()), this, SLOT(pressioneInsInModifica()));
    setLayout(mainl);
}

//return bottono inserimento nel mod
QPushButton * paginamodifica::getBottoneModifca()const{
    return InsButton;
}

//return ogg da modificare dentr
itemBase * paginamodifica::getOggModificabile()const{
    return oggModifica;
}

//controllo per sapere se è un numero da una stringa
bool paginamodifica::is_number(const std::string &s) const{
    char* end = 0;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && val != DBL_MAX;
}

//pressione del tasto modifica nel widget
void paginamodifica::pressioneInsInModifica(){
    bool mod = false;
    string tipoItem = oggModifica->getTipo();
    //item base
    string nomeBase = (nomeDueI->text()).toLocal8Bit().constData();
    string casaProdBase = (casaProdDueI->text()).toLocal8Bit().constData();
    string prezzoBaseSt = (prezzoBaseI->text()).toLocal8Bit().constData();
    //non base
    string consolePhy;
    string edizPhy;
    string piattaVir;
    string espaCard;
    string numcarts;
    if(nomeBase != "" && casaProdBase != "" && (is_number(prezzoBaseSt))){//controllo input tipo base
        if(tipoItem == "physicalgame"){//prendo input gioco fisico
            consolePhy = (liconsolephyI->text()).toLocal8Bit().constData();
            edizPhy = (liedizionephyI->text()).toLocal8Bit().constData();
        }
        if(tipoItem == "virtualgame"){//prendo input gioco virtuale
            piattaVir = (lipiattaformavI->text()).toLocal8Bit().constData();
        }
        if(tipoItem == "cardgame"){//prendo input gioco carte
            espaCard = (liespansioneI->text()).toLocal8Bit().constData();
            numcarts = (linumerocarteI->text()).toLocal8Bit().constData();
        }
        if(tipoItem == "physicalgame"){
            if(consolePhy != "" && edizPhy != ""){//controllo tipo fisico e inerisco se valido
                physicalGame * prov = dynamic_cast<physicalGame*>(oggModifica);
                prov->setConsole(consolePhy);
                prov->setEdizione(edizPhy);
                mod=true;
            }else{
                QMessageBox::warning(this, "Attenzione!", "Inserisci valori adatti");
            }
        }
        if(tipoItem == "virtualgame"){
            virtualGame * prov = dynamic_cast<virtualGame*>(oggModifica);
            if(piattaVir != ""){
                prov->setPiattaForma(piattaVir);
                if(seasonpassvI->isChecked())
                    prov->setSeasonPass(true);
                else
                    prov->setSeasonPass(false);
                mod=true;
            }else{
                QMessageBox::warning(this, "Attenzione!", "Inserisci valori adatti");
            }
        }
        if(tipoItem == "cardgame"){
            cardGame * prov = dynamic_cast<cardGame*>(oggModifica);
            if(espaCard != "" && is_number(numcarts)){
                prov->setEspansione(espaCard);
                if(primaedcI->isChecked())
                    prov->setPrimaEd(true);
                else
                    prov->setPrimaEd(false);
                prov->setNumeroCarte(atof(numcarts.c_str()));
                if(starterdeckcI->isChecked())
                    prov->setStarterDeck(true);
                else
                    prov->setStarterDeck(false);
                mod=true;
            }else{
               QMessageBox::warning(this, "Attenzione!", "Inserisci valori adatti");
            }
        }
        if(mod==true){
            //ins mod del item base
            oggModifica->setTitolo(nomeBase);
            oggModifica->setCasaProduttrice(casaProdBase);
            oggModifica->setPrezzoBase(atof(prezzoBaseSt.c_str()));
            QMessageBox::warning(this, "Esito positivo!", "Oggetto modificato");
            close();//chiudo il widget
        }
    }else{//else controllo inserimento tipo base
        QMessageBox::warning(this, "Attenzione!", "Inserisci valori adatti");
    }
}

//funzione refresh del mio negl
void paginamodifica::refreshNeg()const{
    string tipoItem = oggModifica->getTipo();
    //salvataggio e aggiornamento dati nella view
    if(pNegL->getInfoBottoneGeneraleNeg() == true){
        pNegL->setTrueBottoneTutte();
    }else{
        if(tipoItem == "virtualgame")
            pNegL->setTrueBottoneVirtuale();
        if(tipoItem == "cardgame")
            pNegL->setTrueBottoneCarte();
        if(tipoItem == "physicalgame")
            pNegL->setTrueBottoneFisico();
    }
    pMod->salvataggio();
    pNegL->getLista()->clear();//la  mia lista è derivata da qlistwidget posso usare il metodo derivato clear per pilure la lista prec
    if(pNegL->getInfoBottoneFisico() == true) {//se ho premuto il tasto bottone fisico
        Contenitore<itemBase*>::Constiterator citini = pMod->mcbegin();
        Contenitore<itemBase*>::Constiterator citfine = pMod->mcend();
        for(; citini != citfine ; ++citini){
            if( (*citini)->getTipo() == "physicalgame" )
                pNegL->getLista()->aggiungiItem(*citini);
        }
        pNegL->setFalseBottoneFisico();//setto a false il booleano nel negozio
    }
    if(pNegL->getInfoBottoneVirtuale() == true) {//se ho premuto il tasto bottone virtuale
        Contenitore<itemBase*>::Constiterator citini = pMod->mcbegin();
        Contenitore<itemBase*>::Constiterator citfine = pMod->mcend();
        for(; citini != citfine ; ++citini){
            if( (*citini)->getTipo() == "virtualgame" )
                pNegL->getLista()->aggiungiItem(*citini);
        }
        pNegL->setFalseBottoneVirtuale();//setto a false il booleano nel negozio
    }
    if(pNegL->getInfoBottoneCarte() == true) {//se ho premuto il tasto bottone carte
        Contenitore<itemBase*>::Constiterator citini = pMod->mcbegin();
        Contenitore<itemBase*>::Constiterator citfine = pMod->mcend();
        for(; citini != citfine ; ++citini){
            if( (*citini)->getTipo() == "cardgame" )
                pNegL->getLista()->aggiungiItem(*citini);
        }
        pNegL->setFalseBottoneCarte();//setto a false il booleano nel negozio
    }
    if(pNegL->getInfoBottoneTutte() == true) {//se ho premuto il tasto bottone tutto il negozio
        Contenitore<itemBase*>::Constiterator citini = pMod->mcbegin();
        Contenitore<itemBase*>::Constiterator citfine = pMod->mcend();
        for(; citini != citfine ; ++citini){
                pNegL->getLista()->aggiungiItem(*citini);
        }
        pNegL->setFalseBottoneTutte();//setto a false il booleano nel negozio
    }
    pNegL->getBottoneElimina()->setEnabled(false);
    pNegL->getBottoneModifica()->setEnabled(false);
}

//ovverride di Qclose event
void paginamodifica::closeEvent(QCloseEvent *event) {
    if (event->spontaneous()) {
        //qDebug("The close button was clicked");
        refreshNeg();
        pCont->setDisabled(false);
        // do event->ignore();
        // or QWidget::closeEvent(event);
    } else {
        refreshNeg();
        pCont->setDisabled(false);
        //qDebug("The close button was clicked");
        //QWidget::closeEvent(event);
    }
}
