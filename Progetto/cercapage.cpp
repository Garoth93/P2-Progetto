#include "cercapage.h"

cercapage::cercapage(QWidget* parent):
    QWidget(parent),
    nomeUno(new QLabel("Nome",this)),//creazione label per Nome
    casaProdUno(new QLabel("Casa produttrice",this)),//creazione label per casa produttrice
    nomeDue(new QLineEdit(this)),//creazione edit line per inserimento nome
    casaProdDue(new QLineEdit(this)),//creazione edit line per inserimento casa produttrice
    lista(new itemWidget(this)),
    cercabutton(new QPushButton("Cerca",this)),//creazione bottone cerca
    wvirtualgame(new QWidget(this)),//crazione widget per i dati del gioco virtuale
    wphysicalgame(new QWidget(this)),//crazione widget per i dati del gioco fisico
    wcardgame(new QWidget(this)),//crazione widget per i dati del gioco dic arte
    contenitoreradio(new QGroupBox(tr("Scegli l'oggetto"),this)),//creazione contenitore groupbox
    rVideoV(new QRadioButton(tr("Videogioco virtuale"),this)),//creazione 3 radio button per scegliere il tipo dell oggetto
    rVideoF(new QRadioButton(tr("Videogioco fisico"),this)),
    rCarte(new QRadioButton(tr("Gioco di carte"),this)),
    seasonpassv(new QCheckBox(this)),//ceckbox per bool seasonpass gioco virtuale
    primaedc(new QCheckBox(this)),
    starterdeckc(new QCheckBox(this)),
    lipiattaformav(new QLineEdit(this)),//creazione line per piattaforma gioco virtuale
    liconsolephy(new QLineEdit(this)),
    liedizionephy(new QLineEdit(this)),
    liespansione(new QLineEdit(this)),
    linumerocarte(new QLineEdit(this))
{
    QGridLayout * mainl = new QGridLayout;//layout principale come matrice

    QWidget * witem = new QWidget(this);//widget per inizio ricerca

    //oggetto base item
    QGridLayout * litem = new QGridLayout;
    litem->addWidget(nomeUno,0,0,1,1);//aggiunta al mainl
    litem->addWidget(casaProdUno,1,0,1,1);
    litem->addWidget(nomeDue,0,1,1,1);
    litem->addWidget(casaProdDue,1,1,1,1);
    witem->setLayout(litem);
    mainl->addWidget(witem,0,0,1,1);

    //radio button
    QVBoxLayout *vbox = new QVBoxLayout;//creo vbox per contenere i radio button
    rVideoV->setChecked(true);//imposto radio button predefinito
    brVideov = true;//imposto il primo bool a true
    vbox->addWidget(rVideoV);
    vbox->addWidget(rVideoF);
    vbox->addWidget(rCarte);
    vbox->addStretch(1);
    contenitoreradio->setLayout(vbox);
    contenitoreradio->setFixedHeight(110);
    mainl->addWidget(contenitoreradio,2,0,1,1);//aggiunta radio button a mainl

    //bottone cerca
    mainl->addWidget(cercabutton,4,0,1,1);//aggiunta a mainl bottone cerca

    //connect per radio button per interfaccia dinamica
    connect(rVideoV,SIGNAL(clicked()),this,SLOT(radiobuttonslot()));//crazione signal per vederer cosa visualizzare
    connect(rVideoF,SIGNAL(clicked()),this,SLOT(radiobuttonslot()));
    connect(rCarte,SIGNAL(clicked()),this,SLOT(radiobuttonslot()));

    //ricerca videogioco virtuale
    QGridLayout * lvirtualgame = new QGridLayout;//layout come matrice per virtual game
    QLabel * lpiattaformav = new QLabel("Piattaforma",this);//creazione label per piattaforma gioco virtuale
    QLabel * lseasonpassv = new QLabel("Season pass",this);
    lvirtualgame->addWidget(lpiattaformav,0,0,1,1);
    lvirtualgame->addWidget(lipiattaformav,0,1,1,1);
    lvirtualgame->addWidget(lseasonpassv,1,0,1,1);
    lvirtualgame->addWidget(seasonpassv,1,1,1,1);
    wvirtualgame->setLayout(lvirtualgame);
    mainl->addWidget(wvirtualgame,3,0,1,1);

    //ricerca videogioco fisico
    QGridLayout * lphygame = new QGridLayout;//layout come matrice per gioco fisico
    QLabel * lconsolephy = new QLabel("Nome console",this);
    QLabel * ledizionephy = new QLabel("Edizione",this);
    lphygame->addWidget(lconsolephy,0,0,1,1);
    lphygame->addWidget(liconsolephy,0,1,1,1);
    lphygame->addWidget(ledizionephy,1,0,1,1);
    lphygame->addWidget(liedizionephy,1,1,1,1);
    wphysicalgame->setLayout(lphygame);
    wphysicalgame->setVisible(false);
    mainl->addWidget(wphysicalgame,3,0,1,1);

    //ricerca gioco di carte
    QGridLayout * lcardgame = new QGridLayout;//layout come matrice per gioco fisico
    QLabel * lespansione = new QLabel("Espansione",this);
    QLabel * lnumerocarte = new QLabel("Numero delle carte",this);
    QLabel * lprimaedc = new QLabel("Prima edizione",this);
    QLabel * lstarterdeckc = new QLabel("Starter deck",this);
    lcardgame->addWidget(lespansione,0,0,1,1);
    lcardgame->addWidget(liespansione,0,1,1,1);
    lcardgame->addWidget(lnumerocarte,1,0,1,1);
    lcardgame->addWidget(linumerocarte,1,1,1,1);
    lcardgame->addWidget(lstarterdeckc,2,0,1,1);
    lcardgame->addWidget(starterdeckc,2,1,1,1);
    lcardgame->addWidget(lprimaedc,3,0,1,1);
    lcardgame->addWidget(primaedc,3,1,1,1);
    wcardgame->setLayout(lcardgame);
    wcardgame->setVisible(false);
    mainl->addWidget(wcardgame,3,0,1,1);

    //segnale dopo aver premuto il tasto ricerca
    connect(cercabutton,SIGNAL(clicked()),this,SLOT(pressTastoRicerca()));

    //metto il loyout principale dentro a un widget
    QWidget * mainw = new QWidget;
    mainw->setLayout(mainl);

    //creo il mio loyour orrizontale finale per insire i due widget finali
    QHBoxLayout * mainwtot = new QHBoxLayout;
    mainwtot->addWidget(mainw);
    mainwtot->addWidget(lista);

    //aggiornamento layout principale
    setLayout(mainwtot);
}

void cercapage::radiobuttonslot() {
        QRadioButton* srb = qobject_cast<QRadioButton*>(sender());
        std::string name = srb->text().toStdString();
        if(name=="Videogioco virtuale"){
            wvirtualgame->setVisible(true);
            wphysicalgame->setVisible(false);
            wcardgame->setVisible(false);
            brVideov = true;
            brVideof = false;
            brCarte = false;
        }
        if(name=="Videogioco fisico"){
            wvirtualgame->setVisible(false);
            wphysicalgame->setVisible(true);
            wcardgame->setVisible(false);
            brVideov = false;
            brVideof = true;
            brCarte = false;
        }
        if(name=="Gioco di carte"){
            wvirtualgame->setVisible(false);
            wphysicalgame->setVisible(false);
            wcardgame->setVisible(true);
            brVideov = false;
            brVideof = false;
            brCarte = true;
        }
}

itemBase* cercapage::creazioneOggRicerca(){
    string nomeogg = (nomeDue->text()).toLocal8Bit().constData();
    string casapogg = (casaProdDue->text()).toLocal8Bit().constData();
    if(brVideov == true){//oggetto virtuale
        /*ricorda usiamo conversione to local 8 per windows
          possiamo usare sempre queste 2
          std::string utf8_text = qs.toUtf8().constData();
          std::string current_locale_text = qs.toLocal8Bit().constData();*/
        string piattaogg = (lipiattaformav->text()).toLocal8Bit().constData();
        bool seasonogg = false;
        if (seasonpassv->isChecked())
            seasonogg = true;
        itemBase * oggetto = new virtualGame(nomeogg,casapogg,0,piattaogg,seasonogg);
        return oggetto;
    }
    if(brVideof == true){//oggetto fisico
        string consogg = (liconsolephy->text()).toLocal8Bit().constData();
        string edizogg = (liedizionephy->text()).toLocal8Bit().constData();
        itemBase * oggetto = new physicalGame(nomeogg,casapogg,0,consogg,edizogg);
        return oggetto;
    }
    if(brCarte == true){//oggetto carte
        string espaogg = (liespansione->text()).toLocal8Bit().constData();
        string numcogg = (linumerocarte->text()).toLocal8Bit().constData();
        double numcoggd = atof(numcogg.c_str());
        bool primaogg = false; bool startogg = false;
        if(primaedc->isChecked())
            primaogg = true;
        if(starterdeckc->isChecked())
            startogg = true;
        itemBase * oggetto = new cardGame(nomeogg,casapogg,0,espaogg,primaogg,numcoggd,startogg);
        return oggetto;
    }
    return nullptr;
}

//setta il bool per lo stato ricerca a true dopo aver premuto il tasto cerca
void cercapage::pressTastoRicerca(){
    statoRicerca = true;
}

//return booleano per lo stato della ricerca
bool cercapage::infoStatoRicerca()const{
    return statoRicerca;
}

//get bottne ricerca
QPushButton* cercapage::getBottoneRicerca() const {
    return cercabutton;
}

itemWidget* cercapage::getLista()const{
    return lista;
}
