lista = raw_input().split(" ")

lista_int = []
for elem in lista:
    lista_int.append(int(elem))

maior = lista_int[0]
for elem in lista_int:
    if elem > maior:
        maior = elem

print maior
