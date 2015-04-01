horaA = raw_input().split(" ")
horaB = raw_input().split(" ")

ha = int(horaA[0])
ma = int(horaA[1])
sa = int(horaA[2])

hb = int(horaB[0])
mb = int(horaB[1])
sb = int(horaB[2])

###############

sega = ha * 3600 + ma * 60 + sa
segb = hb * 3600 + mb * 60 + sb

###############

if segb > sega:
    difs = segb - sega
###############
else:
    difs = segb - sega + 24 * 60 * 60

###############

hr = int(difs) / 3600
difs = difs - hr * 3600
mr = difs / 60
sr = difs % 60

#################

#hr = difs / 3600
#mr = (difs % 3600) / 60
#sr = (difs % 3600) % 60

print hr, mr, sr
print str(hr) + ":" + str(mr) + ":" + str(sr)

