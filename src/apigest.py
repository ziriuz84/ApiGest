#!/usr/bin/python3
# -*- coding: utf-8 -*-

from functions import TestDatabase
from interface import Interfaccia
import sqlite3 as lite
from sys import exit

# TODO Aggiungere supporto al file di configurazione

con = None

if __name__ == "__main__":
    try:
        con = lite.connect('test.db')
    except lite.Error as e:
        print("Error %s: " % e.args[0])
        exit(1)
    TestDatabase(con)
    Interfaccia(con)
    con.close()
