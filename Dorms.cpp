class Dorm
{
public:
  string dorm_name;
  vector<Inmate> assigned_inmates;
  set<int> avail_channel;
  set<int> play_channel;
  int max_sleep_times;

  Dorm(const string &name, int p) : dorm_name(name), max_sleep_times(p) {}
};
