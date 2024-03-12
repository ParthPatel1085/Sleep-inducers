#include<iostream>
#include<vector>
#include<set>
#include<fstream>
#include<sstream>
using namespace std;
class Inmate
{
public:
    string inmate_name;
    string earpod_ID;
    vector<int> sleep_times;  
    int fall_asleeptime; 
    bool earpodactive;

int linelength()
    {
        ifstream file("data.csv");
        int a=0;
        string line;
        while(getline(file, line))
        {
            a++;
        }
        file.close();
        cout << a << endl;
        return a;
    }
    void take_input_file(int line_number)
    {
        ifstream file("data.csv");
        int k=linelength();
        for(int i=0;i<k;i++)
        {
        if (!file.is_open())
        {
            cout << "Error while opening file" << endl;
        }
        else
        {
            string line;
            for (int i = 1; i <= line_number; i++)
            {
                if (!getline(file, line))
                {
                    cout << "Error: Not enough lines in file" << endl;
                    file.close();
                    return;
                }
            }
            istringstream iss(line);
            vector<string> tokens;
            string token;
            while (getline(iss, token, ','))
            {
                tokens.push_back(token);
            }
            if (tokens.size() >= 10)
            {
                inmate_name = tokens[0];
                earpod_ID = tokens[1];

                    fall_asleeptime = stoi(tokens[9]);
                    for (int j = 2; j < 9; j++)
                    {
                        {
                            sleep_times.push_back(stoi(tokens[j]));
                        }
                    }

                    for (const auto &value : tokens)
                    {
                        cout << value << "   ";
                    }
                    cout << endl;
                
            }
        }
            file.close(); // Closing the file after reading
        }
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
    Inmate a1;
    int k = a1.linelength();
    Inmate arr[k];
    for(int i=0;i<k;i++)
    {
      arr[i].take_input_file(i+1);
    }
   return 0;
}