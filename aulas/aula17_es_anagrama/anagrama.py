



"""
abb
bab

abcddddb
abcbdddd
"""

def contar(letra, palavra):
    cont = 0
    for x in palavra:
        if x == letra:
            cont += 1
    return cont

palavra1 = raw_input()
palavra2 = raw_input()

iguais = True
for x in palavra1:
    if contar(x, palavra1) != contar(x, palavra2):
        iguais = False
        break
if iguais:
    print "sim"
else:
    print "nao"






