# -*- coding: utf-8 -*-
import datetime

# TODO necessaria una funzione di ricerca degli alveari?
# TODO Aggiungere interfaccia per l'eliminazione degli alveari
# TODO Aggiungere interfaccia per la modifica degli alveari


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
        """
        Funzione di aggiunta di alveari

        Prende l'oggetto Alveare e lo inserisce nel database

        Args:
            db: l'oggetto database
        """
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
        # TODO implementare funzione di modifica degli alveari
        return

    def Elimina(self, db):
        """
        Funzione di eliminazione degli alveari

        Elimina un alveare a partire dall'ID nel database

        Args:
            db: il database su cui lavorare
        """
        cur = db.cursor()
        cur.execute("DELETE FROM ALVEARI WHERE ID=?;", (self.ID, ))
        # TODO implementare funzione di eliminazione degli alveari

    def Elenca(self, db):
        """
        Funzione di elenco degli alveari

        Fa una query sul database per trovare tutti gli alverari e ritorna una
        tupla di tutti i risultati

        Args:
            db: il database su cui lavorare

        Returns:
            una tupla con tutti i valori trovati
        """
        cur = db.cursor()
        cur.execute("SELECT * FROM ALVEARI;")
        valori = cur.fetchall()
        return valori

    def InterfacciaAggiungi(self, db):
        """
        Funzione di interfaccia per l'aggiunta di alveari

        Funge da interfaccia per l'inserimento dei dati del nuovo alveare

        Args:
            db: il database su cui si lavora
        """
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

    def InterfacciaElenca(self, db):
        """
        Interfaccia di elenco alveari

        Fornisce un'interfaccia alla funzione di elenco degli alveari

        Args:
            db: il database su cui lavorare
        """
        print("Elenco Alveari")
        print("==============\n\n")
        print("+====+================+===============+")
        print("| ID |      Nome      |    Apiario    |")
        print("+====+================+===============+")
        valori = self.Elenca(db)
        for val in valori:
            print("|{:>4}|{:>16}|{:>15}|".format(val[0], val[1], val[2]))
        print("+====+================+===============+")
