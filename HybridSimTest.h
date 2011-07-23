#ifndef SOMETHING_H
#define SOMETHING_H

#include <iostream>
#include <time.h>

#include <HybridSystem.h>

enum TestType{
    SIMPLE_TEST	


};

class tester{
	public:
		void read_cb(uint, uint64_t, uint64_t);
		void write_cb(uint, uint64_t, uint64_t);
		void run_test(TestType);

};

#endif
