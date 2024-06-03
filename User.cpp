#include "User.h"

User ::User(string name, int pkey, vector<int> devices)
{
    dev = devices;
    username = name;
    num_devices = 0;
    private_key = pkey;
    dev.clear();
}

User ::~User() {}

string User ::getUsername()
{
    return username;
}

int User ::getprivate_key()
{
    return private_key;
}

vector<int> User ::getdevices()
{
    return dev;
}

void User ::add_device(int d)
{
    dev.push_back(d);
}
