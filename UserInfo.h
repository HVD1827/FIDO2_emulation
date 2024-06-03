#ifndef USERINFO_H
#define USERINFO_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class UserInfo
{
private:
    string user_name;
    int public_key;

public:
    UserInfo();
    UserInfo(string uname, int pkey);
    string get_user_name();
    int get_public_key();
};
#endif // USERINFO_H
