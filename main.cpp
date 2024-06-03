#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#include "Device.h"
#include "Server.h"

int main()
{
    cout << "Enter Number of Devices:\n";
    int N; // number of devices
    cin >> N;
    map<int, Device *> mp_device;
    for (int i = 0; i < N; i++)
    {
        cout << "Enter device id:\n";
        int divid;
        cin >> divid;
        cout << "Enter device password:\n";
        string pass;
        cin >> pass;
        mp_device[divid] = new Device(divid, pass);
    }
    // return 0;
    string srvr;
    cout << "Enter Server Name: ";
    cin >> srvr;
    Server servr(srvr);
    string s;
    cout << "Enter operation type:\n";
    cin >> s;
    map<string, User *> mp_user;
    while (s[0] != 'X')
    {
        if (s[0] == 'R')
        {
            cout << "Enter device id:\n"; // assuming it is always valid
            int device_id;
            cin >> device_id;
            cout << "Enter username:\n";
            string username;
            cin >> username;
            if (mp_user[username] == nullptr)
            {
                vector<int> v;
                User *ur = new User(username, -1, v);
                mp_device[device_id]->Register_User(ur, servr);
                mp_user[username] = ur;
            }
            else
            {
                mp_device[device_id]->Register_User(mp_user[username], servr);
            }
        }
        else if (s[0] == 'S')
        {
            cout << "Enter device id:\n"; // assuming it is always valid
            int device_id;
            cin >> device_id;
            string username, passwd;
            cout << "Enter username:\n";
            cin >> username;
            cout << "Enter password:\n";
            cin >> passwd;
            if (mp_user[username] == nullptr)
            {
                vector<int> v;
                User *ur = new User(username, -1, v);
                mp_device[device_id]->sign_in_user(ur, passwd, servr);
                mp_user[username] = ur;
            }
            else
            {
                mp_device[device_id]->sign_in_user(mp_user[username], passwd, servr);
            }
        }
        else if (s[0] == 'P')
        {
            servr.print_data();
        }
        else
        {
            cout << "Invalid Operation" << endl;
        }
        cout << "Enter operation type:\n";
        cin >> s;
    }
    // for (auto i : mp_device)
    // {
    //     cout << i.first << endl;
    //     i.second->print_users();
    // }
    // above is for printing users on a particular device.
}