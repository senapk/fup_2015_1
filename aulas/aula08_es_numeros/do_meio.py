a = input()
b = input()
c = input()

if (a < b and b < c) or (c < b and b < a):
    print "sim"
else:
    print "nao"

