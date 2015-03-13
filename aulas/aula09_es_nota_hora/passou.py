


notas = raw_input().split(" ")
ap1 = float(notas[0])
ap2 = float(notas[1])
ap3 = float(notas[2])
nf  = float(notas[3])

media = (ap1 + ap2 + ap3)/3.0
if media >= 7.0:
    print "Aprovado"
elif media < 4.0:
    print "Reprovado"
else:
    media = (media + nf)/2.0
    if nf >= 4.0 and media >= 5.0:
        print "Aprovado"
    else:
        print "Reprovado"
print media


