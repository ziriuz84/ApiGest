# -*- coding: utf-8 -*-


class Apiario:
    def __init__(self):
        self.ID = 0
        self.Nome = ""
        self.Posizione = ""

    def Aggiungi(self, db):
        cur = db.cursor()
        cur.execute("SELECT COUNT(*) FROM APIARI;")
        LastID = cur.fetchone()
        self.ID = LastID[0]
        valori = (self.ID, self.Nome, self.Posizione)
        cur.execute("INSERT INTO APIARI VALUES(?, ?, ?);", valori)
        db.commit()

    def Modifica(self, db):
        cur = db.cursor()
        cur.execute("UPDATE APIARI SET Nome=?, Posizione=? WHERE ID=?;",
                    (self.Nome, self.Posizione, self.ID))
        db.commit()

    def Elimina(self, db):
        cur = db.cursor()
        cur.execute("DELETE FROM APIARI WHERE ID=?;",
                    (self.ID, ))
        db.commit()

    def Elenca(self, db):
        cur = db.cursor()
        cur.execute("SELECT * FROM APIARI;")
        valori = cur.fetchall()
        return valori

    def InterfacciaAggiungi(self, db):
        print("Aggiungi un Apiario")
        print("===================\n\n")
        self.Nome = input("Nome -> ")
        self.Posizione = input("Posizione -> ")
        self.Aggiungi(db)

    def InterfacciaElenca(self, db):
        print("Elenco degli apiari")
        print("===================\n\n")
        valori = self.Elenca(db)
        print("+====+==============+==================================+")
        print("| ID |     Nome     |            Posizione             |")
        print("+====+==============+==================================+")
        for val in valori:
            print("|{:>4}|{:>13}|{:>34}|".format(val[0], val[1], val[2]))
        print("+====+==============+==================================+")

    def InterfacciaModifica(self, db):
        print("Modifica Apiario")
        print("================\n\n")
        self.InterfacciaElenca(db)
        self.ID = eval(input("ID apiario da modificare -> "))
        self.Nome = input("Nome -> ")
        self.Posizione = input("Posizione -> ")
        self.Modifica(db)

    def InterfacciaCancella(self, db):
        print("Cancella Apiario")
        print("================")
        self.InterfacciaElenca(db)
        self.ID = eval(input("ID Apiario da cancellare"))
        self.Elimina(db)
