#include <iostream>
#include <stdio.h>
#include <string>
#include <sqlite3.h>
#include <tntdb/connection.h>
#include <tntdb/connect.h>
#include <tntdb/statement.h>
#include "functions.h"
#include "apiario.h"
using namespace std;

/** \brief Inizializza il database se è vuoto
 *
 * \param db tntdb::Connection il database
 * \return tntdb::Connection il database
 *
 */
tntdb::Connection InizializzaDB(tntdb::Connection db)
{
    try
    {
        db.execute("CREATE TABLE TipiTrattamento(ID INT PRIMARY KEY NOT NULL, NomeTrattamento TEXT NOT NULL, Descrizione TEXT NOT NULL, Posologia TEXT NOT NULL)");
        db.execute("CREATE TABLE Apiari(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, Posizione TEXT)");
        db.execute("CREATE TABLE TipiArnia(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, NTelaini INT NOT NULL)");
        db.execute("CREATE TABLE Razze(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL)");
        db.execute("CREATE TABLE Provenienze(ID INT PRIMARY KEY NOT NULL, Provenienza TEXT NOT NULL)");
        db.execute("CREATE TABLE StatoFamiglia(ID INT PRIMARY KEY NOT NULL, StatoFamiglia TEXT NOT NULL)");
        db.execute("CREATE TABLE Nutrizioni(ID INT PRIMARY KEY NOT NULL, Nutrizione TEXT NOT NULL)");
        db.execute("CREATE TABLE ScopiNutrizione(ID INT PRIMARY KEY NOT NULL, Scopo TEXT NOT NULL)");
        db.execute("CREATE TABLE Alveari(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, Apiario INT NOT NULL, DataCreazione INT NOT NULL, Descrizione TEXT, Razza INT NOT NULL, Colore TEXT, TipoArnia INT NOT NULL, Provenienza INT NOT NULL, AnnoRegina INT NOT NULL, StatoFamiglia INT NOT NULL, Posizione INT NOT NULL, FOREIGN KEY(Apiario) REFERENCES Apiari(ID), FOREIGN KEY(Razza) REFERENCES Razze(ID), FOREIGN KEY(TipoArnia) REFERENCES TipiArnia(ID), FOREIGN KEY(Provenienza) REFERENCES Provenienze(ID), FOREIGN KEY(StatoFamiglia) REFERENCES StatoFamiglia(ID))");
        db.execute("CREATE TABLE TrattamentiFitosanitari(ID INT PRIMARY KEY NOT NULL, Data INT NOT NULL, Cassetta INT NOT NULL, Tipo TEXT NOT NULL, Dosi TEXT NOT NULL, FinoAl TEXT NOT NULL, FOREIGN KEY(Cassetta) REFERENCES Alveari(ID))");
        db.execute("CREATE TABLE Materiali(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, Descrizione TEXT NOT NULL, Quantita TEXT NOT NULL)");
        db.execute("CREATE TABLE Clienti(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, Cognome TEXT, RagioneSociale TEXT, Indirizzo TEXT, CAP TEXT, Citta TEXT, Provincia TEXT, Telefono TEXT, Fax TEXT, Cellulare TEXT, Email TEXT, CFPIVA TEXT, Note TEXT)");
        db.execute("CREATE TABLE Entrate(ID INT PRIMARY KEY NOT NULL, Data INT NOT NULL, Cliente INT NOT NULL, Descrizione TEXT NOT NULL, Imponibile REAL NOT NULL, IVA REAL NOT NULL, Importo REAL NOT NULL, FOREIGN KEY(Cliente) REFERENCES Clienti(ID))");
        db.execute("CREATE TABLE Fornitori(ID INT PRIMARY KEY NOT NULL, RagioneSociale TEXT NOT NULL, Nome TEXT, Cognome TEXT, Indirizzo TEXT NOT NULL, CAP TEXT NOT NULL, Citta TEXT NOT NULL, Provincia TEXT NOT NULL, Telefono TEXT, Fax TEXT, Email TEXT, CFPIVA TEXT NOT NULL, Note TEXT)");
        db.execute("CREATE TABLE Spese(ID INT PRIMARY KEY NOT NULL, Data INT NOT NULL, Descrizione TEXT NOT NULL, Fornitore INT NOT NULL, Imponibile REAL NOT NULL, IVA REAL NOT NULL, Importo REAL NOT NULL, FOREIGN KEY(Fornitore) REFERENCES Fornitori(ID))");
        db.execute("CREATE TABLE Versioni (ID INT PRIMARY KEY NOT NULL, Versione TEXT NOT NULL);");
        db.execute("INSERT INTO Versioni(ID,Versione) VALUES (0,0.1);");
        db.execute("INSERT INTO Clienti(ID, Nome, Cognome, RagioneSociale, Indirizzo, CAP, Citta, Provincia, Telefono, Fax, Cellulare, Email, CFPIVA, Note) VALUES (0, 'Generico', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)");
        db.execute("INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(0, 'Assente'); INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(1,'Candito');INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(2,'Candito con polline');INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(3,'Sciroppo');INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(4,'Sciroppo con Apiherb')");
        db.execute("INSERT INTO ScopiNutrizione(ID, Scopo) VALUES(0,'Emergenza');INSERT INTO ScopiNutrizione(ID, Scopo) VALUES(1,'Invernale')");
        db.execute("INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (0, 'Critico');INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (1, 'Insufficiente');INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (2, 'Sufficiente');INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (3, 'Buono');INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (4, 'Ottimo')");
        db.execute("INSERT INTO Razze(ID,Nome) VALUES (0, 'Apis Mellifera Ligustica');INSERT INTO Razze(ID,Nome) VALUES (1, 'Apis Mellifera Carnica');INSERT INTO Razze(ID,Nome) VALUES (2, 'Apis Mellifera Sicula')");
        db.execute("INSERT INTO Provenienze(ID, Provenienza) VALUES (0, 'Sciame Acquistato');INSERT INTO Provenienze(ID, Provenienza) VALUES (1, 'Sciame Naturale');INSERT INTO Provenienze(ID, Provenienza) VALUES (2, 'Sciame Naturale');INSERT INTO Provenienze(ID, Provenienza) VALUES (3, 'Divisione da famiglia')");
        db.execute("INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (0, 'D.B. 6', 6);INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (1, 'D.B. 8', 8);INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (2, 'D.B. 10', 10);INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (3, 'D.B. 12', 12);INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (4, 'Polistirolo 6', 6);INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (5, 'Pigliasciami 6', 6)");
        db.execute("INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione, Posologia) VALUES (0, 'Apiguard', 'Timolo in Gel', 'Due cicli a 15 giorni di distanza');INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione, Posologia) VALUES (1, 'ApiLifeVar', 'Timolo in spugne', 'Quattro cicli a 7 giorni di distanza');INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione, Posologia) VALUES (2, 'ApiBioxal gocciolato', 'Acido Ossalico gocciolato', 'Due cicli da 5ml a telaino ogni 21 giorni')");
    }
    catch (const std::exception&e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    return db;
}

/** \brief Apre il database test.db
 *
 * \return tntdb::Connection il puntatore al database
 * \todo implementare la scelta del file
 */
tntdb::Connection ApriDatabase()
{
//    //TODO implementare la scelta del file
    tntdb::Connection db;
    try
    {
        db=tntdb::connect("sqlite:test.db");
    }
    catch(const std::exception&e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    return db;
}

/** \brief Stampa un messaggio di lavori in corso
 *
 */
void WIP()
{
    cout << "Lavori in corso" << endl;
}

/** \brief Amministra gli alveari
 *
 */
void AmministrazioneAlveari()
{
    int scelta;
    do
    {
        cout << "1 - Aggiungi un alveare" << endl;
        cout << "2 - Modifica un alveare" << endl;
        cout << "3 - Elimina un alveare" << endl;
        cout << "4 - Visualizza gli alveari" << endl;
        cout << "0 - Torna al menu principale" << endl;
        cout << "Scelta -> ";
        cin >> scelta;
        switch(scelta)
        {
        case 1:
            WIP();
            break;
        case 2:
            WIP();
            break;
        case 3:
            WIP();
            break;
        case 4:
            WIP();
            break;
        }
    }
    while(scelta !=0);
    cout << endl << endl;
}

/** \brief Menu di amministrazione degli apiari
 *
 * \param db tntdb::Connection il database
 * \return tntdb::Connection il database
 *
 */
tntdb::Connection AmministrazioneApiari(tntdb::Connection db)
{
    int scelta;
    Apiario apiario;
    do
    {
        cout << "1 - Aggiungi un apiario" << endl;
        cout << "2 - Modifica un apiario" << endl;
        cout << "3 - Elimina un apiario" << endl;
        cout << "4 - Visualizza tutti gli apiari" << endl;
        cout << "0 - Torna al menu principale" << endl;
        cout << "Scelta -> ";
        cin >> scelta;
        switch(scelta)
        {
        case 1:
            db=apiario.Aggiungi(db);
            break;
        case 2:
            db=apiario.Modifica(db);
            break;
        case 3:
            db=apiario.Elimina(db);
            break;
        case 4:
            apiario.Visualizza(db);
            break;
        }
    }
    while(scelta !=0);
    cout << endl << endl;
    return db;
}

/** \brief Amministra le visita
 *
 */
void AmministrazioneVisite()
{
    int scelta;
    do{
        cout << "1 - Aggiungi una visita" << endl;
        cout << "2 - Modifica una visita" << endl;
        cout << "3 - Elimina una visita" << endl;
        cout << "4 - Visualizza tutte le visite" << endl;
        cout << "0 - Torna al menu principale" << endl;
        cout << "Scelta -> ";
        cin >> scelta;
        switch(scelta)
        {
        case 1:
            WIP();
            break;
        case 2:
            WIP();
            break;
        case 3:
            WIP();
            break;
        case 4:
            WIP();
            break;
        }
    }while(scelta!=0);
    cout << endl << endl;
}

/** \brief Amministra gli interventi fitosanitari
 *
 */
void AmministrazioneInterventi()
{
    int scelta;
    do{
        cout << "1 - Aggiungi un intervento" << endl;
        cout << "2 - Modifica un intervento" << endl;
        cout << "3 - Elimina un intervento" << endl;
        cout << "4 - Visualizza tutti gli interventi" << endl;
        cout << "0 - Torna al menu principale" << endl;
        cout << "Scelta -> ";
        cin >> scelta;
        switch(scelta)
        {
        case 1:
            WIP();
            break;
        case 2:
            WIP();
            break;
        case 3:
            WIP();
            break;
        case 4:
            WIP();
            break;
        }
    }while(scelta!=0);
    cout << endl << endl;
}

void AmministrazioneMagazzino(){
        int scelta;
    do{
        cout << "1 - Aggiungi un materiale" << endl;
        cout << "2 - Modifica un materiale" << endl;
        cout << "3 - Elimina un materiale" << endl;
        cout << "4 - Visualizza tutti i materiali" << endl;
        cout << "0 - Torna al menu principale" << endl;
        cout << "Scelta -> ";
        cin >> scelta;
        switch(scelta)
        {
        case 1:
            WIP();
            break;
        case 2:
            WIP();
            break;
        case 3:
            WIP();
            break;
        case 4:
            WIP();
            break;
        }
    }while(scelta!=0);
    cout << endl << endl;
}
