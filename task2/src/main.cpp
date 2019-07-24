
#include <iostream>
#include <mutex>
#include <thread>
#include "Poco/Data/Session.h"
#include "Poco/Data/SQLite/Connector.h"
#include <vector>
#include <iostream>

using namespace Poco::Data;
using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;
using namespace std;

std::mutex mtx;
static int counter = 0;
static const int MAX_COUNTER_VAL = 10;
const std::string DATABASE = "DATA.db";


void init()
{
    SQLite::Connector::registerConnector();
}


void shutdown()
{
    SQLite::Connector::unregisterConnector();
}


void thread_proc(int tnum, Session &ses) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
        std::cout << "Thread " << tnum << std::endl;

        int min = (tnum - 1) * 10 + 1;
        int max = tnum * 10;
        std::vector<int> arr;

        for(int i = min; i <= max; ++i)
            arr.push_back(i);

        Statement insert(ses);
        insert << "INSERT INTO Arrays VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)",
            use(arr[0]),
            use(arr[1]),
            use(arr[2]),
            use(arr[3]),
            use(arr[4]),
            use(arr[5]),
            use(arr[6]),
            use(arr[7]),
            use(arr[8]),
            use(arr[9]);

        insert.execute();
}


int main() {
    init();
    // create a session
    Session session("SQLite", DATABASE);

    // drop sample table, if it exists
    session << "DROP TABLE IF EXISTS Arrays", now;

    session << "CREATE TABLE Arrays (One INTEGER, Two INTEGER, Three INTEGER, Four INTEGER, Five INTEGER, Six INTEGER, Seven INTEGER, Eight INTEGER, Nine INTEGER, Ten INTEGEnn)", now;

    for(int i = 2; i <= 10; i += 2) {
        std::thread thr1(thread_proc, i, ref(session));
        thr1.join();
        std::thread thr2(thread_proc, i - 1, ref(session));
        thr2.join();
    }

    shutdown();

    return 0;
}