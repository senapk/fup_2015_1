
def contar(elem, lista):
    cont = 0
    for x in lista:
        if x == elem:
            cont += 1
    return cont


def existe(elem, lista):
    for x in lista:
        if x == elem:
            return True
    return False


lista = [ 1, 1, 1, 3, 3, 3, 2, 5]

dif = []
for elem in lista:
    if not existe(elem, dif):
        dif.append(elem)

cont = []
for elem in dif:
    cont.append(contar(elem, lista))

maior = cont[0]
for elem in cont:
    if elem > maior:
        maior = elem

mais_rep = []
for i in range(len(dif)):
    if cont[i] == maior:
        mais_rep.append(dif[i])

print mais_rep

