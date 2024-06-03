#include <iostream>
#include <string>
#include <vector>
#include "Server.h"

Server::Server(string name)
{
    Server_name = name;
    num_users = 0;
    user_info.clear();
}

Server::~Server()
{
}

void Server ::register_user_server(string username, int pkey)
{
    UserInfo us3r(username, pkey);
    user_info.push_back(us3r);
}

bool Server ::is_user_present(string username)
{
    for (auto i : user_info)
    {
        if (i.get_user_name() == username)
            return true;
    }
    return false;
}

bool Server ::is_uname_valid(string username)
{
    for (auto i : user_info)
    {
        if (i.get_user_name() == username)
            return false;
    }
    return true;
}

int Server ::getpub_key(string uname)
{
    for (auto i : user_info)
    {
        if (i.get_user_name() == uname)
            return i.get_public_key();
    }
    return -1;
}

void Server ::print_data()
{
    for (auto i : user_info)
    {
        cout << i.get_user_name() << i.get_public_key() << endl;
    }
}