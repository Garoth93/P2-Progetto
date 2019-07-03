#include "menu.h"

menu::menu(QWidget* p):
parent(p),
    salvaDati(new QAction("Salva", p)),
    esciDalProgramma(new QAction("Esci", p))
{
    //Assemblo il menu
    addAction(salvaDati);
    addAction(esciDalProgramma);
}

QAction* menu::getSalva() const {
    return salvaDati;
}

QAction* menu::getEsci() const{
    return esciDalProgramma;
}

