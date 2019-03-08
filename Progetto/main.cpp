//#include "mainwindow.h"
//#include <QApplication>

#include "physicalgame.h"
#include "virtualgame.h"
#include "cardgame.h"
#include "contenitore.h"

/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}*/

int main()
{
    Contenitore<const item*>Q(NULL,NULL);
    const item * ff = new cardGame("diocane","",5,"tgcs",true,11,false);
    const item * fg = new cardGame("diocssssane","",5,"tgcs",true,11,false);
    Q.PushEnd(ff);
    Q.PushBegin(fg);
    Contenitore<const item*>::Constiterator cit = Q.begin();
    std::cout << *(*cit);
    ++cit;
    std::cout << *(*cit);
}
