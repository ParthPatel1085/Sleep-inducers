#include "Inmates.cpp"
class Dorm
{
public:
  string dorm_name;
  vector<Inmate> assigned_inmates;
  int max_sleep_times;

  Dorm(const string &name, int p) : dorm_name(name), max_sleep_times(p) {}
  void print_members();
  bool add_inmate(const Inmate &inmate);
};
