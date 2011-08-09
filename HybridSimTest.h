#include <iostream>
#include <time.h>

#include <HybridSystem.h>
#include "Miss_Rate.h"
#include "Force_Writeback.h"

enum TestType{
    SIMPLE_TEST,	
    PRE_SET_MISS,
    FORCED_WRITE_RAND
};

class tester{
	public:
		void read_cb(uint, uint64_t, uint64_t);
		void write_cb(uint, uint64_t, uint64_t);
		void run_test(TestType);

};
