#include <iostream>
#include <string>
#include <vector>
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