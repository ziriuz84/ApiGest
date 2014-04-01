#include <iostream>
#include <stdio.h>
#include <string>
#include <KompexSQLiteDatabase.h>
#include <KompexSQLiteException.h>
#include <KompexSQLiteStatement.h>
#include "functions.h"
#include "apiario.h"
#include "alveare.h"
using namespace std;

/** \brief Inizializza il database se è vuoto
 *
 * \param db Kompex::SQLiteDatabase *il database
 * \return Kompex::SQLiteDatabase *il database
 *
 */
Kompex::SQLiteDatabase *InizializzaDB(Kompex::SQLiteDatabase *db)
{
    try
    {
        Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
        st->SqlStatement("CREATE TABLE TipiTrattamento(ID INT PRIMARY KEY NOT NULL, NomeTrattamento TEXT NOT NULL, Descrizione TEXT NOT NULL, Posologia TEXT NOT NULL)");
        st->SqlStatement("CREATE TABLE Apiari(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, Posizione TEXT)");
        st->SqlStatement("CREATE TABLE TipiArnia(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, NTelaini INT NOT NULL)");
        st->SqlStatement("CREATE TABLE Razze(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL)");
        st->SqlStatement("CREATE TABLE Provenienze(ID INT PRIMARY KEY NOT NULL, Provenienza TEXT NOT NULL)");
        st->SqlStatement("CREATE TABLE StatoFamiglia(ID INT PRIMARY KEY NOT NULL, StatoFamiglia TEXT NOT NULL)");
        st->SqlStatement("CREATE TABLE Nutrizioni(ID INT PRIMARY KEY NOT NULL, Nutrizione TEXT NOT NULL)");
        st->SqlStatement("CREATE TABLE ScopiNutrizione(ID INT PRIMARY KEY NOT NULL, Scopo TEXT NOT NULL)");
        st->SqlStatement("CREATE TABLE Alveari(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, Apiario INT NOT NULL, GiornoCreazione INT NOT NULL, MeseCreazione INT NOT NULL, AnnoCreazione INT NOT NULL, Descrizione TEXT, Razza INT NOT NULL, Colore TEXT, TipoArnia INT NOT NULL, Provenienza INT NOT NULL, AnnoRegina INT NOT NULL, StatoFamiglia INT NOT NULL, Posizione INT NOT NULL, FOREIGN KEY(Apiario) REFERENCES Apiari(ID), FOREIGN KEY(Razza) REFERENCES Razze(ID), FOREIGN KEY(TipoArnia) REFERENCES TipiArnia(ID), FOREIGN KEY(Provenienza) REFERENCES Provenienze(ID), FOREIGN KEY(StatoFamiglia) REFERENCES StatoFamiglia(ID))");
        st->SqlStatement("CREATE TABLE TrattamentiFitosanitari(ID INT PRIMARY KEY NOT NULL, Data INT NOT NULL, Cassetta INT NOT NULL, Tipo TEXT NOT NULL, Dosi TEXT NOT NULL, FinoAl TEXT NOT NULL, FOREIGN KEY(Cassetta) REFERENCES Alveari(ID))");
        st->SqlStatement("CREATE TABLE Materiali(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, Descrizione TEXT NOT NULL, Quantita TEXT NOT NULL)");
        st->SqlStatement("CREATE TABLE Clienti(ID INT PRIMARY KEY NOT NULL, Nome TEXT NOT NULL, Cognome TEXT, RagioneSociale TEXT, Indirizzo TEXT, CAP TEXT, Citta TEXT, Provincia TEXT, Telefono TEXT, Fax TEXT, Cellulare TEXT, Email TEXT, CFPIVA TEXT, Note TEXT)");
        st->SqlStatement("CREATE TABLE Entrate(ID INT PRIMARY KEY NOT NULL, Data INT NOT NULL, Cliente INT NOT NULL, Descrizione TEXT NOT NULL, Imponibile REAL NOT NULL, IVA REAL NOT NULL, Importo REAL NOT NULL, FOREIGN KEY(Cliente) REFERENCES Clienti(ID))");
        st->SqlStatement("CREATE TABLE Fornitori(ID INT PRIMARY KEY NOT NULL, RagioneSociale TEXT NOT NULL, Nome TEXT, Cognome TEXT, Indirizzo TEXT NOT NULL, CAP TEXT NOT NULL, Citta TEXT NOT NULL, Provincia TEXT NOT NULL, Telefono TEXT, Fax TEXT, Email TEXT, CFPIVA TEXT NOT NULL, Note TEXT)");
        st->SqlStatement("CREATE TABLE Spese(ID INT PRIMARY KEY NOT NULL, Data INT NOT NULL, Descrizione TEXT NOT NULL, Fornitore INT NOT NULL, Imponibile REAL NOT NULL, IVA REAL NOT NULL, Importo REAL NOT NULL, FOREIGN KEY(Fornitore) REFERENCES Fornitori(ID))");
        st->SqlStatement("CREATE TABLE Versioni (ID INT PRIMARY KEY NOT NULL, Versione TEXT NOT NULL);");
        st->SqlStatement("CREATE TABLE Visite (ID INT PRIMARY KEY NOT NULL, Cassetta INT NOT NULL, Giorno INT NOT NULL, Mese INT NOT NULL, Anno INT NOT NULL, Ora INT, Minuti INT, Meteo TEXT, Temperatura REAL, TelainiTotali INT NOT NULL, TelainiOccupati INT NOT NULL, TelainiCovata INT, CelleReali INT, Melari BOOL NOT NULL, Regina BOOL, CovataFresca BOOL, TipoCovata TEXT, Comportamento TEXT NOT NULL, LavoriEffettuati TEXT NOT NULL, Nutrizione INT NOT NULL, ScopoNutrizione INT, VarroaCassetto BOOL, VarroaApi BOOL, ConteggioVarroa INT, Virosi BOOL, TipoVirosi TEXT, LarveMorte BOOL, ApiMorteEntrata BOOL, PeriodoProssimoLavoro1 TEXT, ProssimoLavoro1 TEXT, PeriodoProssimoLavoro2 TEXT, ProssimoLavoro2 TEXT, PeriodoProssimoLavoro3 TEXT, ProssimoLavoro3 TEXT, Note TEXT, Fioriture TEXT, StatoFamiglia INT NOT NULL, VisitaCompleta BOOL NOT NULL, FOREIGN KEY(Cassetta) REFERENCES Alveari(ID), FOREIGN KEY(Nutrizione) REFERENCES Nutrizioni(ID), FOREIGN KEY(ScopoNutrizione) REFERENCES ScopiNutrizione(ID), FOREIGN KEY(StatoFamiglia) REFERENCES StatoFamiglia(ID));");
        st->SqlStatement("INSERT INTO Versioni(ID,Versione) VALUES (0,0.1);");
        st->SqlStatement("INSERT INTO Clienti(ID, Nome, Cognome, RagioneSociale, Indirizzo, CAP, Citta, Provincia, Telefono, Fax, Cellulare, Email, CFPIVA, Note) VALUES (0, 'Generico', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL)");
        st->SqlStatement("INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(0, 'Assente');");
        st->SqlStatement(" INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(1,'Candito');");
        st->SqlStatement("INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(2,'Candito con polline');");
        st->SqlStatement("INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(3,'Sciroppo');");
        st->SqlStatement("INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(4,'Sciroppo con Apiherb')");
        st->SqlStatement("INSERT INTO ScopiNutrizione(ID, Scopo) VALUES(0,'Emergenza');");
        st->SqlStatement("INSERT INTO ScopiNutrizione(ID, Scopo) VALUES(1,'Invernale')");
        st->SqlStatement("INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (0, 'Critico');");
        st->SqlStatement("INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (1, 'Insufficiente');");
        st->SqlStatement("INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (2, 'Sufficiente');");
        st->SqlStatement("INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (3, 'Buono');");
        st->SqlStatement("INSERT INTO StatoFamiglia(ID,StatoFamiglia) VALUES (4, 'Ottimo')");
        st->SqlStatement("INSERT INTO Razze(ID,Nome) VALUES (0, 'Apis Mellifera Ligustica');");
        st->SqlStatement("INSERT INTO Razze(ID,Nome) VALUES (1, 'Apis Mellifera Carnica');");
        st->SqlStatement("INSERT INTO Razze(ID,Nome) VALUES (2, 'Apis Mellifera Sicula')");
        st->SqlStatement("INSERT INTO Provenienze(ID, Provenienza) VALUES (0, 'Sciame Acquistato');");
        st->SqlStatement("INSERT INTO Provenienze(ID, Provenienza) VALUES (1, 'Sciame Naturale');");
        st->SqlStatement("INSERT INTO Provenienze(ID, Provenienza) VALUES (2, 'Sciame Naturale');");
        st->SqlStatement("INSERT INTO Provenienze(ID, Provenienza) VALUES (3, 'Divisione da famiglia')");
        st->SqlStatement("INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (0, 'D.B. 6', 6);");
        st->SqlStatement("INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (1, 'D.B. 8', 8);");
        st->SqlStatement("INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (2, 'D.B. 10', 10);");
        st->SqlStatement("INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (3, 'D.B. 12', 12);");
        st->SqlStatement("INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (4, 'Polistirolo 6', 6);");
        st->SqlStatement("INSERT INTO TipiArnia(ID, Nome, NTelaini) VALUES (5, 'Pigliasciami 6', 6)");
        st->SqlStatement("INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione, Posologia) VALUES (0, 'Apiguard', 'Timolo in Gel', 'Due cicli a 15 giorni di distanza');");
        st->SqlStatement("INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione, Posologia) VALUES (1, 'ApiLifeVar', 'Timolo in spugne', 'Quattro cicli a 7 giorni di distanza');");
        st->SqlStatement("INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione, Posologia) VALUES (2, 'ApiBioxal gocciolato', 'Acido Ossalico gocciolato', 'Due cicli da 5ml a telaino ogni 21 giorni')");
        st->FreeQuery();
    }
    catch (const std::exception&e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    return db;
}

/** \brief Apre il database test.db
 *
 * \return Kompex::SQLiteDatabase *il puntatore al database
 * \todo implementare la scelta del file
 */
Kompex::SQLiteDatabase *ApriDatabase()
{
//    //TODO implementare la scelta del file
//    string nomefile;
//    cout << "Inserisci il nome del file" << endl << "Nome -> ";
//    cin >> nomefile;
    Kompex::SQLiteDatabase *db;
    try
    {
        db=new Kompex::SQLiteDatabase("test.db", SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, 0);
    }
    catch(Kompex::SQLiteException &e)
    {
        std::cerr<<"\nException Occccurred"<<std::endl;
        e.Show();
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
Kompex::SQLiteDatabase *AmministrazioneAlveari(Kompex::SQLiteDatabase *db)
{
    int scelta;
    Alveare alveare;
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
            db=alveare.Aggiungi(db);
            break;
        case 2:
            db=alveare.Modifica(db);
            break;
        case 3:
            db=alveare.Elimina(db);
            break;
        case 4:
            alveare.Visualizza(db);
            break;
        }
    }
    while(scelta !=0);
    cout << endl << endl;
    return db;
}

/** \brief Menu di amministrazione degli apiari
 *
 * \param db Kompex::SQLiteDatabase *il database
 * \return Kompex::SQLiteDatabase *il database
 *
 */
Kompex::SQLiteDatabase *AmministrazioneApiari(Kompex::SQLiteDatabase *db)
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
    do
    {
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
    }
    while(scelta!=0);
    cout << endl << endl;
}

/** \brief Amministra gli interventi fitosanitari
 *
 */
void AmministrazioneInterventi()
{
    int scelta;
    do
    {
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
    }
    while(scelta!=0);
    cout << endl << endl;
}

void AmministrazioneMagazzino()
{
    int scelta;
    do
    {
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
    }
    while(scelta!=0);
    cout << endl << endl;
}

void RecuperaValore(Kompex::SQLiteDatabase *db,string titolo, string campo, string tabella, int id)
{

    Kompex::SQLiteStatement *st= new Kompex::SQLiteStatement(db);
    st->Sql("select ? from ? where ID=?;");
    string valore;
    try
    {
        st->BindString(1, campo);
        st->BindString(2,tabella);
        st->BindInt(3,id);
        st->Execute();
    }
    catch(const std::exception&e)
    {
        std::cerr<<e.what()<<std::endl;
    }
    while (st->FetchRow())
    {
        cout << titolo << ": " << st->GetColumnString(campo) << endl;
    }
    st->FreeQuery();
}

int Data2Secondi()
{
    int giorno, mese, anno, giorni, risultato;
    cout << "Inserisci la data" << endl;
    cout << "Giorno - > ";
    cin >> giorno;
    cout << "Mese -> ";
    cin >> mese;
    cout << "Anno -> ";
    cin >> anno;
    risultato=(anno-1970)*365*24*60*60;
    switch(mese)
    {
    case 1:
        risultato+=0;
        break;
    case 2:
        risultato+=31*24*60*60;
        break;
    case 3:
        risultato+=59*24*60*60;
        break;
    case 4:
        risultato+=90*24*60*60;
        break;
    case 5:
        risultato+=120*24*60*60;
        break;
    case 6:
        risultato+=151*24*60*60;
        break;
    case 7:
        risultato+=181*24*60*60;
        break;
    case 8:
        risultato+=212*24*60*60;
        break;
    case 9:
        risultato+=243*24*60*60;
        break;
    case 10:
        risultato+=273*24*60*60;
        break;
    case 11:
        risultato+=304*24*60*60;
        break;
    case 12:
        risultato+=334*24*60*60;
        break;
    }
    risultato+=giorno*24*60*60;
    return risultato;
}
