#ifndef ALVEARE_H
#define ALVEARE_H
#include <string>
#include <iostream>
#include <KompexSQLiteDatabase.h>
#include <KompexSQLiteStatement.h>
#include "apiario.h"

using namespace std;

class Alveare
{
public:
    /** Default constructor */
    Alveare();
    /** Default destructor */
    virtual ~Alveare();
    /** Add Alveare
     *
     */
    Kompex::SQLiteDatabase *Aggiungi(Kompex::SQLiteDatabase *);
    /** Modify Alveare
     *
     */
    Kompex::SQLiteDatabase *Modifica(Kompex::SQLiteDatabase *);
    /** Delete Alveare
     *
     */
    Kompex::SQLiteDatabase *Elimina(Kompex::SQLiteDatabase *);
    /** Show Alveare
     *
     */
    void Visualizza(Kompex::SQLiteDatabase *);
protected:
private:
    unsigned int ID; //!< Member variable "ID"
    string Nome; //!< Member variable "Nome"
    Apiario Location; //!< Member variable "Apiario"
    time_t DataCreazione; //!< Member variable "DataCreazione"
    string Descrizione; //!< Member variable "Descrizione"
    string Razza; //!< Member variable "Razza"
    string Colore; //!< Member variable "Colore"
    string TipoArnia; //!< Member variable "TipoArnia"
    string Provenienza; //!< Member variable "Provenienza"
    string StatoFamiglia; //!< Member variable "StatoFamiglia"
    unsigned int Posizione; //!< Member variable "Posizione"
    unsigned int AnnoRegina; //!< Member variable "AnnoRegina"
    /** Access ID
     * \return The current value of ID
     */
    unsigned int GetID()
    {
        return ID;
    }
    /** Set ID
     * \param val New value to set
     */
    void SetID(unsigned int val)
    {
        ID = val;
    }
    /** Access Nome
     * \return The current value of Nome
     */
    string GetNome()
    {
        return Nome;
    }
    /** Set Nome
     * \param val New value to set
     */
    void SetNome(string val)
    {
        Nome = val;
    }
    /** Access Apiario
     * \return The current value of Locazione
     */
    Apiario GetLocation()
    {
        return Location;
    }
    /** Set Apiario
     * \param val New value to set
     */
    void SetLocation(Apiario val)
    {
        Location = val;
    }
    /** Access DataCreazione
     * \return The current value of DataCreazione
     */
    time_t GetDataCreazione()
    {
        return DataCreazione;
    }
    /** Set DataCreazione
     * \param val New value to set
     */
    void SetDataCreazione(time_t val)
    {
        DataCreazione = val;
    }
    /** Access Descrizione
     * \return The current value of Descrizione
     */
    string GetDescrizione()
    {
        return Descrizione;
    }
    /** Set Descrizione
     * \param val New value to set
     */
    void SetDescrizione(string val)
    {
        Descrizione = val;
    }
    /** Access Razza
     * \return The current value of Razza
     */
    string GetRazza()
    {
        return Razza;
    }
    /** Set Razza
     * \param val New value to set
     */
    void SetRazza(string val)
    {
        Razza = val;
    }
    /** Access Colore
     * \return The current value of Colore
     */
    string GetColore()
    {
        return Colore;
    }
    /** Set Colore
     * \param val New value to set
     */
    void SetColore(string val)
    {
        Colore = val;
    }
    /** Access TipoArnia
     * \return The current value of TipoArnia
     */
    string GetTipoArnia()
    {
        return TipoArnia;
    }
    /** Set TipoArnia
     * \param val New value to set
     */
    void SetTipoArnia(string val)
    {
        TipoArnia = val;
    }
    /** Access Provenienza
     * \return The current value of Provenienza
     */
    string GetProvenienza()
    {
        return Provenienza;
    }
    /** Set Provenienza
     * \param val New value to set
     */
    void SetProvenienza(string val)
    {
        Provenienza = val;
    }
    /** Access StatoFamiglia
     * \return The current value of StatoFamiglia
     */
    string GetStatoFamiglia()
    {
        return StatoFamiglia;
    }
    /** Set StatoFamiglia
     * \param val New value to set
     */
    void SetStatoFamiglia(string val)
    {
        StatoFamiglia = val;
    }
    /** Access Posizione
     * \return The current value of Posizione
     */
    unsigned int GetPosizione()
    {
        return Posizione;
    }
    /** Set Posizione
     * \param val New value to set
     */
    void SetPosizione(unsigned int val)
    {
        Posizione = val;
    }
    /** Access AnnoRegina
     * \return The current value of AnnoRegina
     */
    unsigned int GetAnnoRegina()
    {
        return AnnoRegina;
    }
    /** Set AnnoRegina
     * \param val New value to set
     */
    void SetAnnoRegina(unsigned int val)
    {
        AnnoRegina = val;
    }
    Kompex::SQLiteDatabase *SetNome(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetLocation(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetDataCreazione(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetDescrizione(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetRazza(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetColore(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetTipoArnia(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetProvenienza(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetStatoFamiglia(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetPosizione(Kompex::SQLiteDatabase *, int);
    Kompex::SQLiteDatabase *SetAnnoRegina(Kompex::SQLiteDatabase *, int);
};

#endif // ALVEARE_H
