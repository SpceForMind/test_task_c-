
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
std::mutex mtx;
static int counter = 0;
static const int MAX_COUNTER_VAL = 10;
const std::string FILENAME = "DATA.txt";


void thread_proc(int tnum, ofstream & f) {
            std::lock_guard<std::mutex> lock(mtx);
            ++counter;
            std::cout << "Thread " << tnum << std::endl;

            int min = (tnum - 1) * 10 + 1;
            int max = tnum * 10;

            for(int i = min; i <= max; ++i)
                f << i << " ";
}


int main() {
    std::ofstream f;
    f.open(FILENAME, std::ios::app);

    for(int i = 2; i <= 10; i += 2) {
        std::thread thr1(thread_proc, i, ref(f));
        thr1.join();
        std::thread thr2(thread_proc, i - 1, ref(f));
        thr2.join();
    }

    f.close();

    return 0;
}

