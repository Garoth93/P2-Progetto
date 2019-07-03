#include "negozio.h"


negozio::negozio(QWidget* parent):
    QWidget(parent),
    videogiochiv(new QPushButton("Videogiochi Virtuali", this)),
    videogiochif(new QPushButton("Videogiochi Fisici", this)),
    carte(new QPushButton("Carte", this)),
    tutte(new QPushButton("Tutto il negozio", this)),
    belimina(new QPushButton("Elimina oggetto", this)),
    bmodifica(new QPushButton("Modifica oggetto", this)),
    //infoBottoneFisico(false),//bool info bottone fisico
    lista(new itemWidget(this))
    //mainl(new QHBoxLayout),
    //buttonl(new QVBoxLayout),
    //vislist(new QListWidget)
{
    QHBoxLayout * mainl = new QHBoxLayout;
    QVBoxLayout * buttonl = new QVBoxLayout;
    buttonl->addWidget(tutte);
    buttonl->addWidget(videogiochiv);
    buttonl->addWidget(videogiochif);
    buttonl->addWidget(carte);
    mainl->addLayout(buttonl);
    mainl->addWidget(lista);

    //per bottoni modifica e elimina
    bmodifica->setEnabled(false);
    belimina->setEnabled(false);
    QHBoxLayout * sotto = new QHBoxLayout;
    sotto->addWidget(belimina);
    sotto->addWidget(bmodifica);

    //layout totale finale
    QVBoxLayout * mainlfinale = new QVBoxLayout;
    QWidget * wsopra = new QWidget;
    QWidget * wsotto = new QWidget;
    wsopra->setLayout(mainl);
    wsotto->setLayout(sotto);
    mainlfinale->addWidget(wsopra);
    mainlfinale->addWidget(wsotto);

    //setloyout passando il layout finale
    setLayout(mainlfinale);

    connect(videogiochif,SIGNAL(clicked()),this,SLOT(bottoneFisico()));
    connect(videogiochiv,SIGNAL(clicked()),this,SLOT(bottoneVirtuale()));
    connect(carte,SIGNAL(clicked()),this,SLOT(bottoneCarte()));
    connect(tutte,SIGNAL(clicked()),this,SLOT(bottoneTutte()));
    //per il tasto elimina
    connect(lista, SIGNAL(itemSelectionChanged()), this, SLOT(pressioneLista()));
}

//serve per settare a true il bool bottone fisico
void negozio::bottoneFisico() {
    //setto a true info bottone fisico
    infoBottoneFisico=true;
    infoGeneraleNegozioTotale=false;//serve per vis dopo elimina
}

//serve per settare a true il bool bottone virtuale
void negozio::bottoneVirtuale() {
    //setto a true info bottone fisico
    infoBottoneVirtuale=true;
    infoGeneraleNegozioTotale=false;
}

//serve per settare a true il bool bottone carte
void negozio::bottoneCarte() {
    //setto a true info bottone fisico
    infoBottoneCarte=true;
    infoGeneraleNegozioTotale=false;
}

//serve per settare a true il bool bottone tutte
void negozio::bottoneTutte() {
    //setto a true info bottone fisico
    infoBottoneTutte=true;
    infoGeneraleNegozioTotale=true;
}

void negozio::pressioneModifica(){
    infoModifica = true;
}

//set a bool info elimina dopo aver premuto il tasto elimina
void negozio::bottoneElimina(){
    infoElimina=true;
}

//VIDEOGIOCO FISICO
//info get fisico bottone
bool negozio::getInfoBottoneFisico() const {
    return infoBottoneFisico;
}

//return bottone fisico
QPushButton* negozio::getBottoneFisico() const {
    return videogiochif;
}

//setto a false il booleano info bottone fisico
void negozio::setFalseBottoneFisico(){
    infoBottoneFisico = false;
}

//setto a true il booleano info bottone fisico
void negozio::setTrueBottoneFisico(){
    infoBottoneFisico = true;
}

//VIDEOGIOCHI VIRTUALE
//info get bottone virtuale
bool negozio::getInfoBottoneVirtuale() const {
    return infoBottoneVirtuale;
}

//return bottone virtuale
QPushButton* negozio::getBottoneVirtuale() const {
    return videogiochiv;
}

//setto a false il booleano info bottone virtuale
void negozio::setFalseBottoneVirtuale(){
    infoBottoneVirtuale = false;
}

//setto a true bool virtuale
void negozio::setTrueBottoneVirtuale(){
    infoBottoneVirtuale = true;
}

//CARTE
//info get fisico Carte
bool negozio::getInfoBottoneCarte() const {
    return infoBottoneCarte;
}

//return bottone carte
QPushButton* negozio::getBottoneCarte() const {
    return carte;
}

//setto a false il booleano info bottone carte
void negozio::setFalseBottoneCarte(){
    infoBottoneCarte = false;
}

//setto a true il booleano info bottone carte
void negozio::setTrueBottoneCarte(){
    infoBottoneCarte = true;
}

//TUTTE
//info get fisico Carte
bool negozio::getInfoBottoneTutte() const {
    return infoBottoneTutte;
}

//return bottone carte
QPushButton* negozio::getBottoneTutte() const {
    return tutte;
}

//setto a false il booleano info bottone carte
void negozio::setFalseBottoneTutte(){
    infoBottoneTutte = false;
}

//setto a true il booleano info bottone carte
void negozio::setTrueBottoneTutte(){
    infoBottoneTutte = true;
}

//ELIMINA
//info get bool elimina
bool negozio::getInfoBottoneElimina() const {
    return infoElimina;
}

//return bottone carte
QPushButton* negozio::getBottoneElimina() const {
    return belimina;
}

//setto a false il booleano info bottone carte
void negozio::setFalseBottoneElimina(){
    infoElimina = false;
}

//BOTTONE MODIFICA
//info get bool modifica
bool negozio::getInfoBottoneModifica() const {
    return infoModifica;
}

//return bottone carte
QPushButton* negozio::getBottoneModifica() const {
    return bmodifica;
}

//setto a false il booleano info bottone carte
void negozio::setFalseBottoneModifica(){
    infoModifica = false;
}

//return putatore itemwidget alla lista
itemWidget* negozio::getLista() const{
    return lista;
}

//funzione alla elemento della lista
void negozio::pressioneLista() {
    infoElimina=true;
    bmodifica->setEnabled(true);
    belimina->setEnabled(true);
}

//bottone generale info negozio totale
bool negozio::getInfoBottoneGeneraleNeg() const{
    return infoGeneraleNegozioTotale;
}

