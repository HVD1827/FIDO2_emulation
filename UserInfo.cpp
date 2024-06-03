#include <iostream>
#include <string>
#include <vector>
#include<map>
#include "UserInfo.h"

UserInfo ::UserInfo()
{
    user_name = "";
    public_key = -1;
}

UserInfo ::UserInfo(string uname, int pkey)
{
    user_name = uname;
    public_key = pkey;
}

int UserInfo :: get_public_key()
{
    return public_key;
}

string UserInfo :: get_user_name()
{
    return user_name;
}