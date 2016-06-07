class Alveare:

    def __init__(self):
        self.ID = 0
        self.Nome = ""
        self.Location = Apiario()
        self.GiornoCreazione = 0
        self.MeseCreazione = 0
        self.AnnoCreazione = 0
        self.Descrizione = ""
        self.Razza = ""
        self.Colore = ""
        self.TipoArnia = ""
        self.Provenienza = ""
        self.StatoFamiglia = ""
        self.Posizione = 0
        self.AnnoRegina = 0

    def Aggiungi(self, c):
        c.execute("select count(*) from Alveari;")
        if (len(c.fetchall()) < 1):
            self.ID = 0
        else:
            c.execute(
                "select ID from Alveari where id=(select MAX(ID) from Alveari);")
            self.ID = c.fetchone()
        self.Nome = eval(input("Nome -> "))
        try:
            campi = "ID, Nome, Apiario, GiornoCreazione, MeseCreazione, AnnoCreazione, Descrizione, Razza, Colore, TipoArnia, Provenienza, AnnoRegina, StatoFamiglia, Posizione"
            valori = ":id, :nome, :idapiario, :giornocreazione, :mesecreazione, :annocreazione, :descrizione, :razza, :colore, :tipoarnia, :provenienza, :annoregina, :statofamiglia, :posizione"
            dizvalori = {"id": self.ID,
                         ":nome": self.Nome,
                         ":idapiario": self.Location,
                         ":giornocreazione": self.GiornoCreazione,
                         ":mesecreazione": self.MeseCreazione,
                         ":annocreazione": self.AnnoCreazione,
                         ":descrizione": self.Descrizione,
                         ":razza": self.Razza,
                         ":colore": self.Colore,
                         ":tipoarnia": self.TipoArnia,
                         ":provenienza": self.Provenienza,
                         ":statofamiglia": self.StatoFamiglia,
                         ":annoregina": self.AnnoRegina,
                         ":posizione": self.Posizione}
            c.execute(
                "INSERT INTO Alveari(" + campi + ") VALUES (" + valori + "));", dizvalori)
        except:
            print("Problema nell'inserimento dei dati a database")
    
    def Elimina(self, c):
		for row in c.execute("select Alveari.ID, Alveari.Nome, Apiari.Nome from Alveari join Apiari on Apiari.id = Alveari.Apiario;"):
			print row
			print "Seleziona l'ID dell'alveare da eliminare"
			self.ID=input("ID ->")
			c.execute("DELETE FROM Alveari WHERE ID = "+self.ID+";")
