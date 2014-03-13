#include "alveare.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <tntdb/connection.h>
#include <tntdb/value.h>
#include <tntdb/statement.h>
#include <tntdb/result.h>
#include <tntdb/row.h>
using namespace std;

Alveare::Alveare()
{
    //ctor
}

Alveare::~Alveare()
{
    //dtor
}
tntdb::Connection Alveare::Aggiungi(tntdb::Connection db)
{
    int temp1, temp2, temp3;
    string tempstr;
    tntdb::Value v=db.selectValue("select count(*) from Alveari");
    Apiario apiario;
    if (v.getUnsigned()<1)
    {
        ID=0;
    }
    else
    {
        v=db.selectValue("select ID from Alveari where id = (select MAX(ID) from Alveari)");
        ID=v.getUnsigned()+1;
    }
    tntdb::Statement st=db.prepare("INSERT INTO Alveari(ID, Nome, Apiario, DataCreazione, Descrizione, Razza, Colore, TipoArnia, Provenienza, AnnoRegina, StatoFamiglia, Posizione) VALUES (:id, :nome, :apiario, :datacreazione, :descrizione, :razza, :colore, :tipoarnia, :provenienza, :annoregina, :statofamiglia, :posizione)");
    st.set("id", ID);
    cout << "Inserisci il nome dell'alveare" << endl << "Nome -> ";
    cin >> tempstr;
    st.set("nome", tempstr);
    apiario.Visualizza(db);
    cout << "Scegli l'ID dell'apiario di appartenenza" << endl << "ID -> ";
    cin >> temp1;
    st.set("apiario", temp1);
    cout << "Seleziona la data di creazione dell'alveare" << endl << "Giorno -> ";
    cin >> temp1;
    cout << "Mese -> ";
    cin >> temp2;
    cout << "Anno -> ";
    cin >> temp3;
    st.set("datacreazione", tntdb::Date(temp3, temp2, temp1));
    cout << "Inserisci un'eventuale descrizione" << endl;
    cin >> tempstr;
    st.set("descrizione", tempstr);
    tntdb::Result result=db.select("select * from Razze");
    cout << "|" << setw(4) << "ID" << "|" << setw(25) << "Razza" << "|" << endl;
    cout << "|----|---------------------------|" << endl;
    for (tntdb::Result::const_iterator it=result.begin();it!=result.end();++it){
        tntdb::Row row=*it;
        string id, nome;
        row[0].get(id);
        row[1].get(nome);
        cout << "|" << setw(4) << id << "|" << setw(25) << nome << "|" << endl;
    }
    cout << "Seleziona la razza" << endl << "ID -> ";
    cin >> temp1;
    st.set("razza", temp1);
    cout << "Inserisci il colore dell'arnia" << endl << "Colore -> ";
    cin >> tempstr;
    st.set("colore", tempstr);
    result=db.select("select * from TipiArnia");
    cout << "|" << setw(4) << "ID" << "|" << setw(15) << "Tipo arnia" << "|" << endl;
    cout << "|----|----------------|" << endl;
    for (tntdb::Result::const_iterator it=result.begin();it!=result.end();++it){
        tntdb::Row row=*it;
        string id, nome;
        row[0].get(id);
        row[1].get(nome);
        cout << "|" << setw(4) << id << "|" << setw(15) << nome << "|" << endl;
    }
    cout << "Seleziona l'ID del tipo di arnia corretto" << endl << "ID -> ";
    cin >> temp1;
    st.set("tipoarnia", temp1);
    result=db.select("select * from Provenienze");
    cout << "|" << setw(4) << "ID" << "|" << setw(15) << "Provenienza" << "|" << endl;
    cout << "|----|----------------|" << endl;
    for (tntdb::Result::const_iterator it=result.begin();it!=result.end();++it){
        tntdb::Row row=*it;
        string id, nome;
        row[0].get(id);
        row[1].get(nome);
        cout << "|" << setw(4) << id << "|" << setw(15) << nome << "|" << endl;
    }
    cout << "Seleziona l'ID della provenienza corretta" << endl << "ID -> ";
    cin >> temp1;
    st.set("provenienza", temp1);
    cout << "Inserisci l'anno di nascita della regina" << endl << "Anno -> ";
    cin >> temp1;
    st.set("annoregina", temp1);
    result=db.select("select * from StatoFamiglia");
    cout << "|" << setw(4) << "ID" << "|" << setw(15) << "Stato Famiglia" << "|" << endl;
    cout << "|----|----------------|" << endl;
    for (tntdb::Result::const_iterator it=result.begin();it!=result.end();++it){
        tntdb::Row row=*it;
        string id, nome;
        row[0].get(id);
        row[1].get(nome);
        cout << "|" << setw(4) << id << "|" << setw(15) << nome << "|" << endl;
    }
    cout << "Dai un voto allo stato della famiglia [0-4]" << endl << "Voto -> ";
    cin >> temp1;
    st.set("statofamiglia", temp1);
    cout << "Indica la posizione dell'arnia nell'apiario" << endl << "Posizione -> ";
    cin >> temp1;
    cout << 1 << endl;
    st.set("posizione", temp1).execute();
    cout << 2 << endl;
    return db;
}

void Alveare::Elimina()
{
    //Elimina
}

void Alveare::Modifica()
{
    //Modifica
}

void Alveare::Visualizza()
{
    //Visualizza
}
