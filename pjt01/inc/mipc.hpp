
#ifndef __MIPC_HPP
#define __MIPC_HPP

#include <iostream>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/file_mapping.hpp>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <cstddef>
#include <cstdlib>

class MyIPC {
	public:
		static int TEST_MAP_SIZE;
	public:
		static int testIPC(int _mapSize = TEST_MAP_SIZE);
		static int testIPCMapFile(int argc, char* argv[], std::vector<std::string>& params);
};

#endif
