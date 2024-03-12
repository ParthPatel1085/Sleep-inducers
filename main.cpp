#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Inmate
{
public:
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
public:
    string dorm_name;
    vector<Inmate> assigned_inmates;
    set<int> avail_channel;
    set<int> play_channel;

    Dorm(const string &name) : dorm_name(name) {}

    bool add_inmate(const Inmate &inmate)
    {
        cout << "Adding inmate: " << inmate.inmate_name << " to " << dorm_name << endl;
        assigned_inmates.push_back(inmate);
        cout << "Inmate name: " << assigned_inmates.back().inmate_name << " added to " << dorm_name << endl;
        cout << "Assigned Inmates count: " << assigned_inmates.size() << endl;
        return true;
    }

    void print_members()
    {
        cout << "Dorm Name: " << dorm_name << endl;
        cout << "Assigned Inmates:" << endl;
        for (const Inmate &inmate : assigned_inmates)
        {
            cout << "Inmate Name: " << inmate.inmate_name << endl;
            cout << "Earpod ID: " << inmate.earpod_ID << endl;
            cout << "Fall Asleep Time: " << inmate.fall_asleeptime << endl;
            cout << "Sleep Times: ";
            for (int st : inmate.sleep_times)
            {
                cout << st << " ";
            }
            cout << endl
                 << endl;
        }
    }
};

int main()
{
    return 0;
}