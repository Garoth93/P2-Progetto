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
     physicalGame asd("dioculo","ps4",23,"ps4","ps4");
     std::cout << asd << std::endl;
     virtualGame dsa("dioculo","ps4",11,"steam",true);
     std::cout << dsa << std::endl;
     cardGame dsaa("dioculo","ps4",11,"tgcs",true,11,false);
     std::cout << dsaa;
}
