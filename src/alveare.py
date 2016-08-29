# -*- coding: utf-8 -*-
import datetime


class Alveare:
    def __init__(self):
        self.ID = 0
        self.Nome = ""
        self.Apiario = 0
        self.DataCreazione = datetime.date(1, 1, 1)
        self.Descrizione = ""
        self.Razza = 0
        self.Colore = ""
        self.TipoArnia = 0
        self.Provenienza = 0
        self.AnnoRegina = 0
        self.StatoFamiglia = 0
        self.Posizione = 0

    def Aggiungi(self, db):
        cur = db.cursor()
        cur.execute("SELECT COUNT(*) FROM ALVEARI;")
        LastID = cur.fetchone()
        self.ID = LastID[0]
        valori = (self.ID, self.Nome, self.Apiario, self.DataCreazione.day,
                  self.DataCreazione.month, self.DataCreazione.year,
                  self.Descrizione, self.Razza, self.Colore, self.TipoArnia,
                  self.Provenienza, self.AnnoRegina, self.StatoFamiglia,
                  self.Posizione)
        cur.execute("INSERT INTO ALVEARI VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?);",
                    valori)
        db.commit()

    def Modifica(self):
        return

    def Elimina(self):
        return

    def Elenca(self):
        return

    def InterfacciaAggiungi(self, db):
        cur = db.cursor()
        print("Aggiunta di un Alveare")
        print("======================\n\n")
        self.Nome = input("Nome -> ")
        cur.execute("SELECT * FROM APIARI;")
        valori = cur.fetchall()
        print("+====+==============+")
        print("| ID |     Nome     |")
        print("+====+==============+")
        for val in valori:
            print("|{:>4}|{:>13}|".format(val[0], val[1]))
        print("+====+==============+")
        self.Apiario = eval(input("ID Apiario di appartenenza -> "))
        data = input("Data di creazione (GG/MM/AAAA) -> ")
        data = data.split("/")
        self.DataCreazione = datetime.date(int(data[2]), int(data[1]),
                                           int(data[0]))
        self.Descrizione = input("Descrizione -> ")
        cur.execute("select * from razze;")
        valori = cur.fetchall()
        print("+====*========================+")
        print("| ID |          Razza         |")
        print("+====*========================+")
        for val in valori:
            print("|{:>4}|{:>25}|".format(val[0], val[1]))
        print("+====+========================+")
        self.Razza = eval(input("ID razza -> "))
        self.Colore = input("Colore -> ")
        cur.execute("select * from tipiarnia;")
        valori = cur.fetchall()
        print("+====*========================+")
        print("| ID |       Tipi Arnia       |")
        print("+====*========================+")
        for val in valori:
            print("|{:>4}|{:>25}|".format(val[0], val[1]))
        print("+====+========================+")
        self.TipoArnia = input("ID Tipo Arnia -> ")
        cur.execute("select * from provenienze;")
        valori = cur.fetchall()
        print("+====*=========================+")
        print("| ID |       Provenienza       |")
        print("+====*=========================+")
        for val in valori:
            print("|{:>4}|{:>26}|".format(val[0], val[1]))
        print("+====+=========================+")
        self.Provenienza = input("ID Provenienza -> ")
        self.AnnoRegina = input("Anno di nascita Regina -> ")
        cur.execute("select * from statofamiglia;")
        valori = cur.fetchall()
        print("+====*=========================+")
        print("| ID |      Stato Famiglia     |")
        print("+====*=========================+")
        for val in valori:
            print("|{:>4}|{:>26}|".format(val[0], val[1]))
        print("+====+=========================+")
        self.StatoFamiglia = input("ID Stato Famiglia -> ")
        self.Posizione = input("Posizione -> ")
        self.Aggiungi(db)