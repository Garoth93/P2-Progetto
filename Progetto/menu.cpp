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

