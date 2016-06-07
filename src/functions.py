import Apiario

def InizializzaDB(conn):
    c = conn.cursor()
    c.execute('''CREATE TABLE TipiTrattamento(ID INT PRIMARY KEY NOT NULL,
    NomeTrattamento TEXT NOT NULL, Descrizione TEXT NOT NULL,
    Posologia TEXT NOT NULL)''')
    c.execute('''CREATE TABLE Apiari(ID INT PRIMARY KEY NOT NULL,
    Nome TEXT NOT NULL, Posizione TEXT)''')
    c.execute('''CREATE TABLE TipiArnia(ID INT PRIMARY KEY NOT NULL,
    Nome TEXT NOT NULL, NTelaini INT NOT NULL)''')
    c.execute('''CREATE TABLE Razze(ID INT PRIMARY KEY NOT NULL,
    Nome TEXT NOT NULL)''')
    c.execute('''CREATE TABLE Provenienze(ID INT PRIMARY KEY NOT NULL,
    Provenienza TEXT NOT NULL)''')
    c.execute('''CREATE TABLE StatoFamiglia(ID INT PRIMARY KEY NOT NULL,
    StatoFamiglia TEXT NOT NULL)''')
    c.execute('''CREATE TABLE Nutrizioni(ID INT PRIMARY KEY NOT NULL,
    Nutrizione TEXT NOT NULL)''')
    c.execute('''CREATE TABLE ScopiNutrizione(ID INT PRIMARY KEY NOT NULL,
    Scopo TEXT NOT NULL)''')
    c.execute('''CREATE TABLE Alveari(ID INT PRIMARY KEY NOT NULL,
    Nome TEXT NOT NULL, Apiario INT NOT NULL, GiornoCreazione INT NOT NULL,
    MeseCreazione INT NOT NULL, AnnoCreazione INT NOT NULL, Descrizione TEXT,
    Razza INT NOT NULL, Colore TEXT, TipoArnia INT NOT NULL,
    Provenienza INT NOT NULL, AnnoRegina INT NOT NULL,
    StatoFamiglia INT NOT NULL, Posizione INT NOT NULL,
    FOREIGN KEY(Apiario) REFERENCES Apiari(ID),
    FOREIGN KEY(Razza) REFERENCES Razze(ID),
    FOREIGN KEY(TipoArnia) REFERENCES TipiArnia(ID),
    FOREIGN KEY(Provenienza) REFERENCES Provenienze(ID),
    FOREIGN KEY(StatoFamiglia) REFERENCES StatoFamiglia(ID))''')
    c.execute('''CREATE TABLE TrattamentiFitosanitari(
        ID INT PRIMARY KEY NOT NULL, Data INT NOT NULL,
        Cassetta INT NOT NULL, Tipo TEXT NOT NULL, Dosi TEXT NOT NULL,
        FinoAl TEXT NOT NULL, FOREIGN KEY(Cassetta) REFERENCES Alveari(ID))''')
    c.execute('''CREATE TABLE Materiali(ID INT PRIMARY KEY NOT NULL,
    Nome TEXT NOT NULL, Descrizione TEXT NOT NULL, Quantita TEXT NOT NULL)''')
    c.execute('''CREATE TABLE Clienti(ID INT PRIMARY KEY NOT NULL,
    Nome TEXT NOT NULL, Cognome TEXT, RagioneSociale TEXT, Indirizzo TEXT,
    CAP TEXT, Citta TEXT, Provincia TEXT, Telefono TEXT, Fax TEXT,
    Cellulare TEXT, Email TEXT, CFPIVA TEXT, Note TEXT)''')
    c.execute('''CREATE TABLE Entrate(ID INT PRIMARY KEY NOT NULL,
    Data INT NOT NULL, Cliente INT NOT NULL, Descrizione TEXT NOT NULL,
    Imponibile REAL NOT NULL, IVA REAL NOT NULL, Importo REAL NOT NULL,
    FOREIGN KEY(Cliente) REFERENCES Clienti(ID))''')
    c.execute('''CREATE TABLE Fornitori(ID INT PRIMARY KEY NOT NULL,
    RagioneSociale TEXT NOT NULL, Nome TEXT, Cognome TEXT,
    Indirizzo TEXT NOT NULL, CAP TEXT NOT NULL, Citta TEXT NOT NULL,
    Provincia TEXT NOT NULL, Telefono TEXT, Fax TEXT, Email TEXT,
    CFPIVA TEXT NOT NULL, Note TEXT)''')
    c.execute('''CREATE TABLE Spese(ID INT PRIMARY KEY NOT NULL,
    Data INT NOT NULL, Descrizione TEXT NOT NULL, Fornitore INT NOT NULL,
    Imponibile REAL NOT NULL, IVA REAL NOT NULL, Importo REAL NOT NULL,
    FOREIGN KEY(Fornitore) REFERENCES Fornitori(ID))''')
    c.execute('''CREATE TABLE Versioni (ID INT PRIMARY KEY NOT NULL,
    Versione TEXT NOT NULL);''')
    c.execute('''CREATE TABLE Visite (ID INT PRIMARY KEY NOT NULL,
    Cassetta INT NOT NULL, Giorno INT NOT NULL, Mese INT NOT NULL,
    Anno INT NOT NULL, Ora INT, Minuti INT, Meteo TEXT, Temperatura REAL,
    TelainiTotali INT NOT NULL, TelainiOccupati INT NOT NULL,
    TelainiCovata INT, CelleReali INT, Melari BOOL NOT NULL, Regina BOOL,
    CovataFresca BOOL, TipoCovata TEXT, Comportamento TEXT NOT NULL,
    LavoriEffettuati TEXT NOT NULL, Nutrizione INT NOT NULL,
    ScopoNutrizione INT, VarroaCassetto BOOL, VarroaApi BOOL,
    ConteggioVarroa INT, Virosi BOOL, TipoVirosi TEXT, LarveMorte BOOL,
    ApiMorteEntrata BOOL, PeriodoProssimoLavoro1 TEXT, ProssimoLavoro1 TEXT,
    PeriodoProssimoLavoro2 TEXT, ProssimoLavoro2 TEXT,
    PeriodoProssimoLavoro3 TEXT, ProssimoLavoro3 TEXT, Note TEXT,
    Fioriture TEXT, StatoFamiglia INT NOT NULL, VisitaCompleta BOOL NOT NULL,
    FOREIGN KEY(Cassetta) REFERENCES Alveari(ID),
    FOREIGN KEY(Nutrizione) REFERENCES Nutrizioni(ID),
    FOREIGN KEY(ScopoNutrizione) REFERENCES ScopiNutrizione(ID),
    FOREIGN KEY(StatoFamiglia) REFERENCES StatoFamiglia(ID));''')
    c.execute('''INSERT INTO Versioni(ID,Versione) VALUES (0,0.1);''')
    c.execute('''INSERT INTO Clienti(ID, Nome, Cognome, RagioneSociale,
    Indirizzo, CAP, Citta, Provincia, Telefono, Fax, Cellulare, Email, CFPIVA,
    Note) VALUES (0, 'Generico', NULL, NULL, NULL, NULL, NULL, NULL, NULL,
    NULL, NULL, NULL, NULL, NULL)''')
    c.execute('''INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(0, 'Assente')''')
    c.execute(''' INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(1,'Candito')''')
    c.execute('''INSERT INTO Nutrizioni(ID, Nutrizione)
    VALUES(2,'Candito con polline');''')
    c.execute('''INSERT INTO Nutrizioni(ID, Nutrizione) VALUES(3,'Sciroppo')''')
    c.execute('''INSERT INTO Nutrizioni(ID, Nutrizione)
    VALUES(4,'Sciroppo con Apiherb')''')
    c.execute('''INSERT INTO ScopiNutrizione(ID, Scopo)
    VALUES(0,'Emergenza');''')
    c.execute('''INSERT INTO ScopiNutrizione(ID, Scopo)
    VALUES(1,'Invernale')''')
    c.execute('''INSERT INTO StatoFamiglia(ID,StatoFamiglia)
    VALUES (0, 'Critico');''')
    c.execute('''INSERT INTO StatoFamiglia(ID,StatoFamiglia)
    VALUES (1, 'Insufficiente');''')
    c.execute('''INSERT INTO StatoFamiglia(ID,StatoFamiglia)
    VALUES (2, 'Sufficiente');''')
    c.execute('''INSERT INTO StatoFamiglia(ID,StatoFamiglia)
    VALUES (3, 'Buono');''')
    c.execute('''INSERT INTO StatoFamiglia(ID,StatoFamiglia)
    VALUES (4, 'Ottimo')''')
    c.execute('''INSERT INTO Razze(ID,Nome)
    VALUES (0, 'Apis Mellifera Ligustica');''')
    c.execute('''INSERT INTO Razze(ID,Nome)
    VALUES (1, 'Apis Mellifera Carnica');''')
    c.execute('''INSERT INTO Razze(ID,Nome)
    VALUES (2, 'Apis Mellifera Sicula')''')
    c.execute('''INSERT INTO Provenienze(ID, Provenienza)
    VALUES (0, 'Sciame Acquistato');''')
    c.execute('''INSERT INTO Provenienze(ID, Provenienza)
    VALUES (1, 'Sciame Naturale');''')
    c.execute('''INSERT INTO Provenienze(ID, Provenienza)
    VALUES (2, 'Sciame Naturale');''')
    c.execute('''INSERT INTO Provenienze(ID, Provenienza)
    VALUES (3, 'Divisione da famiglia')''')
    c.execute('''INSERT INTO TipiArnia(ID, Nome, NTelaini)
    VALUES (0, 'D.B. 6', 6);''')
    c.execute('''INSERT INTO TipiArnia(ID, Nome, NTelaini)
    VALUES (1, 'D.B. 8', 8);''')
    c.execute('''INSERT INTO TipiArnia(ID, Nome, NTelaini)
    VALUES (2, 'D.B. 10', 10);''')
    c.execute('''INSERT INTO TipiArnia(ID, Nome, NTelaini)
    VALUES (3, 'D.B. 12', 12);''')
    c.execute('''INSERT INTO TipiArnia(ID, Nome, NTelaini)
    VALUES (4, 'Polistirolo 6', 6);''')
    c.execute('''INSERT INTO TipiArnia(ID, Nome, NTelaini)
    VALUES (5, 'Pigliasciami 6', 6)''')
    c.execute('''INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione,
    Posologia) VALUES (0, 'Apiguard', 'Timolo in Gel',
    'Due cicli a 15 giorni di distanza');''')
    c.execute('''INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione,
    Posologia) VALUES (1, 'ApiLifeVar', 'Timolo in spugne',
    'Quattro cicli a 7 giorni di distanza');''')
    c.execute('''INSERT INTO TipiTrattamento(ID, NomeTrattamento, Descrizione,
    Posologia) VALUES (2, 'ApiBioxal gocciolato', 'Acido Ossalico gocciolato',
    'Due cicli da 5ml a telaino ogni 21 giorni')''')
    conn.commit()
    c.close()


def WIP():
    print("Work in Progress")


def AmministrazioneAlveari(scelta, conn):
    if scelta != 0:
        print("1 - Aggiungi un alveare")
        print("2 - Modifica un alveare")
        print("3 - Elimina un alveare")
        print("4 - Visualizza gli alveari")
        print("0 - Torna indietro")
        scelta = input("Scelta -> ")
        if scelta == 1:
            WIP()
        if scelta == 2:
            WIP()
        if scelta == 3:
            WIP()
        if scelta == 4:
            WIP()
        AmministrazioneAlveari(scelta, conn)


def AmministrazioneApiari(scelta, conn):
    apiario = Apiario.Apiario()
    c = conn.cursor()
    if scelta != 0:
        print("1 - Aggiungi un apiario")
        print("2 - Modifica un apiario")
        print("3 - Elimina un apiario")
        print("4 - Visualizza gli apiario")
        print("0 - Torna indietro")
        scelta = input("Scelta -> ")
        if scelta == 1:
            apiario.Aggiungi(c)
        if scelta == 2:
            WIP()
        if scelta == 3:
            WIP()
        if scelta == 4:
            WIP()
        AmministrazioneApiari(scelta, conn)


def AmministrazioneVisite(scelta, conn):
    if scelta != 0:
        print("1 - Aggiungi una visita")
        print("2 - Modifica una visita")
        print("3 - Elimina una visita")
        print("4 - Visualizza tutte le visite")
        print("0 - Torna indietro")
        scelta = input("Scelta -> ")
        if scelta == 1:
            WIP()
        if scelta == 2:
            WIP()
        if scelta == 3:
            WIP()
        if scelta == 4:
            WIP()
        AmministrazioneVisite(scelta, conn)


def MenuPrincipale(scelta, conn):
    if scelta == 0:
        print("Uscita")
    else:
        print("1 - Amministrazione Alveari")
        print("2 - Amministrazione Apiari")
        print("3 - Amministrazione Visite")
        print("4 - Amministrazione Interventi Fitosanitari")
        print("5 - Amministrazione Magazzino")
        print("0 - Esci")
        scelta = input("Scelta -> ")
        if scelta == 1:
            AmministrazioneAlveari(100, conn)
        if scelta == 2:
            AmministrazioneApiari(100, conn)
        if scelta == 3:
            AmministrazioneVisite(100, conn)
        if scelta == 4:
            WIP()
        if scelta == 5:
            WIP()
        MenuPrincipale(scelta, conn)
