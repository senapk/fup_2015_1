

slista = raw_input().split(" ")
lista = []
for elem in slista:
    lista.append(int(elem))

impares = []
pares = []
for x in lista:
    if x % 2 == 1:
        impares.append(x)
    else:
        pares.append(x)

for x in impares:
    print x,
print ""
for x in pares:
    print x,

