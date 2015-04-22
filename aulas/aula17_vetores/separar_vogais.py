
texto = raw_input()
vogais = ""
cons = ""

for x in texto:
    if x != " ":
        if x in "aeiouAEIOU":
            vogais += x
        else:
            cons += x

print vogais
print cons

