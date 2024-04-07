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
