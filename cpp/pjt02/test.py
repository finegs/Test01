import sys
import ctypes

def f1(a,b):
    a+=1
    b+=1
    return a+b


a = 100
b = 200

print "f1(100,200) = " , f1(a,b)
print "a = ", a , ", b = ", b
