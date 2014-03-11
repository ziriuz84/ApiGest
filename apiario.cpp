#include "apiario.h"
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <tntdb/connection.h>
#include <tntdb/statement.h>
#include <tntdb/result.h>
#include <tntdb/row.h>
#include <tntdb/value.h>
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

/** \brief Aggiunge un apiario al database
 *
 * \param db tntdb::Connection il database
 * \return tntdb::Connection il database
 *
 */
tntdb::Connection Apiario::Aggiungi(tntdb::Connection db)
{
    tntdb::Value v=db.selectValue("select count(*) from Apiari");
    ID=v.getUnsigned();
    cout << "Nome -> ";
    cin >> Nome;
    cout << "Posizione -> ";
    cin >> Posizione;
    tntdb::Statement st=db.prepare("INSERT INTO Apiari(ID,Nome,Posizione) VALUES (:v1, :v2, :v3)");
    st.set("v1",ID).set("v2", Nome).set("v3",Posizione).execute();
    return db;
}

/** \brief Elimina un apiario dal database
 *
 * \param db tntdb::Connection il database
 * \return tntdb::Connection il database
 *
 */
tntdb::Connection Apiario::Elimina(tntdb::Connection db)
{
    return db;
}

/** \brief Modifica un apiario del database
 *
 * \param db tntdb::Connection il database
 * \return tntdb::Connection il database
 *
 */
tntdb::Connection Apiario::Modifica(tntdb::Connection db)
{
    return db;
}

/** \brief Visualizza tutti gli apiari del database
 *
 * \param db tntdb::Connection il database
 *
 */
void Apiario::Visualizza(tntdb::Connection db)
{
    tntdb::Result result=db.select("select ID, Nome, Posizione from Apiari");
    cout << "|" << setw(4) << "ID" << "|" << setw(15) << "Nome" << "|" << setw(20) << "Posizione" << "|" << endl;
    cout << "|----|---------------|--------------------|" << endl;
    for (tntdb::Result::const_iterator it =result.begin(); it!=result.end(); ++it)
    {
        tntdb::Row row=*it;
        string id;
        string nome;
        string posizione;
        row[0].get(id);
        row[1].get(nome);
        row[2].get(posizione);
        cout << "|" << setw(4) << id << "|" << setw(15) << nome << "|" << setw(20) << posizione << "|" << endl;
    }
}
