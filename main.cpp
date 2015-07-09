#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sqlite3.h>
#include "functions.h"
//using namespace std;

static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   fprintf(stderr, "%s: ", (const char*)data);
   for(i=0; i<argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main() {
	int scelta;
	sqlite3 *db;
	int rc;
	char *zErrMsg;

	rc = sqlite3_open("test.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		exit(0);
	} else {
		fprintf(stderr, "Opened database successfully\n");
	}

	float ntabelle;
//	ntabelle = st->SqlAggregateFuncResult("select count(*) from sqlite_master;");
	std::cout << ntabelle;
	if (ntabelle < 1) {
		std::cout << 0 << std::endl;
//		db = InizializzaDB(db);
	} else {
		std::cout << 1 << std::endl;
	}
	do {
		std::cout << "ApiGest 0.1" << std::endl;
		std::cout << "1 - Amministrazione Alveari" << std::endl;
		std::cout << "2 - Amministrazione Apiari" << std::endl;
		std::cout << "3 - Amministrazione Visite" << std::endl;
		std::cout << "4 - Amministrazione Interventi Fitosanitari" << std::endl;
		std::cout << "5 - Amministrazione Magazzino" << std::endl;
		std::cout << "0 - Esci" << std::endl;
		std::cout << "Scelta -> ";
		std::cin >> scelta;

		switch (scelta) {
		case 1:
//			db = AmministrazioneAlveari(db);
			break;
		case 2:
//			db = AmministrazioneApiari(db);
			break;
		case 3:
//			AmministrazioneVisite();
			break;
		case 4:
//			AmministrazioneInterventi();
			break;
		case 5:
//			AmministrazioneMagazzino();
			break;
		}
	} while (scelta != 0);
	return 0;
}

