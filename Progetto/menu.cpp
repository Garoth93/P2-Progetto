#include "menu.h"

menu::menu(QWidget* p):
parent(p),
    negozio(new QAction("Negozio", p)),
    ricerca(new QAction("Ricerca", p)),
    inserisci(new QAction("Inserisci", p))
{
    //Assemblo il menu
        addAction(negozio);
        addAction(ricerca);
        addAction(inserisci);
}

