#!/usr/bin/env python
# -*- coding: utf-8 -*-

tipos = raw_input().split(" ")

mae = tipos[0]
pai = tipos[1]
filho = tipos[2]
if len(mae) == 1:
	mae = "O" + mae
if len(pai) == 1:
	pai = "O" + pai
if len(filho) == 1:
	filho = "O" + filho

a = mae[0]
b = mae[1]
c = pai[0]
d = pai[1]
e = filho[0]
f = filho[1]

if (e == a or e == b) and (f == c or f == d):
	print "Sim"
elif (e == c or e == d) and (f == a or f == b):
	print  "Sim"
else:
	print "Nao"
	
	
	