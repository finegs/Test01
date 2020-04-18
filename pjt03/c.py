#args05.py

import argparse

parser = argparse.ArgumentParser(description='prefix and version example', prefix_chars='-+')
parser.add_argument('-a', action="store_false", default=None, help='Turn A off')
parser.add_argument('+a', action="store_true", default=None, help='Turn A on')
parser.add_argument('--version', action='version', version='%(prog)s 1.0')
args = parser.parse_args()

print(args)


