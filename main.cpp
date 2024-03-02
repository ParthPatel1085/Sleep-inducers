#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class Sleepinducers
{
    // properties
private:
    int totalinmates;
    int totaldorms;
    double maxsleeptime;

    vector<int> inmates;       // inmates sleeptime in minutes
    vector<vector<int>> dorms; // inmates assigned in dorms(rooms)

public:
    Sleepinducers(int ti, int td, double mst) : totalinmates(ti), totaldorms(td), maxsleeptime(mst) {}

    void initializeinmates()
    {
        srand(time(0));
        for (int i = 0; i < totalinmates; i++)
        {
            inmates.push_back(rand() % (60));
        }
    }
};
int main()
{
    int M;
    int N;
    int P;

    return 0;
}
