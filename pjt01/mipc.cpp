

#include <cstring>
#include <iostream>
#include <map>
#include <mutex>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <boost/interprocess/allocators/allocator.hpp>

#include "mipc.hpp"

//using namespace std;
int MyIPC::TEST_MAP_SIZE = 100;

int MyIPC::testIPC(int argc, char *argv[])
{
   using namespace boost::interprocess;

   int _mapSize = TEST_MAP_SIZE;
   int segmentSize = 65536;

   // parse argument
   for (int i = 0; i < argc; i++)
   {
      if (strncmp("-S", argv[i], 2) || strncmp("--size", argv[i], 6))
      {
         if (argc < (i + 1))
         {
            std::cerr << "illegal argument : " << argv[i];
            exit(-1);
         }
         _mapSize = atoi(argv[i + 1]);
      }
   }

   //Remove shared memory on construction and destruction
   struct shm_remove
   {
      shm_remove() { shared_memory_object::remove("MySharedMemory"); }
      ~shm_remove() { shared_memory_object::remove("MySharedMemory"); }
   } remover;

   //Shared memory front-end that is able to construct objects
   //associated with a c-string. Erase previous shared memory with the name
   //to be used and create the memory segment at the specified address and initialize resources
   managed_shared_memory segment(create_only, "MySharedMemory" //segment name
                                 ,
                                 segmentSize); //segment size in bytes

   //Note that map<Key, MappedType>'s value_type is std::pair<const Key, MappedType>,
   //so the allocator must allocate that pair.
   typedef int KeyType;
   typedef float MappedType;
   typedef std::pair<const int, float> ValueType;

   //Alias an STL compatible allocator of for the map.
   //This allocator will allow to place containers
   //in managed shared memory segments
   typedef allocator<ValueType, managed_shared_memory::segment_manager>
       ShmemAllocator;

   //Alias a map of ints that uses the previous STL-like allocator.
   //Note that the third parameter argument is the ordering function
   //of the map, just like with std::map, used to compare the keys.
   typedef map<KeyType, MappedType, std::less<KeyType>, ShmemAllocator> MyMap;

   //Initialize the shared memory STL-compatible allocator
   ShmemAllocator alloc_inst(segment.get_segment_manager());

   //Construct a shared memory map.
   //Note that the first parameter is the comparison function,
   //and the second one the allocator.
   //This the same signature as std::map's constructor taking an allocator
   MyMap *mymap =
       segment.construct<MyMap>("MyMap") //object name
       (std::less<int>()                 //first  ctor parameter
        ,
        alloc_inst); //second ctor parameter

   if (!mymap)
   {
      std::cerr << "MyMap allocating failed : size = " << _mapSize
                << ", segmentSize = " << segmentSize;
      exit(-2);
   }

   //Insert data in the map
   for (int i = 0; i < _mapSize; ++i)
   {
      //mymap->insert(std::pair<const int, float>(i, (float)i));
      //      mymap->[i] = (float)i*i;
      (*mymap).emplace(i, (float)i * i);
   }

   // Get Data in the map
   float vf = .0;
   for (int i = 0; i < _mapSize; ++i)
   {
      //   std::cout << "mymap[" << i << "] : " << mymap->find(i)->first << std::endl;
      vf = (float)(*mymap)[i];
      std::cout << "mymap[" << i << "] = "
                << vf
                << ", match= " << std::boolalpha << (vf == (float)i * i) << std::endl;
   }
   return 0;
}

int MyIPC::testIPCMapFile(int argc, char *argv[], std::vector<std::string> &params)
{

   using namespace boost::interprocess;

   //Define file names
   const char *FileName = "file.bin";
   const std::size_t FileSize = 10000;

   bool isSvr = std::end(params) != std::find_if(std::begin(params), 
		   						std::end(params), 
								[&](std::string &s) {
                   if ("-s" == s || "-S" == s)
                      return true;
                   return false;
                });

   //   if(argc == 1){ //Parent process executes this
   if (isSvr)
   {    //Parent process executes this
      { //Create a file
         file_mapping::remove(FileName);
         std::filebuf fbuf;
         fbuf.open(FileName, std::ios_base::in | std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
         //Set the size
         fbuf.pubseekoff(FileSize - 1, std::ios_base::beg);
         fbuf.sputc(0);
      }

      //Remove on exit
      struct file_remove
      {
         file_remove(const char *FileName)
             : FileName_(FileName) {}
         ~file_remove() { file_mapping::remove(FileName_); }
         const char *FileName_;
      } remover(FileName);

      //Create a file mapping
      file_mapping m_file(FileName, read_write);

      //Map the whole file with read-write permissions in this process
      mapped_region region(m_file, read_write);

      //Get the address of the mapped region
      void *addr = region.get_address();
	  std::size_t size = region.get_size();

      //Write all the memory to 1
      std::memset(addr, 1, size);

      //Launch child process
      std::string s(argv[0]);
//      s += " child ";
      s += " -S ";
      if (0 != std::system(s.c_str()))
         return 1;
   }
   else
   {    //Child process executes this
      { //Open the file mapping and map it as read-only
         file_mapping m_file(FileName, read_only);

         mapped_region region(m_file, read_only);

         //Get the address of the mapped region
         void *addr = region.get_address();
         std::size_t size = region.get_size();

         //Check that memory was initialized to 1
         const char *mem = static_cast<char *>(addr);
         for (std::size_t i = 0; i < size; ++i)
            if (*mem++ != 1)
               return 1; //Error checking memory
      }
      { //Now test it reading the file
         std::filebuf fbuf;
         fbuf.open(FileName, std::ios_base::in | std::ios_base::binary);

         //Read it to memory
         std::vector<char> vect(FileSize, 0);
         fbuf.sgetn(&vect[0], std::streamsize(vect.size()));

         //Check that memory was initialized to 1
         const char *mem = static_cast<char *>(&vect[0]);
         for (std::size_t i = 0; i < FileSize; ++i)
            if (*mem++ != 1)
               return 1; //Error checking memory
      }
   }

   return EXIT_SUCCESS;
}

std::string MyIPC::q_popCmd() {
	std::lock_guard<std::mutex> guard(q_cmdQueue_mtx);
	std::string cmd = MyIPC::cmdQueue.front();
	cmdQueue.pop();
	return cmd;
}

void MyIPC::q_pushCmd(const std::string& newCmd) {
	std::lock_guard<std::mutex> guard(q_cmdQueue_mtx);
	MyIPC::cmdQueue.push(newCmd);
}

bool MyIPC::q_empty() {
	return MyIPC::cmdQueue.empty();
}

