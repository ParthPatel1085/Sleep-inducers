#include<iostream>
#include<vector>
#include<set>
#include<fstream>
using namespace std;
class Inmate
{
private:
    string inmate_name;
    string earpod_ID;
    vector<int> sleep_times;  
    int fall_asleeptime; 
    bool earpodactive;

public: 
    Inmate(string name, string earpodID, vector<int> sleeptimes, int fallasleeptime)
    {
        inmate_name = name;
        earpod_ID = earpodID;
        sleep_times = sleeptimes;
        fall_asleeptime = fallasleeptime;
        earpodactive = true; 
    }
};
class Dorm
{
private:
    string dorm_name;
    vector<Inmate> assigned_inmate; 
    set<int> avail_channel;     
    set<int> play_channel;      

public: 
    Dorm(string name) : dorm_name(name), assigned_inmate(), avail_channel(), play_channel() {}
};

int main()
{
    string name, e_ID;
    int t1,t2,t3,t4,t5,t6,t7, as_time;
    ifstream file;//file I/O included

    file.open("data.csv");
    while (file >> name >> e_ID >> t1 >> t1 >> t3 >> t4 >> t5 >> t6 >> t7 >> as_time){
    cout << name << "  "<<e_ID<<"  "<<t1 << "   "<<t2 << "   "<<t3 << "   "<<t4 << "   "<<t5 << "   "<<t6 << "   "<<t7<<"  "<<as_time<<endl;
    }
    file.close();
    return 0;
}
