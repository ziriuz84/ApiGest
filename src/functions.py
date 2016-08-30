# -*- coding: utf-8 -*-

import sqlite3
import sys


def InizializzaDB(db):
    """
    Funzione di inizializzazione del database

    Inizializza il database con le relative tabelle e valori iniziali

    Args:
        db: il database con cui lavorare
    """
    try:
        sqlstatement = "CREATE TABLE TipiTrattamento("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL,"
        sqlstatement += "NomeTrattamento TEXT NOT NULL,"
        sqlstatement += "Descrizione TEXT NOT NULL, "
        sqlstatement += "Posologia TEXT NOT NULL)"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE Apiari("
        sqlstatement += "ID INT PRIMARY KEY, "
        sqlstatement += "Nome TEXT NOT NULL, "
        sqlstatement += "Posizione TEXT)"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE TipiArnia("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "Nome TEXT NOT NULL, "
        sqlstatement += "NTelaini INT NOT NULL)"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE Razze("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "Nome TEXT NOT NULL)"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE Provenienze("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "Provenienza TEXT NOT NULL)"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE StatoFamiglia("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "StatoFamiglia TEXT NOT NULL)"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE Nutrizioni("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "Nutrizione TEXT NOT NULL)"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE ScopiNutrizione("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "Scopo TEXT NOT NULL)"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE Alveari("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "Nome TEXT NOT NULL, "
        sqlstatement += "Apiario INT NOT NULL, "
        sqlstatement += "GiornoCreazione INT NOT NULL, "
        sqlstatement += "MeseCreazione INT NOT NULL, "
        sqlstatement += "AnnoCreazione INT NOT NULL, "
        sqlstatement += "Descrizione TEXT, "
        sqlstatement += "Razza INT NOT NULL, "
        sqlstatement += "Colore TEXT, "
        sqlstatement += "TipoArnia INT NOT NULL, "
        sqlstatement += "Provenienza INT NOT NULL, "
        sqlstatement += "AnnoRegina INT NOT NULL, "
        sqlstatement += "StatoFamiglia INT NOT NULL, "
        sqlstatement += "Posizione INT NOT NULL, "
        sqlstatement += "FOREIGN KEY(Apiario) REFERENCES Apiari(ID), "
        sqlstatement += "FOREIGN KEY(Razza) REFERENCES Razze(ID), "
        sqlstatement += "FOREIGN KEY(TipoArnia) REFERENCES TipiArnia(ID), "
        sqlstatement += "FOREIGN KEY(Provenienza) REFERENCES Provenienze(ID), "
        sqlstatement += "FOREIGN KEY(StatoFamiglia) "
        sqlstatement += "REFERENCES StatoFamiglia(ID))"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE TrattamentiFitosanitari("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "Data INT NOT NULL, "
        sqlstatement += "Cassetta INT NOT NULL, "
        sqlstatement += "Tipo TEXT NOT NULL, "
        sqlstatement += "Dosi TEXT NOT NULL, "
        sqlstatement += "FinoAl TEXT NOT NULL, "
        sqlstatement += "FOREIGN KEY(Cassetta) REFERENCES Alveari(ID))"
        db.execute(sqlstatement)
        sqlstatement = "CREATE TABLE Materiali("
        sqlstatement += "ID INT PRIMARY KEY NOT NULL, "
        sqlstatement += "Nome TEXT NOT NULL, "
        sqlstatement += "Descrizione TEXT NOT NULL, "
        sqlstatement += "Quantita TEXT NOT NULL)"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Nutrizioni(ID, Nutrizione) "
        sqlstatement += "VALUES(0, 'Assente'); "
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Nutrizioni(ID, Nutrizione) "
        sqlstatement += "VALUES(1,'Candito');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Nutrizioni(ID, Nutrizione) "
        sqlstatement += "VALUES(2,'Candito con polline');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Nutrizioni(ID, Nutrizione) "
        sqlstatement += "VALUES(3,'Sciroppo');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Nutrizioni(ID, Nutrizione) "
        sqlstatement += "VALUES(4,'Sciroppo con Apiherb')"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO ScopiNutrizione(ID, Scopo) "
        sqlstatement += "VALUES(0,'Emergenza');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO ScopiNutrizione(ID, Scopo) "
        sqlstatement += "VALUES(1,'Invernale')"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO StatoFamiglia(ID,StatoFamiglia) "
        sqlstatement += "VALUES (0, 'Critico');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO StatoFamiglia(ID,StatoFamiglia) "
        sqlstatement += "VALUES (1, 'Insufficiente');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO StatoFamiglia(ID,StatoFamiglia) "
        sqlstatement += "VALUES (2, 'Sufficiente');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO StatoFamiglia(ID,StatoFamiglia) "
        sqlstatement += "VALUES (3, 'Buono');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO StatoFamiglia(ID,StatoFamiglia) "
        sqlstatement += "VALUES (4, 'Ottimo')"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Razze(ID,Nome) "
        sqlstatement += "VALUES (0, 'Apis Mellifera Ligustica');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Razze(ID,Nome) "
        sqlstatement += "VALUES (1, 'Apis Mellifera Carnica');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Razze(ID,Nome) "
        sqlstatement += "VALUES (2, 'Apis Mellifera Sicula')"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Provenienze(ID, Provenienza) "
        sqlstatement += "VALUES (0, 'Sciame Acquistato');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Provenienze(ID, Provenienza) "
        sqlstatement += "VALUES (1, 'Sciame Naturale');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Provenienze(ID, Provenienza) "
        sqlstatement += "VALUES (2, 'Sciame Naturale');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO Provenienze(ID, Provenienza) "
        sqlstatement += "VALUES (3, 'Divisione da famiglia')"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiArnia(ID, Nome, NTelaini) "
        sqlstatement += "VALUES (0, 'D.B. 6', 6);"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiArnia(ID, Nome, NTelaini) "
        sqlstatement += "VALUES (1, 'D.B. 8', 8);"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiArnia(ID, Nome, NTelaini) "
        sqlstatement += "VALUES (2, 'D.B. 10', 10);"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiArnia(ID, Nome, NTelaini) "
        sqlstatement += "VALUES (3, 'D.B. 12', 12);"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiArnia(ID, Nome, NTelaini) "
        sqlstatement += "VALUES (4, 'Polistirolo 6', 6);"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiArnia(ID, Nome, NTelaini) "
        sqlstatement += "VALUES (5, 'Pigliasciami 6', 6)"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiTrattamento("
        sqlstatement += "ID, NomeTrattamento, Descrizione, Posologia) "
        sqlstatement += "VALUES (0, 'Apiguard', 'Timolo in Gel', "
        sqlstatement += "'Due cicli a 15 giorni di distanza');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiTrattamento("
        sqlstatement += "ID, NomeTrattamento, Descrizione, Posologia) "
        sqlstatement += "VALUES (1, 'ApiLifeVar', 'Timolo in spugne', "
        sqlstatement += "'Quattro cicli a 7 giorni di distanza');"
        db.execute(sqlstatement)
        sqlstatement = "INSERT INTO TipiTrattamento("
        sqlstatement += "ID, NomeTrattamento, Descrizione, Posologia) "
        sqlstatement += "VALUES (2, 'ApiBioxal gocciolato', "
        sqlstatement += "'Acido Ossalico gocciolato', "
        sqlstatement += "'Due cicli da 5ml a telaino ogni 21 giorni')"
        db.execute(sqlstatement)
        db.commit()
    except sqlite3.Error as e:
        print("Errore nella scrittura delle query:")
        print(e.args[0])
        sys.exit(1)


def TestDatabase(db):
    """
    Funzione di test del database

    Effettua un conteggio sul numero di tabelle nel database. Se è minore di 1,
    e quindi non ci sono tabelle, richiama la funzione InizializzaDB

    Args:
        db: il database con cui lavorare
    """
    cur = db.cursor()
    cur.execute("select count(*) from sqlite_master")
    if cur.fetchone() < (1,):
        InizializzaDB(db)


def WIP():
    """
    Funzione Work in progress

    Da richiamare quando una sezione è ancora da completare. Stampa
    semplicemente a schermo la frase "Work in Progress"
    """
    print("Work in Progress")
