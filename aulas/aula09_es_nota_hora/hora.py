


inicio = raw_input().split(":")
fim  = raw_input().split(":")

h1 = int(inicio[0])
m1 = int(inicio[1])
s1 = int(inicio[2])

h2 = int(fim[0])
m2 = int(fim[1])
s2 = int(fim[2])

soma1 = h1 * 60 * 60 + m1 * 60 + s1
soma2 = h2 * 60 * 60 + m2 * 60 + s2
dif = soma2 - soma1

hf = int(dif / (60 * 60))
dif = dif - hf * (60 * 60)
mf = int(dif / 60)
sf = int(dif % 60)

print str(hf) + ":" + str(mf) + ":" + str(sf)


