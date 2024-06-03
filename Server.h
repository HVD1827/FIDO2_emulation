#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <string>
#include <vector>
#include "UserInfo.h"
class Server
{
private:
    string Server_name;
    int num_users;
    vector<UserInfo> user_info;

public:
    Server(string name);
    ~Server();
    void register_user_server(string username, int public_key);
    bool is_user_present(string username);
    bool is_uname_valid(string username);
    int getpub_key(string uname);
    void print_data();
};
#endif // SERVER_H
