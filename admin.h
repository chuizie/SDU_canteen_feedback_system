#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <vector>

class admin{
    public:
        admin(const std::string& ac, const std::string& pa);
        ~admin();
        bool login();
        bool signupAdmin();
        bool deleteAdmin();
        bool passwordChange(const std::string& npa);
        std::string getaccount(){return account;}
        static std::vector<std::string> showComments();

    private:
        std::string account;
        std::string password;
        
};

#endif
