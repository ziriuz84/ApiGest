#include <iostream>
#include <string>
#include <KompexSQLiteDatabase.h>
#include <KompexSQLiteStatement.h>
#include "functions.h"
//using namespace std;


int main()
{
    int scelta;
    Kompex::SQLiteDatabase *db=ApriDatabase();
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
    float ntabelle;
    ntabelle=st->SqlAggregateFuncResult("select count(*) from sqlite_master;");
    std::cout << ntabelle;
    if(ntabelle<1)
    {
        std::cout << 0 << std::endl;
        db=InizializzaDB(db);
    }
    else
    {
        std::cout << 1 << std::endl;
    }
    do
    {
        std::cout << "ApiGest 0.1" << std::endl;
        std::cout << "1 - Amministrazione Alveari"<<std::endl;
        std::cout << "2 - Amministrazione Apiari"<<std::endl;
        std::cout << "3 - Amministrazione Visite"<<std::endl;
        std::cout << "4 - Amministrazione Interventi Fitosanitari"<<std::endl;
        std::cout << "5 - Amministrazione Magazzino" << std::endl;
        std::cout << "0 - Esci"<<std::endl;
        std::cout << "Scelta -> ";
        std::cin >> scelta;

        switch (scelta)
        {
        case 1:
            db=AmministrazioneAlveari(db);
            break;
        case 2:
            db=AmministrazioneApiari(db);
            break;
        case 3:
            AmministrazioneVisite();
            break;
        case 4:
            AmministrazioneInterventi();
            break;
        case 5:
            AmministrazioneMagazzino();
            break;
        }
    }
    while (scelta!=0);
    return 0;
}

