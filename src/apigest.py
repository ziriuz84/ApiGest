#!/usr/bin/python
# -*- coding: utf-8 -*-

import functions
from interface import Interfaccia
import sqlite3 as lite

con = None

if __name__ == "__main__":
    try:
        con = lite.connect('test.db')
    except lite.Error, e:
        print "Error %s: " % e.args[0]
        sys.exit(1)
    Interfaccia(con)
    con.close()
