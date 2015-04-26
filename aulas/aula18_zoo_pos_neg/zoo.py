

1 3 4 2 4 2 1 3 4 1 2 4 2 5 7 2 7

szoo = raw_input().split(" ")
zoo = []
for elem in szoo:
    zoo.append(elem)

especies = []
for elem in zoo:
    if abs(elem) not in especies:
        especies.append(abs(elem))

print len(especies)


######################3
cont = 0
for i in range(len(zoo)):
    eh_primeiro = True
    for j in range(i):

        if zoo[i] == zoo[j]:
            eh_primeiro = False
            break
    if eh_primeiro:
        cont += 1
