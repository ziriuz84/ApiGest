# -*- coding: utf-8 -*-

from functions import WIP
import apiario
import alveare


def MenuApiari(db):
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
    Alveare = alveare.Alveare()
    scelta = 5
    while scelta != 0:
        print("Gestione alveari")
        print("========================\n\n")
        print("1 - Aggiungi Alveare")
        print("2 - Modifica Alveare")
        print("3 - Cancella Alveare")
        print("4 - Elenca Alveari")
        print("0 - Torna Indietro")
        scelta = eval(input("Scelta-> "))
        print("\n\n\n\n")
        if scelta == 1:
            Alveare.InterfacciaAggiungi(db)
        if scelta == 2:
            WIP()
        if scelta == 3:
            WIP()
        if scelta == 4:
            WIP()


def MenuPrincipale(db):
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
    MenuPrincipale(db)
