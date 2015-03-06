
def calcular_situacao(media):
    if media >= 7.0:
        return "Aprovado"
    elif media < 4.0:
        return "Reprovado"
    else:
        return "Final"

def calcular_nota_final(media, final):
    media_final = (final + media)/2.0
    if media_final >= 5.0 and final >= 4:
        print "Aprovado com nota " + str(media_final)
    else:
        print "Reprovado na final"

nota1 = float(input("Nota 1 "))
nota2 = float(input("Nota 2 "))
nota3 = float(input("Nota 3 "))
media = float(nota1 + 2 * nota2 + 3 * nota3)/6
situacao = calcular_situacao(media)
if situacao == "Aprovado":
    print "Aprovado " + str(media)
elif situacao == "Reprovado":
    print "Reprovado " + str(media)
else:
    final = float(input("final\n"))
    calcular_nota_final(media ,final)



