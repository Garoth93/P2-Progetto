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
    Contenitore<const item*>S(NULL,NULL);
    const item * cff = new cardGame("uno","unouno",5,"tgcs",true,11,false);
    const item * cfg = new cardGame("due","duedue",5,"tgcs",true,11,false);
    S.PushEnd(cff);
    S.PushBegin(cfg);
    Contenitore<const item*>::Constiterator cit = S.cbegin();
    std::cout << *(*cit) << std::endl;
    ++cit;
    std::cout << *(*cit) << std::endl;
    --cit;
    std::cout << *(*cit) << std::endl;

    Contenitore<const item*>Q(NULL,NULL);
    const item * ff = new cardGame("unoc","unoc",5,"tgcs",true,11,false);
    const item * fg = new cardGame("duec","duec",5,"tgcs",true,11,false);
    Q.PushEnd(ff);
    Q.PushBegin(fg);
    Contenitore<const item*>::Iterator it = Q.begin();
    std::cout << *(*it) << std::endl;
    ++it;
    std::cout << *(*it) << std::endl;
    delete(*it);
    it=Q.erase(it);
    --it;
    if(it != Q.end() )
        std::cout << *(*it) << std::endl;
    std::cout << "FINE"<< std::endl;
}
