#include "negozio.h"

negozio::negozio(QWidget* parent):
    QWidget(parent),
    videogiochiv(new QPushButton("Videogiochi", this)),
    videogiochif(new QPushButton("Videogiochi", this)),
    carte(new QPushButton("Carte", this))
    //mainl(new QHBoxLayout),
    //buttonl(new QVBoxLayout),
    //vislist(new QListWidget)
{
    QHBoxLayout * mainl = new QHBoxLayout;
    QVBoxLayout * buttonl = new QVBoxLayout;
    QListWidget * vislist = new QListWidget;
    buttonl->addWidget(videogiochiv);
    buttonl->addWidget(videogiochif);
    buttonl->addWidget(carte);
    mainl->addLayout(buttonl);
    mainl->addWidget(vislist);
    setLayout(mainl);
}

