#

import zmq

def main():
	#ZMQ connection
	# url = "tcp://127.0.0.1:5550"
	url = "tcp://*:5550"
	ctx = zmq.Context()
	# socket = ctx.socket(zmq.SUB)
	socket = ctx.socket(zmq.REP)
	socket.bind(url) #subscriber create ZeroMQ Socket
	# socket.setsocket(zmq.SUBSCRIBE, ''.encode('ascii')) # any topic

	print(f'Sub bound to :{url}\nWaiting for data...')
	while True:
		#wait for publisher data
		# topic,msg = socket.recv_multipart()
		# print(f'On topic{topic},received:{msg}')
		
		message = socket.recv()
		print(f'{"REQ" : "{msg}"}')
		
		time.sleep(1)
		rep = f'{"REP" : "{msg}"}'
		socket.send(b'{rep}')


		


if __name__ == "__main__":
	main()


