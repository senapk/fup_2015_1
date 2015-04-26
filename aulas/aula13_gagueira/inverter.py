lista = raw_input().split(" ")
del lista[0]
#modo 1 python
#lista1 = lista[::-1]
#for x in lista1:
    #print x,

#modo 2
#ind = len(lista) - 1
#while ind >= 0:
    #print lista[ind],
    #ind -= 1

#modo 3
for i in range(len(lista) - 1, -1, -1):
    print lista[i],
