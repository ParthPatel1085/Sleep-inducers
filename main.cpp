#include <iostream>
#include <vector>
using namespace std;
class Sleepinducers
{
    // properties
    private:

    int totalinmates;
    int totaldorms;
    double maxsleeptime;

    vector<int> inmates; // inmates sleeptime in minutes
    vector<vector<int>> dorms; //inmates assigned in dorms 
    
    public:

    Sleepinducers(int ti,int td,double mst) 
    : totalinmates(ti),totaldorms(td),maxsleeptime(mst){}
    
};

int main()
{   
   int M;
   int N;
   int P;


    return 0;
}