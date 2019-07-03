#include "modello.h"
#include <QSaveFile>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include <iostream>

//costruttore modello
modello::modello(std::string p):
    lista(new Contenitore<itemBase*>),
    Path(p),
    datiSalvati(true)
{}

//distruttore
modello::~modello(){delete lista;}

//FUNZIONI CHE RITORNANO DA QUELLE DENTRO IL CONTENITORE
//begin
Contenitore<itemBase*>::Iterator modello::mbegin(){
    return lista->begin();
}

//end
Contenitore<itemBase*>::Iterator modello::mend(){
    return lista->end();
}

//cbegin
Contenitore<itemBase*>::Constiterator modello::mcbegin() const{
    return lista->cbegin();
}

//mcend
Contenitore<itemBase*>::Constiterator modello::mcend() const{
    return lista->cend();
}

//melimina
Contenitore<itemBase*>::Iterator modello::melimina( Contenitore<itemBase*>::Iterator ite ){
    return lista->erase(ite);
}
//meliminanoi
void modello::meliminanoi(Contenitore<itemBase *>::Iterator itel){
    lista->erasenoi(itel);
}

//getlista
Contenitore<itemBase*>* modello::getlista() const{
    return lista;
}

//funzione di caricamete dati da xml
void modello::caricamento(){
    QFile fileSalvataggio(QString::fromStdString(Path));

    if(!fileSalvataggio.open(QIODevice::ReadOnly)) {
        qWarning() << "Non è stato possibile aprire il file" << fileSalvataggio.errorString();
        return ;
    }

    QXmlStreamReader lettore(&fileSalvataggio);//variabile lettore
    if(lettore.readNextStartElement()){
        if(lettore.name() == "root"){
            while(lettore.readNextStartElement()){
                const QXmlStreamAttributes attributo = lettore.attributes();

                std::string titolo = attributo.hasAttribute("titolo") ? attributo.value("titolo").toString().toStdString() : "";
                std::string casaProduttrice = attributo.hasAttribute("casaProduttrice") ? attributo.value("casaProduttrice").toString().toStdString() : "";
                double prezzoBase = attributo.hasAttribute("prezzoBase") ? attributo.value("prezzoBase").toDouble() : 0;

                itemBase* daInserire = nullptr;//why?

                if(lettore.name() == "VideogiocoFisico"){
                    std::string qualeConsole = attributo.hasAttribute("qualeConsole") ? attributo.value("qualeConsole").toString().toStdString() : "";
                    std::string edizione = attributo.hasAttribute("edizione") ? attributo.value("edizione").toString().toStdString() : "";

                    //chiamo il costrtuttore a videogioco fisico
                    daInserire = new physicalGame(titolo,casaProduttrice,prezzoBase,qualeConsole,edizione);

                } else if(lettore.name() == "VideogiocoVirtuale"){
                    std::string piattaForma = attributo.hasAttribute("piattaForma") ? attributo.value("piattaForma").toString().toStdString() : "";
                    bool seasonPass = attributo.hasAttribute("seasonPass") ? attributo.value("seasonPass").toString()=="true"? true : false : false;

                    //chiamo costrtuttore videogioco virtuale
                    daInserire = new virtualGame(titolo,casaProduttrice,prezzoBase,piattaForma,seasonPass);

                } else if(lettore.name() == "GiocoDiCarte"){
                    std::string espansione = attributo.hasAttribute("espansione") ? attributo.value("espansione").toString().toStdString() : "";
                    bool primaEdizione = attributo.hasAttribute("primaEdizione") ? attributo.value("primaEdizione").toString()=="true"? true: false : false;
                    int numeroCarte = attributo.hasAttribute("numeroCarte") ? attributo.value("numeroCarte").toInt() : 0;
                    bool starterDeck = attributo.hasAttribute("starterDeck") ? attributo.value("starterDeck").toString()=="true"? true: false : false;

                    //costruttore gioco di carte
                    daInserire = new cardGame(titolo,casaProduttrice,prezzoBase,espansione,primaEdizione,numeroCarte,starterDeck);
                }

                if(daInserire!=nullptr)//chiamo la mia pushback
                    //lista->insertBack(daInserire);
                    lista->PushEnd(daInserire);

                if(!lettore.isEndDocument())//elemento dopo
                    lettore.skipCurrentElement();
            }
        }
    }
    datiSalvati=true;
    fileSalvataggio.close();
}

//salvataggio dei dati nel file xml
void modello::salvataggio(){
    QSaveFile file(QString::fromStdString(Path));

    if(!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QXmlStreamWriter lettore(&file);

    lettore.setAutoFormatting(true); // Per leggibilità del file XML
    lettore.writeStartDocument();  // Scrive le intestazioni XML
    lettore.writeComment("!!!Non modificate");

    lettore.writeStartElement("root");

    Contenitore<itemBase*>::Constiterator it = mcbegin();
    //auto it = mcbegin();//iteratore automatico e lo setto a inizio del mio contenitore
    while(it != mcend()){
        const itemBase* daSalvare = *it;
        QString tipologiaOgg = QString::fromStdString(daSalvare->getTipo());
        /*controllo del gettipo*/
        if(tipologiaOgg == "physicalgame")//per videogioco fisico
            tipologiaOgg = "VideogiocoFisico";
        if(tipologiaOgg == "virtualgame")//per videogioco virtuale
            tipologiaOgg = "VideogiocoVirtuale";
        if(tipologiaOgg == "cardgame")//per videogioco di carte
            tipologiaOgg = "GiocoDiCarte";
        lettore.writeEmptyElement(tipologiaOgg);
        lettore.writeAttribute("titolo", QString::fromStdString(daSalvare->getTitolo()));
        lettore.writeAttribute("casaProduttrice", QString::fromStdString(daSalvare->getCasaProdruttrice()));
        lettore.writeAttribute("prezzoBase", QString("%1").arg(daSalvare->getPrezzoBase()));

        if(tipologiaOgg == "VideogiocoFisico"){
            const physicalGame* oggVideogioco = static_cast<const physicalGame*>(daSalvare);
            lettore.writeAttribute("qualeConsole", QString::fromStdString(oggVideogioco->getQualeConsole()));
            lettore.writeAttribute("edizione", QString::fromStdString(oggVideogioco->getEdizione()));
        } else if(tipologiaOgg == "VideogiocoVirtuale"){
            const virtualGame* oggGiocoVirtuale = static_cast<const virtualGame*>(daSalvare);
            lettore.writeAttribute("piattaForma", QString::fromStdString(oggGiocoVirtuale->getPiattaForma()));
            lettore.writeAttribute("seasonPass", oggGiocoVirtuale->getSeasonPass() ? "true" : "false");
        } else if(tipologiaOgg == "GiocoDiCarte"){
            const cardGame* oggGiocoCarte = static_cast<const cardGame*>(daSalvare);
            lettore.writeAttribute("espansione", QString::fromStdString(oggGiocoCarte->getEspansione()));
            lettore.writeAttribute("primaEdizione", oggGiocoCarte->getPrimaEdizione() ? "true" : "false");
            lettore.writeAttribute("numeroCarte", QString("%1").arg(oggGiocoCarte->getNumeroCarte()));
            lettore.writeAttribute("starterDeck", oggGiocoCarte->getStarterDeck() ? "true" : "false");
        }

        ++it;
    }

    lettore.writeEndElement();
    lettore.writeEndDocument();
    datiSalvati = true;
    file.commit();
}

//settare un nuovo percorso per io dati
void modello::setNuovoPercorso(std::string p){
    Path = p;
    delete lista;
    datiSalvati = false;
    lista = new Contenitore<itemBase*>();
}


