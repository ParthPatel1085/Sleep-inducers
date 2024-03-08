#include<iostream>
#include<vector>
#include<set>
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
    return 0;
}
