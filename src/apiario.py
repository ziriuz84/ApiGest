# -*- coding: utf-8 -*-


class Apiario:
    def __init__(self):
        self.ID = 0
        self.Nome = ""
        self.Posizione = ""
    def Aggiungi(self, db):
        cur = db.cursor()
        cur.execute("SELECT COUNT(*) FROM APIARI")
        self.ID = cur.fetchone()
        if self.ID == NULL:
            self.ID = 0
        else:
            self.ID +=1
        cur.execute("INSERT INTO APIARI VALUES({:d},{nome},{posizione});"
                    .format(self.ID, self.Nome, self.Posizione)
    def Modifica(self, db):
        return
    def Elimina(self):
        return
    def InterfacciaAggiungi(self, db):
        print("Aggiungi un Apiario")
        print("===================\n\n")
        self.Nome = input("Nome -> ")
        self.Posizione = input("Posizione -> ")
        self.Aggiungi(db)
        return
