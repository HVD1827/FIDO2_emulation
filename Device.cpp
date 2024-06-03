#include "Device.h"
#include <iostream>
#include <string>
#include <vector>

int revrse(int n)
{
    vector<int> v;
    while (n != 0)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    for (int i = 0; i < v.size(); i++)
    {
        n *= 10;
        n += v[i];
    }
    return n;
}

Device::Device(int id, string pass)
{
    device_id = id;
    users.clear();
    num_users = 0;
    password = pass;
}

Device::~Device()
{
}

void Device ::Register_User(User *user, Server &ser)
{
    if (!ser.is_user_present(user->getUsername()))
    {
        int private_key = rand() % 100000;
        int public_key = revrse(private_key);
        user->set_pvt_key(private_key);
        // passkey pair is ready by now
        // now go to the server and register
        ser.register_user_server(user->getUsername(), public_key);
        user->add_device(device_id);
        users.push_back(user->getUsername());
        cout << "User registered successfully!!\n";
    }
    else
    {
        cout << "Username already exists!! Please choose a different username!" << endl;
        return;
    }
}

void Device ::sign_in_user(User *user, string pass, Server &ser)
{
    if (ser.is_user_present(user->getUsername()))
    {
        if (pass != password)
        {
            cout << "Wrong Password!! Try again" << endl;
        }
        else
        {
            int pvtkey_from_server = revrse(ser.getpub_key(user->getUsername()));
            int pvtkey = user->getprivate_key();
            if (pvtkey_from_server == pvtkey)
            {
                cout << "You have logged in successfully" << endl;
            }
            else
            {
                cout << "Invalid Username" << endl;
            }
        }
    }
    else
    {
        cout << "User is not registered!! Please register!" << endl;
        return;
    }
}

void Device ::print_users()
{
    for (auto i : users)
    {
        cout << i << " ";
    }
    cout << endl;
}