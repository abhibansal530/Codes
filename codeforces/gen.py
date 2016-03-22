#!/usr/bin/python
import random as r
m=200000
vm=1000000
n=r.randrange(1,m)
print n
for i in range(0,n):
    v=r.randrange(-1*vm,vm);
    print v
q=r.randrange(1,m)
print q
for i in range(0,q):
    op=r.randrange(0,2)
    if(op==0):
        l=r.randrange(0,n)
        l2=r.randrange(0,n)
        print l,l2
    else:
        l=r.randrange(0,n)
        l2=r.randrange(0,n)
        v=r.randrange(-1*vm,vm)
        print l,l2,v

