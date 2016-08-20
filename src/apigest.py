#!/usr/bin/python
# -*- coding: utf-8 -*-

from functions import TestDatabase
from interface import Interfaccia
import sqlite3 as lite
import sys

con = None

if __name__ == "__main__":
    try:
        con = lite.connect('test.db')
    except lite.Error as e:
        print("Error %s: " % e.args[0])
        sys.exit(1)
    TestDatabase(con)
    Interfaccia(con)
    con.close()
