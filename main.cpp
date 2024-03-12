#include <iostream>
#include <vector>
#include <set>
#include <fstream>
#include <sstream>
using namespace std;

class Inmate
{
public:
    string inmate_name;
    string earpod_ID;
    vector<int> sleep_times;
    int fall_asleeptime;
    bool earpodactive;

    void parse_data(const string &line);
    void read_data(const string &filename);
};
void Inmate::parse_data(const string &line)
{
    istringstream iss(line);
    vector<string> tokens;
    string token;
    while (getline(iss, token, ','))
    {
        tokens.push_back(token);
    }
    if (tokens.size() < 10)
    {
        cout << "Invalid data format in file" << endl;
        return;
    }

    inmate_name = tokens[0];
    earpod_ID = tokens[1];
    // Convert the fall asleep time to integer
    fall_asleeptime = stoi(tokens[9]);
    // Parse sleep times
    for (int j = 2; j < 9; j++)
    {
        sleep_times.push_back(stoi(tokens[j]));
    }
    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << "  ";
    }
    cout << endl;
}

void Inmate::read_data(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Skip header line
    while (getline(file, line))
    {
        parse_data(line);
    }

    file.close();
}

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
    vector<Inmate> x[3];
    for (int i = 0; i < 3; ++i)
    {
        Inmate inmate;          // Create an Inmate object
        x[i].push_back(inmate); // Add the Inmate object to the vector
        for (Inmate &inmate : x[i])
        {
            inmate.read_data("data.csv");
            cout << "Read inmate: " << inmate.inmate_name << endl; // Debug statement
        }
    }

    Dorm dorm1("dorm1");
    Dorm dorm2("dorm2");

    for (int i = 0; i < 3; ++i)
    {
        
        for (const Inmate &inmate : x[i])
        {
            
            if (inmate.fall_asleeptime <= 50)
            {
                
                dorm1.add_inmate(inmate);
            }
            else
            {
                
                dorm2.add_inmate(inmate);
            }
        }
    }

    dorm1.print_members();
    dorm2.print_members();

 return 0;
}