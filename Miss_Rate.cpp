#include "Miss_Rate.h"

Miss_Rate::Miss_Rate()
{
}

uint Miss_Rate::Pre_Set_Miss(HybridSystem::HybridSystem *mem)
{
    
    uint64_t num_init =  100000;
    
    srand(time(NULL));

    mem->addTransaction(false, 140708070030063);
    for(uint64_t i=0; i<10000; i++){
	
	mem->update();
	
    }

    cout<<"Preparing transactions to preload cache with data...\n";

    for (uint64_t i=0; i<num_init;i++)
    {
        DRAMSim::Transaction t = DRAMSim::Transaction(DATA_READ, i*PAGE_SIZE, NULL);
        mem->addTransaction(t);
        if (i%10000 == 0)
	{
            cout << i << "/" << num_init << endl;
	}
    }
    cout << "Running transactions to preload cache with data...\n";
    int factor = 1000;
    for (uint64_t i=0; i<num_init*factor; i++)
        {
            mem->update();
            if (i%1000000 == 0)
            {
                cout << i << "/" << num_init*factor << endl;
            }
        }

	uint64_t cur_addr = 0;

        const uint64_t NUM_ACCESSES = 1000;
        const int MISS_RATE = 10;

        cout << "Starting miss rate test...\n";
        for (uint64_t i=0; i<NUM_ACCESSES; i++)
        {
                TransactionType type = DATA_READ;

                // Decide whether to do a hit or a miss with probability miss rate.
                bool want_hit = true;
                if (rand() % 100 < MISS_RATE)
                        want_hit = false;

                //if (mem->get_valid_pages().size() == 0)
                //      want_hit = false;

                if (want_hit)
                        cur_addr = mem->get_hit();
                else
                        cur_addr = (rand() % TOTAL_PAGES) * PAGE_SIZE;

                cout << mem->currentClockCycle << ": want_hit=" << want_hit << " cur_addr=" << cur_addr << endl;

                // Pick the address that will give a hit or a miss.
                int k=0;
                while(mem->is_hit(cur_addr) != want_hit)
                {
                        cur_addr = (rand() % TOTAL_PAGES) * PAGE_SIZE;
                        k++;
                        cout << "k=" << k << " want_hit=" << want_hit << " cur_addr=" << cur_addr << " is_hit=" << mem->is_hit(cur_addr) << "\n";
                        
                }
                //cur_addr = (cur_addr + PAGE_SIZE) % (TOTAL_PAGES * PAGE_SIZE);
                

                DRAMSim::Transaction t = DRAMSim::Transaction(type, cur_addr, NULL);
                mem->addTransaction(t);

#if DEBUG_CACHE
                cout << "\n\tAdded transaction " << i << " of type=" << type << " addr=" << cur_addr << " set=" << SET_INDEX(cur_addr) 
                        << " tag=" << TAG(cur_addr) << endl;
#endif

                for (int j=0; j<factor; j++)
                {
                        mem->update();
                }
        }


        for (int i=0; i<1000000; i++)
        {
                mem->update();
        }


        /*cout << "\n\n" << mem->currentClockCycle << ": completed " << complete << "\n\n";
*/        cout << "dram_pending=" << mem->dram_pending.size() << " flash_pending=" << mem->flash_pending.size() << "\n\n";
        cout << "dram_queue=" << mem->dram_queue.size() << " flash_queue=" << mem->flash_queue.size() << "\n\n";
        cout << "pending_pages=" << mem->pending_pages.size() << "\n\n";

        return mem->currentClockCycle;

}
