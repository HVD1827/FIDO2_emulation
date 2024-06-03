#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "User.h"
#include "Server.h"
class Device
{
private:
    int device_id;
    vector<string> users;
    int num_users;
    string password;

public:
    Device(int id, string pass);
    ~Device();
    void Register_User(User *user, Server &ser);
    void sign_in_user(User *user, string pass, Server &ser);
    void print_users();
};

#endif // DEVICE_H