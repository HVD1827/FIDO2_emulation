#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
// #include "Device.h"
class Device;
class User
{
private:
    int num_devices;
    int private_key;
    vector<int> dev;
    string username;

public:
    User(string name, int pkey, vector<int> devices);
    ~User();
    string getUsername();
    vector<int> getdevices();
    int getprivate_key();
    void add_device(int d);
    void set_pvt_key(int key)
    {
        private_key = key;
    }
};