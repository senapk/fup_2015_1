
lista = raw_input().split(" ")

mais_rep = []
mais_rep.append(lista[0])
record = lista.count(lista[0])

for i in range(1, len(lista)):
    qtd = lista.count(lista[i])
    if(qtd > record):
        record = qtd
        mais_rep = []
        mais_rep.append(lista[i])
    elif(qtd == record):
        if(lista[i] not in mais_rep):
            mais_rep.append(lista[i])

for elem  in mais_rep:
    print elem,


