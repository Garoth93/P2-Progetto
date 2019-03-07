//#include "mainwindow.h"
//#include <QApplication>

#include "physicalgame.h"
#include "virtualgame.h"
#include "cardgame.h"

/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}*/

int main()
{
     physicalGame *asd=new physicalGame("prova","prova",1000,"prova","prova");
     physicalGame asd2("","",1000,"prova","prova");
     std::cout << asd << std::endl;
     virtualGame dsa("dioculo","ps4",11,"steam",true);
     std::cout << dsa << std::endl;
     cardGame dsaa("dioculo","ps4",11,"tgcs",true,11,false);
     std::cout << dsaa;

     item * ff = new cardGame("","",5,"tgcs",true,11,false);
     cardGame cdue("drago alato","konami",5,"tgcs",true,11,false);

     if(*ff == cdue){
         std::cout<< std::endl << "sono uguali";
     }else{
         std::cout<< std::endl << "non sono uguali";
     }
}
