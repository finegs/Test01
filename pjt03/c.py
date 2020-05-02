<<<<<<< HEAD
import time

x = 0
def doit1(i):
    global x
    x = x + 1


list = range(100000)
t = time.time()
for i in list:
    doit1(i)

print ("%.3f" %
    (time.time() -t))
=======
#args05.py

import argparse

parser = argparse.ArgumentParser(description='prefix and version example', prefix_chars='-+')
parser.add_argument('-a', action="store_false", default=None, help='Turn A off')
parser.add_argument('+a', action="store_true", default=None, help='Turn A on')
parser.add_argument('--version', action='version', version='%(prog)s 1.0')
args = parser.parse_args()

print(args)


>>>>>>> 8bde84963db968610bd1162b70cdeb5a0fa1fb94
