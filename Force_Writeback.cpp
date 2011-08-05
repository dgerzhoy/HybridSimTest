#include "Force_Writeback.h"

int main() {

	srand(SEED);

	for (int i = 0; i <= TOTAL_ACCESSES; i++){
		address = (uint64_t)(rand()%MEMORY_SIZE);
		address_list.push_back(address)i;
		
		addTransaction(1, address);
	}	

	for(list<address_list>::iterator it = address_list.begin; it !=address_list.end; ++it){
	
		addTransaction(1,(*it));

	}

}
