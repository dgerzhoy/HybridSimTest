#include "Force_Writeback.h"

Force_Writeback::Force_Writeback()
{
	SEED = 1;
	TOTAL_ACCESSES = 1000;
	MEMORY_SIZE = PAGE_SIZE*TOTAL_PAGES;
}

uint Force_Writeback::Forced_Rand_Writeback(HybridSystem::HybridSystem *mem) {

	srand(SEED);

	for (int i = 0; i <= TOTAL_ACCESSES; i++){
		address = (uint64_t)(rand()%MEMORY_SIZE);
		address_list.push_back(address);
		
		mem->addTransaction(1, address);
	}	

	for(int i = 0; i <=TOTAL_ACCESSES; i++){
		mem->update();
	}

	for(list<uint64_t>::iterator it = address_list.begin(); it !=address_list.end(); ++it){
	
		mem->addTransaction(1,(*it));

	}
	
	for(int i=0; i<= TOTAL_ACCESSES; i++){
		mem->update();
	}
}
