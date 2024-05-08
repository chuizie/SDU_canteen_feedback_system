#ifndef USERS_H
#define USERS_H
#include<string>


class users{
    public:
        users(const std::string& na, const std::string& ac, const std::string& pa);
        ~users();
        bool addUsers();
        static bool changePassword(const std::string& ac, const std::string& opa, const std::string& npa);
        static bool login(const std::string& ac, const std::string& pa);
        static bool deleteUsers(const std::string& ac);
        static bool submintComments(const std::string& dN, const std::string& co);
    private:
        std::string name;
        std::string account;
        std::string password;
};

#endif
