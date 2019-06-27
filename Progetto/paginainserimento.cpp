#include "paginainserimento.h"

paginainserimento::paginainserimento(QWidget * p):
    QWidget(p),
    nomeUnoI(new QLabel("Nome",this)),//creazione label per Nome
    casaProdUnoI(new QLabel("Casa produttrice",this)),//creazione label per casa produttrice
    nomeDueI(new QLineEdit(this)),//creazione edit line per inserimento nome
    casaProdDueI(new QLineEdit(this)),//creazione edit line per inserimento casa produttrice
    InsButton(new QPushButton("Inserisci",this)),//creazione bottone ins
    contenitoreradioI(new QGroupBox(tr("Scegli l'oggetto"),this)),//creazione contenitore groupbox
    rVideoVI(new QRadioButton(tr("Videogioco virtuale"),this)),//creazione 3 radio button per scegliere il tipo dell oggetto
    rVideoFI(new QRadioButton(tr("Videogioco fisico"),this)),
    rCarteI(new QRadioButton(tr("Gioco di carte"),this)),
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

    //oggetto base item
    QGridLayout * litem = new QGridLayout;
    litem->addWidget(nomeUnoI,0,0,1,1);//aggiunta al mainl
    litem->addWidget(casaProdUnoI,1,0,1,1);
    litem->addWidget(nomeDueI,0,1,1,1);
    litem->addWidget(casaProdDueI,1,1,1,1);
    witem->setLayout(litem);
    mainl->addWidget(witem,0,0,1,1);

    //radio button
    QVBoxLayout *vbox = new QVBoxLayout;//creo vbox per contenere i radio button
    rVideoVI->setChecked(true);//imposto radio button predefinito
    brVideovI = true;//imposto il primo bool a true
    vbox->addWidget(rVideoVI);
    vbox->addWidget(rVideoFI);
    vbox->addWidget(rCarteI);
    vbox->addStretch(1);
    contenitoreradioI->setLayout(vbox);
    contenitoreradioI->setFixedHeight(110);
    mainl->addWidget(contenitoreradioI,2,0,1,1);//aggiunta radio button a mainl

    //bottone inserimento
    mainl->addWidget(InsButton,4,0,1,1);//aggiunta a mainl bottone cerca

    //connect per radio button per interfaccia dinamica
    connect(rVideoVI,SIGNAL(clicked()),this,SLOT(radiobuttonslotI()));//crazione signal per vederer cosa visualizzare
    connect(rVideoFI,SIGNAL(clicked()),this,SLOT(radiobuttonslotI()));
    connect(rCarteI,SIGNAL(clicked()),this,SLOT(radiobuttonslotI()));

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
    connect(InsButton,SIGNAL(clicked()),this,SLOT(pressTastoInserimento()));

    //metto il loyout principale dentro a un widget
    /*QWidget * mainw = new QWidget;
    mainw->setLayout(mainl);*/

    //creo il mio loyour orrizontale finale per insire i due widget finali
    /*QHBoxLayout * mainwtot = new QHBoxLayout;
    mainwtot->addWidget(mainw);
    mainwtot->addWidget(lista);*/

    //aggiornamento layout principale
    setLayout(mainl);
}

//slot signal radiobutton
void paginainserimento::radiobuttonslotI() {
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
}

//setta il bool per lo stato ins a true dopo aver premuto il tasto ins
void paginainserimento::pressTastoInserimento(){
    statoIns = true;
}

//return booleano per lo stato ins
bool paginainserimento::infoStatoIns()const{
    return statoIns;
}

//get bottne ins
QPushButton* paginainserimento::getBottoneInserimento() const {
    return InsButton;
}

itemBase * paginainserimento::creazioneOggIns(){
    string nomeogg = (nomeDueI->text()).toLocal8Bit().constData();
    string casapogg = (casaProdDueI->text()).toLocal8Bit().constData();
    if(brVideovI == true){//oggetto virtuale
        /*ricorda usiamo conversione to local 8 per windows
          possiamo usare sempre queste 2
          std::string utf8_text = qs.toUtf8().constData();
          std::string current_locale_text = qs.toLocal8Bit().constData();*/
        string piattaogg = (lipiattaformavI->text()).toLocal8Bit().constData();
        bool seasonogg = false;
        if (seasonpassvI->isChecked())
            seasonogg = true;
        itemBase * oggetto = new virtualGame(nomeogg,casapogg,0,piattaogg,seasonogg);
        return oggetto;
    }
    if(brVideofI == true){//oggetto fisico
        string consogg = (liconsolephyI->text()).toLocal8Bit().constData();
        string edizogg = (liedizionephyI->text()).toLocal8Bit().constData();
        itemBase * oggetto = new physicalGame(nomeogg,casapogg,0,consogg,edizogg);
        return oggetto;
    }
    if(brCarteI == true){//oggetto carte
        string espaogg = (liespansioneI->text()).toLocal8Bit().constData();
        string numcogg = (linumerocarteI->text()).toLocal8Bit().constData();
        double numcoggd = atof(numcogg.c_str());
        bool primaogg = false; bool startogg = false;
        if(primaedcI->isChecked())
            primaogg = true;
        if(starterdeckcI->isChecked())
            startogg = true;
        itemBase * oggetto = new cardGame(nomeogg,casapogg,0,espaogg,primaogg,numcoggd,startogg);
        return oggetto;
    }
}


