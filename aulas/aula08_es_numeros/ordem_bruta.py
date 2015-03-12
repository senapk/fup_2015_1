P1 = input ("diga sua altura")
P2 = input ("diga sua altura")
P3 = input ("diga sua altura")

if P1 < P2 and P1 < P3:
    if P2 > P3:
        print "Menor Maior Meio"
    else:
        print "Menor Meio Maior"
elif P2 < P3 and P2 < P1:
    if P3 > P1:
        print "Meio Menor Maior"
    else:
        print "Maior Menor Meio"
else: #P3 < P2 and P3 < P1
    if P2 > P1:
        print "meio Maio Menor"
    else:
        print "maior meio Menor"
