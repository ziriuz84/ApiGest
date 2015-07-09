#include "apiario.h"
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include "functions.h"
using namespace std;
/*
Apiario::Apiario()
{
    //ctor
}

Apiario::~Apiario()
{
    //dtor
}*/

/** \brief Aggiunge un apiario al database
 *
 * \param db Kompex::SQLiteDatabase il database
 * \return Kompex::SQLiteDatabase il database
 *
 *//*
Kompex::SQLiteDatabase *Apiario::Aggiungi(Kompex::SQLiteDatabase *db)
{
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
    if (st->SqlAggregateFuncResult("select count(*) from Apiari;")<1)
    {
        ID=0;
    }
    else
    {
        ID=st->SqlAggregateFuncResult("select ID from Apiari where id = (select MAX(ID) from Apiari);");
        ID++;
    }
    cout << "Nome -> ";
    cin >> Nome;
    cout << "Posizione -> ";
    cin >> Posizione;
    try
    {
        st->Sql("INSERT INTO Apiari(ID,Nome,Posizione) VALUES (?, ?, ?)");
        st->BindInt(1,ID);
        st->BindString(2,Nome);
        st->BindString(3,Posizione);
        st->ExecuteAndFree();
    }
    catch(Kompex::SQLiteException &exception)
    {
        std::cerr << "Exception Occured: " << exception.GetString();
        exception.Show();
    }
    return db;
}*/

/** \brief Elimina un apiario dal database
 *
 * \param db Kompex::SQLiteDatabase *il database
 * \return Kompex::SQLiteDatabase *il database
 *
 *//*
Kompex::SQLiteDatabase *Apiario::Elimina(Kompex::SQLiteDatabase *db)
{
    Visualizza(db);
    cout << "Seleziona l'ID dell'apiario da eliminare" << endl << "ID -> ";
    cin >> ID;
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
    st->Sql("DELETE FROM Apiari WHERE ID = ?");
    st->BindInt(1,ID);
    st->ExecuteAndFree();
    return db;
}*/

/** \brief Modifica un apiario del database
 *
 * \param db Kompex::SQLiteDatabase *il database
 * \return Kompex::SQLiteDatabase *il database
 *
 *//*
Kompex::SQLiteDatabase *Apiario::Modifica(Kompex::SQLiteDatabase *db)
{
    Visualizza(db);
    cout << "Seleziona l'ID dell'apiario da modificare" << endl << "ID -> ";
    cin >> ID;
    cout << "Nome -> ";
    cin >> Nome;
    cout << "Posizione -> ";
    cin >> Posizione;
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
    st->Sql("update Apiari set Nome = ?, Posizione = ? where id = ?");
    st->BindString(1,Nome);
    st->BindString(2,Posizione);
    st->BindInt(3,ID);
    st->ExecuteAndFree();
    return db;
}*/

/** \brief Visualizza tutti gli apiari del database
 *
 * \param db Kompex::SQLiteDatabase *il database
 *
 *//*
void Apiario::Visualizza(Kompex::SQLiteDatabase *db)
{
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
//    st->Sql("select ID, Nome, Posizione from Apiari;");
//    st->Execute();
//    cout << "|" << setw(4) << "ID" << "|" << setw(15) << "Nome" << "|" << setw(20) << "Posizione" << "|" << endl;
//    cout << "|----|---------------|--------------------|" << endl;
//    while (st->FetchRow())
//    {
//        cout << "|" << setw(4) << st->GetColumnInt("ID") << "|" << setw(15) << st->GetColumnString("Nome") << "|" << setw(20) << st->GetColumnString("Posizione") << "|" << endl;
//    }
//    st->FreeQuery();
    cout << endl << endl;
    st->GetTable("select ID, Nome, Posizione from Apiari;");
    cout << endl << endl;
}
*/
