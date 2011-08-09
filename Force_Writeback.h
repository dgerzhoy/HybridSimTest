#include <HybridSystem.h>
#include <stdio.h>
#include <stdlib.h>


using namespace HybridSim;

class Force_Writeback{
	public:
	
	Force_Writeback(void);
	uint Forced_Rand_Writeback(HybridSystem::HybridSystem*);	

	int SEED;
	uint64_t address;
	list<uint64_t> address_list;
	
	int TOTAL_ACCESSES;
	uint64_t MEMORY_SIZE;
};
