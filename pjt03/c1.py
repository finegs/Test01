import time
x = 0
def doit2(list):
    global x
    for i in list:
        x = x + 1

list = range(100000)
t = time.time()
doit2(list)
print("%.3f" %
        (time.time()-t))
