#include "paginamodifica.h"

paginamodifica::paginamodifica(negozio * p , itemBase * oggM, modello * mm, QWidget * pcc):
    QWidget(NULL),
    pNegL(p),
    pMod(mm),
    pCont(pcc),
    oggModifica(oggM),
    nomeUnoI(new QLabel("Nome",this)),//creazione label per Nome
    casaProdUnoI(new QLabel("Casa produttrice",this)),//creazione label per casa produttrice
    nomeDueI(new QLineEdit(this)),//creazione edit line per inserimento nome
    casaProdDueI(new QLineEdit(this)),//creazione edit line per inserimento casa produttrice
    InsButton(new QPushButton("Inserisci",this)),//creazione bottone ins
    /*contenitoreradioI(new QGroupBox(tr("Scegli l'oggetto"),this)),//creazione contenitore groupbox
    rVideoVI(new QRadioButton(tr("Videogioco virtuale"),this)),//creazione 3 radio button per scegliere il tipo dell oggetto
    rVideoFI(new QRadioButton(tr("Videogioco fisico"),this)),
    rCarteI(new QRadioButton(tr("Gioco di carte"),this)),*/
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
    linumerocarteI(new QLineEdit(this)),
    prezzoBaseI(new QLineEdit(this))
{
    QGridLayout * mainl = new QGridLayout;//layout principale come matrice

    QWidget * witem = new QWidget(this);//widget per inizio ins
    //imposto i line edit per oggetto base
    nomeDueI->setText(QString::fromStdString(oggModifica->getTitolo()));
    casaProdDueI->setText(QString::fromStdString(oggModifica->getCasaProdruttrice()));
    prezzoBaseI->setText(QString::number(oggModifica->getPrezzoBase()));
    //manca prezzo base
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

    //radio button
    /*QVBoxLayout *vbox = new QVBoxLayout;//creo vbox per contenere i radio button
    vbox->addWidget(rVideoVI);
    vbox->addWidget(rVideoFI);
    vbox->addWidget(rCarteI);
    vbox->addStretch(1);
    contenitoreradioI->setLayout(vbox);
    contenitoreradioI->setFixedHeight(110);
    contenitoreradioI->hide();//nascondo i radio button
    mainl->addWidget(contenitoreradioI,2,0,1,1);//aggiunta radio button a mainl*/

    //bottone inserimento
    mainl->addWidget(InsButton,4,0,1,1);//aggiunta a mainl bottone cerca

    //connect per radio button
    /*connect(rVideoVI,SIGNAL(clicked()),this,SLOT(radiobuttonslotM()));//crazione signal per vederer cosa visualizzare
    connect(rVideoFI,SIGNAL(clicked()),this,SLOT(radiobuttonslotM()));
    connect(rCarteI,SIGNAL(clicked()),this,SLOT(radiobuttonslotM()));*/

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

    //segnale dopo aver premuto il tasto ricerca
    //connect(InsButton,SIGNAL(clicked()),this,SLOT(pressTastoInserimento()));

    //metto il loyout principale dentro a un widget
    /*QWidget * mainw = new QWidget;
    mainw->setLayout(mainl);*/

    //creo il mio loyour orrizontale finale per insire i due widget finali
    /*QHBoxLayout * mainwtot = new QHBoxLayout;
    mainwtot->addWidget(mainw);
    mainwtot->addWidget(lista);*/

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

//slot signal radiobutton
/*void paginamodifica::radiobuttonslotM() {
        QRadioButton* srb = qobject_cast<QRadioButton*>(sender());
        std::string name = srb->text().toStdString();
        if(name=="Videogioco virtuale"){
            wvirtualgameI->setVisible(true);
            wphysicalgameI->setVisible(false);
            wcardgameI->setVisible(false);
            brVideovI = true;
            brVideofI = false;
            brCarteI = false;
        }
        if(name=="Videogioco fisico"){
            wvirtualgameI->setVisible(false);
            wphysicalgameI->setVisible(true);
            wcardgameI->setVisible(false);
            brVideovI = false;
            brVideofI = true;
            brCarteI = false;
        }
        if(name=="Gioco di carte"){
            wvirtualgameI->setVisible(false);
            wphysicalgameI->setVisible(false);
            wcardgameI->setVisible(true);
            brVideovI = false;
            brVideofI = false;
            brCarteI = true;
        }
}*/

void paginamodifica::pressioneInsInModifica(){
    bool mod = false;
    string tipoItem = oggModifica->getTipo();
    oggModifica->setTitolo((nomeDueI->text()).toLocal8Bit().constData());
    oggModifica->setCasaProduttrice((casaProdDueI->text()).toLocal8Bit().constData());
    string prezzoBaseSt = (prezzoBaseI->text()).toLocal8Bit().constData();
    oggModifica->setPrezzoBase(atof(prezzoBaseSt.c_str()));
    if(tipoItem == "physicalgame"){
        physicalGame * prov = dynamic_cast<physicalGame*>(oggModifica);
        prov->setConsole((liconsolephyI->text()).toLocal8Bit().constData());
        prov->setEdizione((liedizionephyI->text()).toLocal8Bit().constData());
        mod=true;
    }
    if(tipoItem == "virtualgame"){
        virtualGame * prov = dynamic_cast<virtualGame*>(oggModifica);
        prov->setPiattaForma((lipiattaformavI->text()).toLocal8Bit().constData());
        if(seasonpassvI->isChecked())
            prov->setSeasonPass(true);
        else
            prov->setSeasonPass(false);
        mod=true;
    }
    if(tipoItem == "cardgame"){
        cardGame * prov = dynamic_cast<cardGame*>(oggModifica);
        prov->setEspansione((liespansioneI->text()).toLocal8Bit().constData());
        if(primaedcI->isChecked())
            prov->setPrimaEd(true);
        else
            prov->setPrimaEd(false);
        string numcarts = (linumerocarteI->text()).toLocal8Bit().constData();
        prov->setNumeroCarte(atof(numcarts.c_str()));
        if(starterdeckcI->isChecked())
            prov->setStarterDeck(true);
        else
            prov->setStarterDeck(false);
        mod=true;
    }
    if(mod==true)
        QMessageBox::warning(this, "Esito positivo!", "Oggetto modificato");
    else
        QMessageBox::warning(this, "Esito negativo!", "Oggetto non modificato");
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

    pCont->setDisabled(false);
    close();//chiudo il widget
}
