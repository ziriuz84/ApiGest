#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <sqlite3.h>
#include <string>
#include <tntdb/connection.h>

tntdb::Connection InizializzaDB(tntdb::Connection);
tntdb::Connection ApriDatabase();
void WIP();
tntdb::Connection AmministrazioneAlveari(tntdb::Connection);
tntdb::Connection AmministrazioneApiari(tntdb::Connection);
void AmministrazioneVisite();
void AmministrazioneInterventi();
void AmministrazioneMagazzino();
#endif // FUNCTIONS_H_INCLUDED
