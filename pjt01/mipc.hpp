
#ifndef __MIPC_HPP
#define __MIPC_HPP

class MyIPC {
	public:
		static int TEST_MAP_SIZE;
	public:
		static int testIPC(int _mapSize = TEST_MAP_SIZE);
};


#endif
