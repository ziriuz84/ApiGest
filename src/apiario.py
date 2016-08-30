# -*- coding: utf-8 -*-


class Apiario:
    def __init__(self):
        self.ID = 0
        self.Nome = ""
        self.Posizione = ""

    def Aggiungi(self, db):
        """
        Funzione di aggiunta dell'apiario

        Aggiunge nel database l'oggetto apiario

        Args:
            db: il database su cui si lavora
        """
        cur = db.cursor()
        cur.execute("SELECT COUNT(*) FROM APIARI;")
        LastID = cur.fetchone()
        self.ID = LastID[0]
        valori = (self.ID, self.Nome, self.Posizione)
        cur.execute("INSERT INTO APIARI VALUES(?, ?, ?);", valori)
        db.commit()

    def Modifica(self, db):
        """
        Funzione di modifica dell'apiario

        Modifica i valori dell'apiario all'interno del database

        Args:
            db: il database su cui si lavora
        """
        cur = db.cursor()
        cur.execute("UPDATE APIARI SET Nome=?, Posizione=? WHERE ID=?;",
                    (self.Nome, self.Posizione, self.ID))
        db.commit()

    def Elimina(self, db):
        """
        Funzione di eliminazione dell'apiario

        Elimina l'apiario a partire dal suo id

        Args:
            db: il database su cui si lavora
        """
        cur = db.cursor()
        cur.execute("DELETE FROM APIARI WHERE ID=?;",
                    (self.ID, ))
        db.commit()

    def Elenca(self, db):
        """
        Funzione di elenco degli apiari

        Fa una query al database per ritornare l'intero elenco degli apiari

        Args:
            db: il database su cui si lavora

        Returns:
            una lista con tutti i valori
        """
        cur = db.cursor()
        cur.execute("SELECT * FROM APIARI;")
        valori = cur.fetchall()
        return valori

    def InterfacciaAggiungi(self, db):
        """
        Interfaccia per l'aggiunta dell'apiario

        Funge da interfaccia per l'inserimento dei dati dell'apiario

        Args:
            db: il database su cui si lavora
        """
        print("Aggiungi un Apiario")
        print("===================\n\n")
        self.Nome = input("Nome -> ")
        self.Posizione = input("Posizione -> ")
        self.Aggiungi(db)

    def InterfacciaElenca(self, db):
        """
        Interfaccia di elenco degli apiari

        Funge da interfaccia con la query di inserimento degli apiari, creando
        una tabella formattata

        Args:
            db: il database su cui si lavora
        """
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
        """
        Interfaccia di modifica degli apiari

        Funge da interfaccia per la modifica degli apiari

        Args:
            db: il database su cui lavorare
        """
        print("Modifica Apiario")
        print("================\n\n")
        self.InterfacciaElenca(db)
        self.ID = eval(input("ID apiario da modificare -> "))
        self.Nome = input("Nome -> ")
        self.Posizione = input("Posizione -> ")
        self.Modifica(db)

    def InterfacciaCancella(self, db):
        """
        Interfaccia di eliminazione apiari

        Funge da interfaccia per l'eliminazione degli apiari. Stampa una
        tabella con l'elenco di tutti gli apiari e chiede l'ID dell'apiario
        da eliminare

        Args:
            db: il database su cui lavorare
        """
        print("Cancella Apiario")
        print("================")
        self.InterfacciaElenca(db)
        self.ID = eval(input("ID Apiario da cancellare"))
        self.Elimina(db)
