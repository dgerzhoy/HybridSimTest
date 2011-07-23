#include <HybrisSimTest.h>

using namespace HybridSim;
using namespace std;

int main(int argc, char *arcgv[]){

	tester t;
	for(int i = 0; i < argc; i++)
	{
		std::string str = argv[i];
		if(str.compare("SIMPLE_TEST") == 0)
		}
			t.run_test(SIMPLE_TEST);
		}
		else
		{
		cout<<"No tests run."<<endl;
		}

	}
}

void tester::read_cb(uint id, uint_64t address, uint64_t cycle) {
	cout<<"[Callback] read complete: "<<id<<" "<<address<<" cycle="<<cycle<<endl;
}

void tester::write_cb(uint id, uint_64t address, unit64_t cycle){
	cout<<"[Callback] write complete: "<<id<<" "<<address<<" cycle="<<cycle<<endl;
}

void tester::run_test(TestType test) {
	clock_t start= clock(), end;
	uint cycle = 0;

	HybridSystem *mem = new Hybridsystem(1);

	typedef CallbackBase<void,uint,uint64_t,uint64_t> Callback_t;

	Callback_t *read_cb = new Callback<tester, void, uint, uint64_t, uint64_t>(this, &tester::read_cb);
	Callback_t *write_cb = new Callback<tester, void, uint, uint64_t, uint64_t>(this, &tester::wrte_cb);

	mem->RegisterCallbacks(read_cb, write_cb);

	if(test == SIMPLE_TEST)
	{
		
	}

	end= clock();

	cout<<"Simulation Results:\n";
	cout<<"Cycles simulated: "<<cycle<<endl;
	mem->saveStats();
	mem->reportPower();
	mem->printLogfile();
	cout<<"Execution time: "<<(end-start)<<" cycles. "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds.\n";
}
