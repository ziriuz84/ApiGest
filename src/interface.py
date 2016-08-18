# -*- coding: utf-8 -*-

import apiario

def MenuApiari(db):
    scelta = 5
    while scelta != 0:
        print "Gestione apiari"
        print "========================\n\n"
        print "1 - Aggiungi Apiario"
        print "2 - Modifica Apiario"
        print "3 - Cancella Apiario"
        print "4 - Elenca Apiari"
        print "0 - Torna Indietro"
        scelta = input("Scelta-> ")
        print "\n\n\n\n"

def MenuPrincipale(db):
    scelta = 5
    while (scelta != 0):
        print "Benvenuto in Apigest 0.1"
        print "========================"
        print "\n"
        print "1 - Gestione Apiari"
        print "0 - Esci"
        scelta = input("scelta-> ")
        print "\n\n\n\n"
        if scelta == 1:
            MenuApiari(db)

def Interfaccia(db):
    MenuPrincipale(db)

