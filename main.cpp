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

    vector<int> inmates;       // inmates sleeptime in minutes
    vector<vector<int>> dorms; // inmates assigned in dorms(rooms)

public:
    Sleepinducers(int ti, int tdb) : totalinmates(ti), totaldorms(td) {}

    void initializeinmates()
    {
        srand(time(0));
        for (int i = 0; i < totalinmates; i++)
        {
            inmates.push_back(rand() % (60));
        }
    }

    void Dorms()
    {
        vector<int> time(totaldorms,0);
        int k = 60 / totaldorms;
        int s = 0;
        for (int i = 0; i < totaldorms; i++)
        {
            time[i] = k;
            k += time[0];
            time[totaldorms-1]=60;
            for(int j=0;j<totalinmates;j++)
            {  
               if(inmates[j]<=time[i] && inmates[j]>s)
               {
                    dorms[i][j] == inmates[j];
               }
            }
            s = time[i];
        }
    }
    void display()
    {

        for (int i = 0; i < totaldorms; i++)
        {
            for (auto &r : dorms[i])
            {
                cout << r << "   ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    int M;
    int N;
    int P;
    Sleepinducers A(20,7);
    A.initializeinmates();
    A.Dorms();
    A.display();

    return 0;
}
