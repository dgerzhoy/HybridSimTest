#include <stdio.h>
#include <stdlib.h>

using namespace HybridSim;

class Force_Writeback{
	public:
	
	Force_Writeback(void);
	

	int SEED = 1;
	uint64_t address;
	list<uint64_t, address> address_list;
	
	int TOTAL_ACCESSES = 1000;
	uint64_t MEMORY_SIZE = PAGE_SIZE*TOTAL_PAGES;
};
