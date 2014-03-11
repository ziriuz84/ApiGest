#include <iostream>
#include <string>
#include "functions.h"
#include <tntdb/connection.h>
#include <tntdb/connect.h>
#include <tntdb/result.h>
#include <tntdb/row.h>
#include <tntdb/value.h>
//using namespace std;


int main()
{
    int scelta;
    tntdb::Connection db=ApriDatabase();
    tntdb::Value v=db.selectValue("select count(*) from sqlite_master");
    if(v.getUnsigned()<1)
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
        std::cout << "0 - Esci"<<std::endl;
        std::cout << "Scelta -> ";
        std::cin >> scelta;

        switch (scelta)
        {
        case 1:
            AmministrazioneAlveari();
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
        }
    }
    while (scelta!=0);
    return 0;
}

