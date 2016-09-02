# -*- coding: utf-8 -*-

from functions import WIP
import apiario
import alveare

# TODO Aggiungere menu gestione visite


def MenuApiari(db):
    """
    Funzione di gestione degli apiari

    Stampa il menu della gestione apiari e chiama il metodo relativo
    all'opzione scelta

    Args:
        db: il database su cui lavorare
    """
    Apiario = apiario.Apiario()
    scelta = 5
    while scelta != 0:
        print("Gestione apiari")
        print("========================\n\n")
        print("1 - Aggiungi Apiario")
        print("2 - Modifica Apiario")
        print("3 - Cancella Apiario")
        print("4 - Elenca Apiari")
        print("0 - Torna Indietro")
        scelta = eval(input("Scelta-> "))
        print("\n\n\n\n")
        if scelta == 1:
            Apiario.InterfacciaAggiungi(db)
        if scelta == 2:
            Apiario.InterfacciaModifica(db)
        if scelta == 3:
            Apiario.InterfacciaCancella(db)
        if scelta == 4:
            Apiario.InterfacciaElenca(db)


def MenuAlveari(db):
    """
    Funzione di gestione degli alveari

    Stampa il menu della gestione alveari e chiama il metodo relativo
    all'opzione scelta

    Args:
        db: il database su cui lavorare
    """
    Alveare = alveare.Alveare()
    scelta = 5
    while scelta != 0:
        print("Gestione alveari")
        print("========================\n\n")
        print("1 - Aggiungi Alveare")
        print("2 - Modifica Alveare")
        print("3 - Cancella Alveare")
        print("4 - Elenca Alveari")
        print("5 - Elenca Alveari di uno specifico Apiario")
        print("0 - Torna Indietro")
        scelta = eval(input("Scelta-> "))
        print("\n\n\n\n")
        if scelta == 1:
            Alveare.InterfacciaAggiungi(db)
        if scelta == 2:
            WIP()  # TODO Aggiungere funzione di modifica
        if scelta == 3:
            WIP()  # TODO Aggiungere funzione di eliminazione
        if scelta == 4:
            Alveare.InterfacciaElenca(db)
        if scelta == 5:
            Alveare.InterfacciaElencaPerApiario(db)


def MenuPrincipale(db):
    """
    Funzione del menu principale

    Stampa il menu principale e chiama la funziona relativa all'opzione scelta

    Args:
        db: il database su cui lavorare
    """
    scelta = 5
    while (scelta != 0):
        print("Benvenuto in Apigest 0.1")
        print("========================")
        print("\n")
        print("1 - Gestione Apiari")
        print("2 - Gestione Alveari")
        print("0 - Esci")
        scelta = eval(input("scelta-> "))
        print("\n\n\n\n")
        if scelta == 1:
            MenuApiari(db)
        if scelta == 2:
            MenuAlveari(db)


def Interfaccia(db):
    """
    Funzione dell'interfaccia testuale

    Richiama il menu principale dell'interfaccia testuale

    Args:
        db: il database su cui lavorare
    """
    MenuPrincipale(db)
