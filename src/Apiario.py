class Apiario:
    def __init__(self):
        self.ID = 0
        self.Nome = ""
        self.Posizione = ""
    def Aggiungi(self, c):
        c.execute("select count(*) from Apiari")
        if (c.fetchone() < 1):
            self.ID = 0
            print 1
        else:
            print 2
            sqlstring = "select ID from Apiari "
            sqlstring = sqlstring + "where id=(select MAX(ID) from Apiari);"
            c.execute(sqlstring)
            self.ID = c.fetchone()
        self.Nome = raw_input("Nome -> ")
        self.Posizione = raw_input("Posizione -> ")
        try:
            campi = "ID,Nome,Posizione"
            valori = ":id, :nome, :posizione"
            dizvalori = {":id": self.ID,
            ":nome": self.Nome,
            ":posizione": self.Posizione}
            sqlstring = "insert into Apiari(" + campi
            sqlstring = sqlstring + ") values (" + valori + ");"
            print self.ID
            print campi
            print valori
            print dizvalori
            print sqlstring
            c.execute(sqlstring, dizvalori)
        except:
            print "\n\nProblema nell'inserimento dell'apiario\n\n"
