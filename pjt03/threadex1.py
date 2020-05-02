#threadex1.py

import threading, time


class MyThread(threading.Thread):
	def run(self):
		for i in range(10):
			print(f'id={self.getName()} -> {i}')
			time.sleep(0)

def myrun(id):
	for i in range(10):
		print(f'index:{i}')
		time.sleep(0)

threads=[]

for i in range(2):
#	th = threading.Thread(target=myrun, args=(i,))
	th = MyThread()
	th.start()
	threads.append(th)

for th in threads:
	th.join()

print(f'Exiting')
