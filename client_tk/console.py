import cli

c = cli.cli()
name = input("Login: ")
adress = input("Adress: ")
c.initialize(name, adress)
c.send("test string")
