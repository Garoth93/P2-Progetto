#include "negozio.h"


negozio::negozio(QWidget* parent):
    QWidget(parent),
    videogiochiv(new QPushButton("Videogiochi Virtuali", this)),
    videogiochif(new QPushButton("Videogiochi Fisici", this)),
    carte(new QPushButton("Carte", this)),
    tutte(new QPushButton("Tutto il negozio", this)),
    infoBottoneFisico(false),//bool info bottone fisico
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

    setLayout(mainl);

    connect(videogiochif,SIGNAL(clicked()),this,SLOT(bottoneFisico()));
    connect(videogiochiv,SIGNAL(clicked()),this,SLOT(bottoneVirtuale()));
    connect(carte,SIGNAL(clicked()),this,SLOT(bottoneCarte()));
    connect(tutte,SIGNAL(clicked()),this,SLOT(bottoneTutte()));
}

//serve per settare a true il bool bottone fisico
void negozio::bottoneFisico() {
    //setto a true info bottone fisico
    infoBottoneFisico=true;
}

//serve per settare a true il bool bottone virtuale
void negozio::bottoneVirtuale() {
    //setto a true info bottone fisico
    infoBottoneVirtuale=true;
}

//serve per settare a true il bool bottone carte
void negozio::bottoneCarte() {
    //setto a true info bottone fisico
    infoBottoneCarte=true;
}

//serve per settare a true il bool bottone tutte
void negozio::bottoneTutte() {
    //setto a true info bottone fisico
    infoBottoneTutte=true;
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

//return putatore itemwidget alla lista
itemWidget* negozio::getLista() const{
    return lista;
}

