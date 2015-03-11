
n1 = input("Digite nota 1\n")
n2 = input("Digite nota 2\n")
n3 = input("Digite nota 3\n")

media = float(n1 + n2 + n3)/3.0

if media >= 7.0:
    print "Aprovado"
elif media < 4.0:
    print "Reprovado"
else:
    print "\nFinal " + str(media)
    final = input("Digite a final\n")
    if (media + final) >= 10.0 and final >=4:
        print "Aprovado"
    else:
        print "Reprovado"

