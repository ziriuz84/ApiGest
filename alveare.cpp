#include "alveare.h"

#include <iostream>
#include <iomanip>
#include <string>
#include <KompexSQLiteDatabase.h>
#include <KompexSQLiteStatement.h>
#include <KompexSQLiteException.h>
#include "functions.h"
using namespace std;

Alveare::Alveare()
{
    //ctor
}

Alveare::~Alveare()
{
    //dtor
}
Kompex::SQLiteDatabase *Alveare::Aggiungi(Kompex::SQLiteDatabase *db)
{
    int temp1;
    string tempstr;
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
    Kompex::SQLiteStatement *st2 = new Kompex::SQLiteStatement(db);
    Apiario apiario;
    if (st->SqlAggregateFuncResult("select count(*) from Alveari;")<1)
    {
        ID=0;
    }
    else
    {
        st->Sql("select ID from Alveari where id = (select MAX(ID) from Alveari);");
        st->Execute();
        ID=st->GetColumnInt("ID");
        ID++;
        st->FreeQuery();
    }
    try
    {
        st->Sql("INSERT INTO Alveari(ID, Nome, Apiario, GiornoCreazione, MeseCreazione, AnnoCreazione, Descrizione, Razza, Colore, TipoArnia, Provenienza, AnnoRegina, StatoFamiglia, Posizione) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
        st->BindInt(1, ID);
        cout << "Inserisci il nome dell'alveare" << endl << "Nome -> ";
        cin >> tempstr;
        st->BindString(2, tempstr);
        apiario.Visualizza(db);
        cout << "Scegli l'ID dell'apiario di appartenenza" << endl << "ID -> ";
        cin >> temp1;
        st->BindInt(3, temp1);
        cout << "Seleziona la data di creazione dell'alveare" << endl;
        cout << "Giorno ->";
        cin >> temp1;
        st->BindInt(4, temp1);
        cout << "Mese -> ";
        cin >> temp1;
        st->BindInt(5, temp1);
        cout << "Anno -> ";
        cin >> temp1;
        st->BindInt(6, temp1);
        cout << "Inserisci un'eventuale descrizione" << endl;
        cin >> tempstr;
        st->BindString(7, tempstr);
        st2->GetTable("select * from Razze;");
        st2->FreeQuery();
        cout << "Seleziona la razza" << endl << "ID -> ";
        cin >> temp1;
        st->BindInt(8, temp1);
        cout << "Inserisci il colore dell'arnia" << endl << "Colore -> ";
        cin >> tempstr;
        st->BindString(9, tempstr);
        st2->GetTable("select * from TipiArnia;");
        st2->FreeQuery();
        cout << "Seleziona l'ID del tipo di arnia corretto" << endl << "ID -> ";
        cin >> temp1;
        st->BindInt(10, temp1);
        st2->GetTable("select * from Provenienze;");
        st2->FreeQuery();
        cout << "Seleziona l'ID della provenienza corretta" << endl << "ID -> ";
        cin >> temp1;
        st->BindInt(11, temp1);
        cout << "Inserisci l'anno di nascita della regina" << endl << "Anno -> ";
        cin >> temp1;
        st->BindInt(12, temp1);
        st2->GetTable("select * from StatoFamiglia;");
        st2->FreeQuery();
        cout << "Dai un voto allo stato della famiglia [0-4]" << endl << "Voto -> ";
        cin >> temp1;
        st->BindInt(13, temp1);
        cout << "Indica la posizione dell'arnia nell'apiario" << endl << "Posizione -> ";
        cin >> temp1;
        st->BindInt(14, temp1);
        st->ExecuteAndFree();
    }
    catch (Kompex::SQLiteException &exception)
    {
        cout << exception.GetString();
    }
    return db;
}

Kompex::SQLiteDatabase *Alveare::Elimina(Kompex::SQLiteDatabase *db)
{
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
    int id;
    st->GetTable("select Alveari.ID, Alveari.Nome, Apiari.Nome from Alveari join Apiari on Apiari.id = Alveari.Apiario;");
    cout << "Seleziona l'ID dell'alveare da eliminare" << endl << "ID -> ";
    cin >> id;
    st->FreeQuery();
    st->Sql("DELETE FROM Alveari WHERE ID = ?;");
    st->BindInt(1,id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::Modifica(Kompex::SQLiteDatabase *db)
{
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
    Kompex::SQLiteStatement *st2 = new Kompex::SQLiteStatement(db);
    int id;
    st->GetTable("select Alveari.ID, Alveari.Nome, Apiari.Nome from Alveari join Apiari on Apiari.id = Alveari.Apiario;");
    cout << "Seleziona l'ID dell'alveare da modificare" << endl << "ID -> ";
    cin >> id;
// TODO (sirio#1#): Questa query da un errore. sqlite3_step ritorna un valore 100 che non dovrebbe, sembrerebbe non chiuda la riga
    try
    {
        st2->Sql("select Alveari.ID, Alveari.Nome, Apiari.Nome, Alveari.GiornoCreazione, Alveari.MeseCreazione, Alveari.AnnoCreazione, Alveari.Descrizione, Razze.Nome, Alveari.Colore, TipiArnia.Nome, Provenienze.Provenienza, Alveari.AnnoRegina, StatoFamiglia.StatoFamiglia, Alveari.Posizione from Alveari join Apiari on Apiari.id=Alveari.Apiario join Razze on Razze.ID=Alveari.Razza join TipiArnia on TipiArnia.id=Alveari.TipoArnia join Provenienze on Provenienze.id = Alveari.Provenienza join StatoFamiglia on StatoFamiglia.id=Alveari.StatoFamiglia where Alveari.ID = ?;");
        st2->BindInt(1,id);
        st2->Execute();
//        st->FreeQuery();
    }
    catch (Kompex::SQLiteException &e)
    {
        e.Show();
    }
    string a;
    cout << st2->FetchRow();
    while (st2->FetchRow())
    {
        cout << left << setw(20) << "ID" << ": " << st2->GetColumnInt(0) << endl;
        cout << setw(20) << "1 - Nome" << ": " << st2->GetColumnString(1) << endl;
        cout << setw(20) << "2 - Apiario" << ": " << st2->GetColumnString(2) << endl;
        cout << setw(20) << "3 - Creato il" << ": " << st2->GetColumnInt(3) << "/" << st2->GetColumnInt(4) << "/" << st2->GetColumnInt(5) << endl;
        cout << setw(20) << "4 - Descrizione" << ": " << st2->GetColumnString(6) << endl;
        cout << setw(20) << "5 - Razza" << ": " << st2->GetColumnString(7) << endl;
        cout << setw(20) << "6 - Colore" << ": " << st2->GetColumnString(8) << endl;
        cout << setw(20) << "7 - Tipo di Arnia" << ": " << st2->GetColumnString(9) << endl;
        cout << setw(20) << "8 - Provenienza" << ": " << st2->GetColumnString(10) << endl;
        cout << setw(20) << "9 - Anno Regina" << ": " << st2->GetColumnInt(11) << endl;
        cout << setw(20) << "10 - Stato della famiglia" << ": " << st2->GetColumnString(12) << endl;
        cout << setw(20) << "11 - Posizione" << ": " << st2->GetColumnInt(13) << endl;
    }
    cout << "Quale valore vuoi modificare?" << endl;
    cout << "Valore -> ";
    int valore;
    cin >> valore;
    Alveare alveare;
    switch(valore)
    {
    case 1:
        db=alveare.SetNome(db, st2->GetColumnInt(0));
        break;
    case 2:
        db=alveare.SetLocation(db, st2->GetColumnInt(0));
        break;
    case 3:
        db=alveare.SetDataCreazione(db, st2->GetColumnInt(0));
        break;
    case 4:
        db=alveare.SetDescrizione(db, st2->GetColumnInt(0));
        break;
    case 5:
        db=alveare.SetRazza(db, st2->GetColumnInt(0));
        break;
    case 6:
        db=alveare.SetColore(db, st2->GetColumnInt(0));
        break;
    case 7:
        db=alveare.SetTipoArnia(db, st2->GetColumnInt(0));
        break;
    case 8:
        db=alveare.SetProvenienza(db, st2->GetColumnInt(0));
        break;
    case 9:
        db=alveare.SetAnnoRegina(db, st2->GetColumnInt(0));
        break;
    case 10:
        db=alveare.SetStatoFamiglia(db, st2->GetColumnInt(0));
        break;
    case 11:
        db=alveare.SetPosizione(db, st2->GetColumnInt(0));
        break;
    }
    st2->FreeQuery();
    st->FreeQuery();
    return db;
}

void Alveare::Visualizza(Kompex::SQLiteDatabase *db)
{
    Kompex::SQLiteStatement *st = new Kompex::SQLiteStatement(db);
    try
    {
        st->Sql("select Alveari.ID, Alveari.Nome, Apiari.Nome, Alveari.GiornoCreazione, Alveari.MeseCreazione, Alveari.AnnoCreazione, Alveari.Descrizione, Razze.Nome, Alveari.Colore, TipiArnia.Nome, Provenienze.Provenienza, Alveari.AnnoRegina, StatoFamiglia.StatoFamiglia, Alveari.Posizione from Alveari join Apiari on Apiari.id=Alveari.Apiario join Razze on Razze.ID=Alveari.Razza join TipiArnia on TipiArnia.id=Alveari.TipoArnia join Provenienze on Provenienze.id = Alveari.Provenienza join StatoFamiglia on StatoFamiglia.id=Alveari.StatoFamiglia");
        string a;
        while (st->FetchRow())
        {
            string valore;
            cout << left << setw(20) << "ID" << ": " << st->GetColumnInt(0) << endl;
            cout << setw(20) << "Nome" << ": " << st->GetColumnString(1) << endl;
            cout << setw(20) << "Apiario" << ": " << st->GetColumnString(2) << endl;
            cout << setw(20) << "Creato il" << ": " << st->GetColumnInt(3) << "/" << st->GetColumnInt(4) << "/" << st->GetColumnInt(5) << endl;
            cout << setw(20) << "Descrizione" << ": " << st->GetColumnString(6) << endl;
            cout << setw(20) << "Razza" << ": " << st->GetColumnString(7) << endl;
            cout << setw(20) << "Colore" << ": " << st->GetColumnString(8) << endl;
            cout << setw(20) << "Tipo di Arnia" << ": " << st->GetColumnString(9) << endl;
            cout << setw(20) << "Provenienza" << ": " << st->GetColumnString(10) << endl;
            cout << setw(20) << "Anno Regina" << ": " << st->GetColumnInt(11) << endl;
            cout << setw(20) << "Stato della famiglia" << ": " << st->GetColumnString(12) << endl;
            cout << setw(20) << "Posizione" << ": " << st->GetColumnInt(13) << endl;
            cout << "Premi un carattere qualsiasi e batti invio" << endl;
            cin >> a;
        }
        st->FreeQuery();
    }
    catch (Kompex::SQLiteException &exception)
    {
        cout << exception.GetString();
    }
}

Kompex::SQLiteDatabase *Alveare::SetNome(Kompex::SQLiteDatabase *db, int id)
{
    cout << "Nuovo Nome -> ";
    string valore;
    try
    {
        Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
        st->Sql("UPDATE Alveari SET Nome = ? WHERE ID = ?;");
        st->BindInt(2,id);
        cin >> valore;
        st->BindString(1,valore);
        st->ExecuteAndFree();
    }
    catch(Kompex::SQLiteException &e)
    {
        cout << e.GetString();
    }
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetLocation(Kompex::SQLiteDatabase *db, int id)
{
    Apiario apiario;
    apiario.Visualizza(db);
    cout << "ID Nuovo Apiario -> ";
    string valore;
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    st->Sql("UPDATE Alveari SET Apiario = ? WHERE ID = ?");
    st->BindInt(2, id);
    cin >> valore;
    st->BindString(1, valore);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetDataCreazione(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    st->Sql("UPDATE Alveari SET GiornoCreazione = ?, MeseCreazione = ?, AnnoCreazione = ? WHERE ID=?;");
    int valore;
    cout << "Giorno -> ";
    cin >> valore;
    st->BindInt(1, valore);
    cout << "Mese -> ";
    cin >> valore;
    st->BindInt(2, valore);
    cout << "Anno -> ";
    cin >> valore;
    st->BindInt(3, valore);
    st->BindInt(4, id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetDescrizione(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    st->Sql("UPDATE Alveari SET Descrizione = ? WHERE ID = ?");
    string valore;
    cout << "Nuova Descrizione -> ";
    st->BindString(1, valore);
    st->BindInt(2, id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetRazza(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    st->GetTable("SELECT * FROM Razze");
    st->FreeQuery();
    st->Sql("UPDATE Alveari SET Razza = ? WHERE ID = ?;");
    int valore;
    cout << "ID Nuova Razza -> ";
    cin >> valore;
    st->BindInt(1, valore);
    st->BindInt(2, id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetColore(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    st->Sql("UPDATE Alveari SET Colore = ? WHERE ID = ?;");
    string valore;
    cout << "Nuova Descrizione -> ";
    cin >> valore;
    st->BindString(1, valore);
    st->BindInt(2, id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetTipoArnia(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    st->GetTable("SELECT * FROM TipiArnia");
    int valore;
    cout << "ID Nuovo tipo arnia -> ";
    cin >> valore;
    st->Sql("UPDATE Alveari SET TipoArnia = ? WHERE ID = ?;");
    st->BindInt(1, valore);
    st->BindInt(2, id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetProvenienza(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    st->GetTable("SELECT * FROM Provenienze;");
    int valore;
    cout << "ID Nuova provenienza -> ";
    cin >> valore;
    st->Sql("UPDATE Alveari SET Provenienza = ? WHERE ID = ?;");
    st->BindInt(1, valore);
    st->BindInt(2, id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetStatoFamiglia(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    st->GetTable("SELECT * FROM StatoFamiglia;");
    int valore;
    cout << "ID Nuovo Stato della famiglia -> ";
    cin >> valore;
    st->Sql("UPDATE Alveari SET StatoFamiglia = ? WHERE ID = ?;");
    st->BindInt(1, valore);
    st->BindInt(2, id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetPosizione(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    int valore;
    cout << "Nuova Posizione -> ";
    cin >> valore;
    st->Sql("UPDATE Alveari SET Posizione = ? WHERE ID = ?;");
    st->BindInt(1, valore);
    st->BindInt(2, id);
    st->ExecuteAndFree();
    return db;
}

Kompex::SQLiteDatabase *Alveare::SetAnnoRegina(Kompex::SQLiteDatabase *db, int id)
{
    Kompex::SQLiteStatement *st=new Kompex::SQLiteStatement(db);
    int valore;
    cout << "Nuovo Anno di nascita della regina -> ";
    cin >> valore;
    st->Sql("UPDATE Alveari SET AnnoRegina = ? WHERE ID = ?;");
    st->BindInt(1, valore);
    st->BindInt(2, id);
    st->ExecuteAndFree();
    return db;
}
