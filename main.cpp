#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
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
}
class Dorm
{
public:
  string dorm_name;
  vector<Inmate> assigned_inmates;
  set<int> avail_channel;
  set<int> play_channel;
  int max_sleep_times;

  Dorm(const string &name, int p) : dorm_name(name), max_sleep_times(p) {}

  bool add_inmate(const Inmate &inmate)
  {
    assigned_inmates.push_back(inmate);
    return true;
  }

  void print_members()
  {
    cout << "-------------------------------------------------------------------" << endl;
    cout << "This are the list of inmates who are assigned to " << dorm_name << endl;
    for (const Inmate &inmate : assigned_inmates)
    {
      cout << "Inmate Name: " << inmate.inmate_name << endl;
      cout << "Earpod ID: " << inmate.earpod_ID << endl;
      cout << "Fall Asleep Time: " << inmate.fall_asleeptime << endl;
      cout << "Sleep Time list from monday to sunday :   ";
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
  vector<Inmate> inmates;
  ifstream file("data1.csv");
  if (!file.is_open())
  {
    cerr << "Error opening file: data1.csv" << endl;
    return 1;
  }

  string line;
  getline(file, line); // skip header line
  while (getline(file, line))
  {
    Inmate inmate;
    inmate.parse_data(line);
    inmates.push_back(inmate);
  }
  file.close();

  int p1 = 20; // maxium music playing time for dorm1
  int p2 = 40; // maxium music playing time for dorm2
  Dorm dorm1("Dorm1", p1);
  Dorm dorm2("Dorm2", p2);

  int fall_asleep_threshold = 20;
  cout << "Adding inmates to the dorm according to theis FallAsleepTimes .... " << endl;
  for (const Inmate &inmate : inmates)
  {
    if (inmate.fall_asleeptime <= fall_asleep_threshold)
    {
      dorm1.add_inmate(inmate);
    }
    else
    {
      dorm2.add_inmate(inmate);
    }
  }
  cout << "-------------------------------------------------------------------" << endl;
  cout << "All inmates are added successfully ..." << endl;
  dorm1.print_members();
  dorm2.print_members();
  return 0;
}
