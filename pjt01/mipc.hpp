
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
#include <queue>
#include <vector>
#include <mutex>

class MyIPC
{
public:
	static int TEST_MAP_SIZE;

public:
	static int testIPC(int argc, char *argv[]);
	static int testIPCMapFile(int argc, char *argv[], std::vector<std::string> &params);

	static std::string popCmd();
	static void pushCmd(const std::string& newCmd);
	static bool isEmpty();
	
private:
	static void initQueue();
	static std::queue<std::string> cmdQueue;
	static std::mutex cmdQueue_mtx;
};

#endif
