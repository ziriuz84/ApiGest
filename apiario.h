#ifndef APIARIO_H
#define APIARIO_H
#include <iostream>
#include <sqlite3.h>
#include <tntdb/connection.h>
#include <string>
using namespace std;

class Apiario
{
public:
    /** Default constructor */
    Apiario();
    /** Default destructor */
    virtual ~Apiario();
    /** Add Alveare
     *
     */
    tntdb::Connection Aggiungi(tntdb::Connection);
    /** Modify Alveare
     *
     */
    void Modifica();
    /** Delete Alveare
     *
     */
    void Elimina();
    /** Show Alveare
     *
     */
    void Visualizza();
protected:
private:
//    unsigned int ID; //!< Member variable "ID"
    string ID; //!< Member variable "ID"
    string Nome; //!< Member variable "Nome"
    string Posizione; //!< Member variable "Posizione"
    /** Access ID
    * \return The current value of ID
    */
    string GetID()
    {
        return ID;
    }
    /** Set ID
     * \param val New value to set
     */
    void SetID(string val)
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
    /** Access Posizione
     * \return The current value of Posizione
     */
    string GetPosizione()
    {
        return Posizione;
    }
    /** Set Posizione
     * \param val New value to set
     */
    void SetPosizione(string val)
    {
        Posizione = val;
    }
};

#endif // APIARIO_H
