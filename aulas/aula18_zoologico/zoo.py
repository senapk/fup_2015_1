
zoo = raw_input().split(" ")
especies = []

for animal in zoo:
    if animal not in especies:
        especies.append(animal)

########### com booleano de controle
cont = 0

for i in range(len(zoo)):
    iguais = False
    for j in range(i):
        if zoo[i] == zoo[j]:
            iguais = True
            break
    if not iguais:
        cont += 1

################ com funcao

cont = 0

def existe_ate(lista, pos):
    for i in range(pos)
        if lista[i] == lista[pos]
            return True
    return False

for i in range(len(zoo)):
    if not existe_ate(zoo, i)
        cont += 1


########################
i = 0
while i < len(zoo):
    j = i + 1
    while j < len(zoo):
        if zoo[i] == zoo[j]
            del zoo[j]
        else:
            j += 1
    i += 1



