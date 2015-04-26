def compara(n1, n2, n3):
    if n1 < n2 and n1 < n3:
        return "P"
    if n1 > n2 and n1 > n3:
        return "G"
    else:
        return "M"

lista = raw_input().split(" ")

p1 = int(lista[0])
p2 = int(lista[1])
p3 = int(lista[2])

print compara(p1, p2, p3),
print compara(p2, p1, p3),
print compara(p3, p1, p2)
