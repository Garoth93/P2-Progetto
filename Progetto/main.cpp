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
    /*Contenitore<const item*>S(NULL,NULL);
    const item * cff = new cardGame("uno","unouno",5,"tgcs",true,11,false);
    const item * cfg = new cardGame("due","duedue",5,"tgcs",true,11,false);
    S.PushEnd(cff);
    S.PushBegin(cfg);
    Contenitore<const item*>::Constiterator cit = S.cbegin();
    std::cout << *(*cit) << std::endl;
    ++cit;
    std::cout << *(*cit) << std::endl;
    --cit;
    std::cout << *(*cit) << std::endl;*/

    Contenitore<item*>Q(NULL,NULL);
    item * ff = new cardGame("unoc","unoc",5,"tgcs",true,11,false);
    item * fg = new cardGame("duec","duec",5,"tgcs",true,11,false);
    item * fh = new cardGame("trec","trec",5,"tgcs",true,11,false);
    item * fj = new cardGame("qua","qua",5,"tgcs",true,11,false);
    Q.PushEnd(ff);
    Contenitore<item*>::Iterator it = Q.begin();
    std::cout << *(*it) << std::endl;
    delete(*it);
    it=Q.erase(it);
    if(it == Q.end()){
        std::cout << "VERO" << std::endl;
    }
    Contenitore<item*>::Iterator it2 = Q.begin();
    if(it2 == Q.end()){
        std::cout << "VERO" << std::endl;
    }
    Q.PushEnd(fg);
    Contenitore<item*>::Iterator it3 = Q.begin();
    std::cout << *(*it3) << std::endl;
}
