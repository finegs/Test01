import os
import argparse
#import timeit

from datetime import datetime

# code_to_test = """

parser = argparse.ArgumentParser()
parser.add_argument('-cnt', nargs = '?', default=10, help='Count to generate')
parser.add_argument('-funit', nargs = '?', default=100, help='Flush Unit Size')
parser.add_argument('-usefstr', nargs = '?', default=False, help='Use f-string')
parser.add_argument('-outputfile', nargs = '?', default='out.json', help='Output file')
args = parser.parse_args()

cnt = int(args.cnt)
funit = int(args.funit)
usefstr = args.usefstr
outputfile = args.outputfile


print(f'{datetime.now()} output file open started: \"outputfile\":{outputfile}')
f = open(outputfile, 'w')
print(f'{datetime.now()} output file opened: \"outputfile\":{outputfile}')

f.write('[')

tstart = datetime.now()

if not usefstr:
	print(f'{datetime.now()} starting : \"usefstr\":{usefstr}')
	for idx in range(0,cnt,1):
		s = '\n'
		if idx > 0:	s = ","
		s += '{\"id\":' + str(idx)
		s += ',\"name\":\"name_' + str(idx) + '\"'
		s += ',\"address\":\"addr_' + str(idx) + '\"}'
		f.write(s)
		if (idx % funit) == 0: f.flush()
	print(f'{datetime.now()} completed : \"usefstr\":{usefstr}');
	
else:
	print(f'{datetime.now()} starting : \"usefstr\":{usefstr}')
	for idx in range(0, cnt, 1):
		s = '\n'
		if(idx>0):	s+=','
		s += f'{{\"id\":{idx}, \"name\":\"name_{idx}\", \"address\":\"addr_{idx}\"}}'
		f.write(s)
		if (idx % funit) == 0: f.flush()
	print(f'{datetime.now()} completed : \"usefstr\":{usefstr}');


f.write('\n]')
f.flush()
f.close()

tend = datetime.now()

print(f'{datetime.now()} use f-string\t: {usefstr}');
print(f'{datetime.now()} elapsed_time\t: {tend-tstart}');
print(f'{datetime.now()} cnt\t\t: {cnt:,}');
print(f'{datetime.now()} funit\t: {funit:,}');

# """
# 100cycle execution and dedive 100
# elapsed_time = timeit.timeit(code_to_test, number=100)/100

#elapsed_time = timeit.timeit(code_to_test, number=1)/1
#print('elapsed time : {0}, cnt : {1}'.format(elapsed_time, cnt))

