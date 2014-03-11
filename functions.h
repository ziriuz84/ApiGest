#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <sqlite3.h>
#include <string>
#include <tntdb/connection.h>

static int callback(void *, int , char **, char **);
tntdb::Connection EseguiQuery(tntdb::Connection,const char *);
tntdb::Connection InizializzaDB(tntdb::Connection);
tntdb::Connection ApriDatabase();
void WIP();
void AmministrazioneAlveari();
tntdb::Connection AmministrazioneApiari(tntdb::Connection);
void AmministrazioneVisite();
void AmministrazioneInterventi();
void AmministrazioneMagazzino();
#endif // FUNCTIONS_H_INCLUDED
