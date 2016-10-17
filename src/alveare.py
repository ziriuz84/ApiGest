# -*- coding: utf-8 -*-
import datetime
import apiario

# TODO necessaria una funzione di ricerca degli alveari?
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

    def Modifica(self, db):
        """
        Funzione di modifica degli alveari

        Modifica un alveare a partire dall'ID nel database

        Args:
            db: il database su cui lavorare
        """
        cur = db.cursor()
        sqlstatement = "UPDATE Alveari SET Nome=?, Apiario=?, "
        sqlstatement += "GiornoCreazione=?, MeseCreazione=?, "
        sqlstatement += "AnnoCreazione=?, Descrizione=?, Razza=?, "
        sqlstatement += "Colore=?, TipoArnia=?, Provenienza=?, "
        sqlstatement += "AnnoRegina=?, StatoFamiglia=?, Posizione=? "
        sqlstatement += "WHERE ID=?;"
        cur.execute(sqlstatement, (self.Nome,
                                   self.Apiario,
                                   self.DataCreazione.day,
                                   self.DataCreazione.month,
                                   self.DataCreazione.year,
                                   self.Descrizione,
                                   self.Razza,
                                   self.Colore,
                                   self.TipoArnia,
                                   self.Provenienza,
                                   self.AnnoRegina,
                                   self.StatoFamiglia,
                                   self.Posizione,
                                   self.ID))

    def Elimina(self, db):
        """
        Funzione di eliminazione degli alveari

        Elimina un alveare a partire dall'ID nel database

        Args:
            db: il database su cui lavorare
        """
        cur = db.cursor()
        cur.execute("DELETE FROM ALVEARI WHERE ID=?;", (self.ID, ))
        db.commit()

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

    def ElencaPerApiario(self, db):
        """
        Funzione di elenco per apiario

        Recupera gli alveari che appartengono ad un dato apiario

        Args:
            db: il database su cui lavorare
        """
        cur = db.cursor()
        cur.execute("SELECT * FROM ALVEARI WHERE Apiario=?;", (self.Apiario, ))
        valori = cur.fetchall()
        return valori

    def SelezionaAlveare(self, db):
        """
        Funzione di selezione di un alveare

        Recupera i valori di un alveare e ne salva gli attributi

        Args:
            db: il database su cui lavorare
        """
        cur = db.cursor()
        cur.execute("SELECT * FROM ALVEARI WHERE ID=?;", (self.ID, ))
        valori = cur.fetchone()
        print(valori)
        self.ID = valori[0]
        self.Nome = valori[1]
        self.Apiario = valori[2]
        self.DataCreazione = datetime.date(valori[5], valori[4], valori[3])
        self.Descrizione = valori[6]
        self.Razza = valori[7]
        self.Colore = valori[8]
        self.TipoArnia = valori[9]
        self.Provenienza = valori[10]
        self.AnnoRegina = valori[11]
        self.StatoFamiglia = valori[12]
        self.Posizione = valori[13]
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
        Apiario = apiario.Apiario()
        for val in valori:
            nome = Apiario.RecuperaNome(db, val[2])
            print("|{:>4}|{:>16}|{:>15}|".format(val[0], val[1], nome[0]))
        print("+====+================+===============+")

    def InterfacciaElencaPerApiario(self, db):
        """
        Interfaccia di elenco alveari di un apiario

        Fornisce un'interfaccia alla funzione di elenco degli alveari di un
        solo apiario

        Args:
            db: il database su cui lavorare
        """
        print("Elenco Alveari")
        print("==============\n\n")
        Apiario = apiario.Apiario()
        Apiario.InterfacciaElenca(db)
        self.Apiario = eval(input("Seleziona un apiario -> "))
        print("+====+================+")
        print("| ID |      Nome      |")
        print("+====+================+")
        valori = self.ElencaPerApiario(db)
        for val in valori:
            print("|{:>4}|{:>16}|".format(val[0], val[1]))
        print("+====+================+===============+")

    def InterfacciaElimina(self, db):
        """
        Interfaccia di eliminazione degli alveari

        Fornisce l'interfaccia per eliminare un alveare

        Args:
            db: il database su cui lavorare
        """
        self.InterfacciaElencaPerApiario(db)
        self.ID = eval(input("ID alveare da eliminare -> "))
        self.Elimina(db)

    def InterfacciaModifica(self, db):
        """
        Interfaccia di modifica degli alveari

        Fornisce l'interfaccia per modificare un alveare

        Args:
            db: il database su cui lavorare
        """
        cur = db.cursor()
        self.InterfacciaElencaPerApiario(db)
        self.ID = eval(input("ID alveare da modificare ->  "))
        self.SelezionaAlveare(db)
        print("1 - Nome: " + self.Nome)
        cur.execute("SELECT Nome FROM APIARI WHERE ID=?;", (self.Apiario, ))
        print("2 - Apiario: " + cur.fetchone()[0])
        print("3 - Data Creazione: " + self.DataCreazione.strftime("%d/%m/%Y"))
        print("4 - Descrizione: " + self.Descrizione)
        cur.execute("SELECT NOME FROM Razze WHERE ID=?;", (self.Razza, ))
        print("5 - Razza: " + cur.fetchone()[0])
        print("6 - Colore: " + self.Colore)
        cur.execute("SELECT Nome FROM TIPIARNIA WHERE ID=?;",
                    (self.TipoArnia,))
        print("7 - Tipo di Arnia: " + cur.fetchone()[0])
        cur.execute("SELECT PROVENIENZA FROM PROVENIENZE WHERE ID=?;",
                    (self.Provenienza, ))
        print("8 - Provenienza: " + cur.fetchone()[0])
        print("9 - Anno Regina: " + str(self.AnnoRegina))
        cur.execute("SELECT STATOFAMIGLIA FROM STATOFAMIGLIA WHERE ID=?;",
                    (self.StatoFamiglia, ))
        print("10 - Stato della Famiglia: " + cur.fetchone()[0])
        print("11 - Posizione: " + str(self.Posizione))
        scelta = eval(input("Valore da modificare -> "))
        if scelta == 1:
            self.Nome = input("Nome -> ")
        if scelta == 2:
            Apiario = apiario.Apiario()
            Apiario.InterfacciaElenca(db)
            self.Apiario = eval(input("ID Apiario -> "))
        if scelta == 3:
            data = input("Data di creazione (GG/MM/AAAA) -> ")
            data = data.split("/")
            self.DataCreazione = datetime.date(int(data[2]), int(data[1]),
                                               int(data[0]))
        if scelta == 4:
            self.Descrizione = input("Descrizione -> ")
        if scelta == 5:
            cur.execute("select * from razze;")
            valori = cur.fetchall()
            print("+====*========================+")
            print("| ID |          Razza         |")
            print("+====*========================+")
            for val in valori:
                print("|{:>4}|{:>25}|".format(val[0], val[1]))
            print("+====+========================+")
            self.Razza = eval(input("ID Razza -> "))
        if scelta == 6:
            self.Colore = input("Colore -> ")
        if scelta == 7:
            cur.execute("select * from tipiarnia;")
            valori = cur.fetchall()
            print("+====*========================+")
            print("| ID |       Tipi Arnia       |")
            print("+====*========================+")
            for val in valori:
                print("|{:>4}|{:>25}|".format(val[0], val[1]))
            print("+====+========================+")
            self.TipoArnia = eval(input("ID Tipo di Arnia -> "))
        if scelta == 8:
            cur.execute("select * from provenienze;")
            valori = cur.fetchall()
            print("+====*=========================+")
            print("| ID |       Provenienza       |")
            print("+====*=========================+")
            for val in valori:
                print("|{:>4}|{:>26}|".format(val[0], val[1]))
            print("+====+=========================+")
            self.Provenienza = eval(input("ID Provenienza -> "))
        if scelta == 9:
            self.AnnoRegina = eval(input("Anno nascita regina -> "))
        if scelta == 10:
            cur.execute("select * from statofamiglia;")
            valori = cur.fetchall()
            print("+====*=========================+")
            print("| ID |      Stato Famiglia     |")
            print("+====*=========================+")
            for val in valori:
                print("|{:>4}|{:>26}|".format(val[0], val[1]))
            print("+====+=========================+")
            self.StatoFamiglia = eval(input("ID Stato della famiglia -> "))
        if scelta == 11:
            self.Posizione = eval(input("Posizione -> "))
        self.Modifica(db)
