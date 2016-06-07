# -*- coding: utf-8 -*-
import functions
import sqlite3


scelta = 100
conn = sqlite3.connect('./test.db')
c = conn.cursor()
c.execute('''SELECT COUNT(*) FROM sqlite_master''')
dbvuoto = c.fetchone()
if dbvuoto[0] < 1:
    functions.InizializzaDB(conn)
print("ApiGest 0.1")
functions.MenuPrincipale(scelta, conn)
c.close()
conn.close()