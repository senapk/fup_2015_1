import random
from os import system

def mostrar_lista(lista):
    ind = 0
    while ind < len(lista):
        if ind % 15 == 0:
            print ""
        print "%2d" %lista[ind],
        ind = ind + 1
    print ""

def mostrar_rack(lista):
    num = 1
    while num < 76:
        if (num - 1) % 15 == 0:
            print ""
        if num in lista:
            print "%2d" %(num),
        else:
            print "__",
        num = num + 1
    print ""

#opcao1
roleta = []
rack = []
num = 1
while num < 76:
    roleta.append(num)
    num = num + 1
#opcao2
#roleta = range(1, 75, 1)
system("clear")
mostrar_lista(roleta)

opcao = 1
while opcao != 0 and len(roleta) > 0:
    print "Escolha 1 para pedir bola e 0 para sair"
    opcao = input()
    if(opcao == 0):
        continue

    system("clear")


    ind = random.randint(0, len(roleta) - 1)
    print "Numero sorteado", roleta[ind]
    rack.append(roleta[ind])
    rack = sorted(rack)
    del roleta[ind]
    mostrar_rack(roleta)
    mostrar_rack(rack)


