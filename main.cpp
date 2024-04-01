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

  void parse_data(const string &line)
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
    cout << "Inmate data parsed for: " << inmate_name << endl; // Debug: Parsed data
  }

  void read_data(const string &filename)
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
    cout << "Finished reading inmate data from: " << filename << endl; // Debug: Finished reading
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
    cout << "Adding inmate: " << inmate.inmate_name << " to " << dorm_name << endl; // Debug: Adding inmate
    assigned_inmates.push_back(inmate);
    cout << "Inmate added successfully." << endl; // Debug: Added successfully
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
  // 1. Read Inmate Data (Optimized):
  vector<Inmate> inmates;
  string filename = "data.csv"; // Replace with your actual filename

  if (!ifstream(filename)) // Check for file existence before opening
  {
    cout << "Error: File '" << filename << "' does not exist." << endl;
    return 1; // Indicate error
  }

  ifstream file(filename);

  string line;
  getline(file, line); // Skip header line
  while (getline(file, line))
  {
    Inmate inmate;
    inmate.read_data(line); // Call read_data directly on each Inmate object
    inmates.push_back(inmate);
  }

  file.close();
  cout << "Successfully read data for " << inmates.size() << " inmates." << endl; // Debug: Read count

  // 2. Dorm Creation:
Dorm dorm1("dorm1");
Dorm dorm2("dorm2");

// 3. Inmate Assignment (Improved):
for (const Inmate &inmate : inmates)
{
  if (inmate.fall_asleeptime <= 50)
  {
    dorm1.add_inmate(inmate);
    cout << inmate.inmate_name << " assigned to dorm1 (fall asleep time: " << inmate.fall_asleeptime << ")." << endl; // Debug: Assigned dorm
  }
  else
  {
    dorm2.add_inmate(inmate);
    cout << inmate.inmate_name << " assigned to dorm2 (fall asleep time: " << inmate.fall_asleeptime << ")." << endl; // Debug: Assigned dorm
  }
}

// 4. Printing Dorm Members:
cout << "\nDorm 1 Members:" << endl;
dorm1.print_members();
cout << "\nDorm 2 Members:" << endl;
dorm2.print_members();

return 0;
}
  
