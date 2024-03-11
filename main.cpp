#include<iostream>
#include<vector>
#include<set>
#include<fstream>
using namespace std;
class Inmate
{
public:
    string inmate_name;
    string earpod_ID;
    vector<int> sleep_times;  
    int fall_asleeptime; 
    bool earpodactive;


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
