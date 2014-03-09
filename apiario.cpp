#include "apiario.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <tntdb/connection.h>
#include <tntdb/statement.h>
#include "functions.h"
using namespace std;

Apiario::Apiario()
{
    //ctor
}

Apiario::~Apiario()
{
    //dtor
}

tntdb::Connection Apiario::Aggiungi(tntdb::Connection db)
{
    cout << "ID -> ";
    cin >> ID;
//    printf("%d %d", ID, &ID);;
    cout << "Nome -> ";
    cin >> Nome;
    cout << "Posizione -> ";
    cin >> Posizione;
    string sql;
    sql = "INSERT INTO Apiari(ID,Nome,Posizione) VALUES ";
    sql=sql+"("+ID+","+Nome+","+Posizione+");";
    db=EseguiQuery(db, sql.c_str());
    tntdb::Statement st=db.prepare("INSERT INTO Apiari(ID,Nome,Posizione) VALUES (:v1, :v2, :v3)");
    st.setString("v1",ID).setString("v2", Nome).setString("v3",Posizione).execute();
    cout << 11 << endl;
    return db;
}

void Apiario::Elimina()
{
    //Elimina
}

void Apiario::Modifica()
{
    //Modifica
}

void Apiario::Visualizza()
{
    //Visualizza
}
