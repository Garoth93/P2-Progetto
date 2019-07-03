#include <QApplication>

#include "physicalgame.h"
#include "virtualgame.h"
#include "cardgame.h"
#include "contenitore.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller w(nullptr);
    w.show();

    return a.exec();
}

/*int main()
{
    Contenitore<const itemBase*>S(nullptr,nullptr);
    const itemBase * cff = new cardGame("uno","unouno",5,"tgcs",true,11,false);
    const itemBase * cfg = new cardGame("due","duedue",5,"tgcs",true,11,false);
    S.PushEnd(cff);
    S.PushBegin(cfg);
    Contenitore<const itemBase*>::Constiterator cit = S.cbegin();
    std::cout << *(*cit) << std::endl;
    ++cit;
    std::cout << *(*cit) << std::endl;
    --cit;
    std::cout << *(*cit) << std::endl;

    Contenitore<const item*>Q(nullptr,nullptr);
    const item * ff = new cardGame("unoc","unoc",5,"tgcs",true,11,false);
    const item * fg = new cardGame("duec","duec",5,"tgcs",true,11,false);
    const item * fh = new cardGame("trec","trec",5,"tgcs",true,11,false);
    const item * fj = new cardGame("qua","qua",5,"tgcs",true,11,false);
    Q.PushEnd(ff);
    Contenitore<const item*>::Iterator it = Q.begin();
    std::cout << *(*it) << std::endl;
    delete(*it);
    it=Q.erase(it);
    if(it == Q.end()){
        std::cout << "VERO" << std::endl;
    }
    Contenitore<const item*>::Iterator it2 = Q.begin();
    if(it2 == Q.end()){
        std::cout << "VERO" << std::endl;
    }
    Q.PushEnd(fg);
    Contenitore<const item*>::Iterator it3 = Q.begin();
    std::cout << *(*it3) << std::endl;
    Q.PushEnd(fh);
    ++it3;
    std::cout << *(*it3) << std::endl;
    delete(*it3);
    it3=Q.erase(it3);
    std::cout << *(*it3) << std::endl;
    const cardGame* dp = dynamic_cast<const cardGame*>((*it3));
    if(dp){
        std::cout << (*dp) << std::endl;
    }
    std::cout << (*it3)->getTipo() << std::endl;
    const item * aa = new cardGame("copia","copia",5,"tgcs",true,11,false);
    const item * bb = new cardGame("copia","",5,"",false,11,false);
    if(*aa == *bb){
        std::cout << "uguali" << std::endl;
    }
    if(*aa != *bb){
       std::cout << "diversi" << std::endl;
    }
}*/
