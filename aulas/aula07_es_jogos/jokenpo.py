#/usr/bin/env python2

opcao1 = raw_input("jog1\n")
opcao2 = raw_input("jog2\n")

if opcao1 == opcao2:
    print "empate"
elif (opcao1 == "pedra" and opcao2 == "tesoura") or \
    (opcao1 == "papel" and opcao2 == "pedra") or \
    (opcao1 == "tesoura" and opcao2 == "papel"):
    print "jog1"
else:
    print "jog2"
