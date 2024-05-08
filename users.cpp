#include"users.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

//账号合法性判断
bool usersAccountLegality(const string& ac){
    bool accountLegality = 1;
    for (char ch : ac){
        if (!isdigit(ch)){
            accountLegality = 0;
            cerr << "illegal account" << endl;
            return 0;
        }
    }

    if (ac.length() != 12){
        accountLegality = 0;
        cerr << "illegal account" << endl;
        return 0;
    }

    return 1;
}


users::users(const string& na, const string& ac, const string& pa)
    : name(na), account(ac), password(pa){}

users::~users(){}

bool users::login(const string& ac, const string& pa){
    if (usersAccountLegality(ac)){
        ifstream inputFile("users.txt");
        if (!inputFile){
            cerr << "could not open users.txt" << endl;
            return 0;
        }
        else{
            string line;
            bool loginJug = 0;
            while (getline(inputFile, line)){
                istringstream iss(line);
                string firstword, secondword, thirdword;
                iss >> firstword >> secondword >> thirdword;
                if (secondword == ac){
                    loginJug = 1;
                    if (thirdword == pa){
                        cout << "login successful！user：" << firstword << endl;
                        return 1;
                    }
                    else{
                        cout << "password error！" << endl;
                        return 0;
                    }
                }
            }
            if (!loginJug){
                cout << "account does not exist" << endl;
                return 0;
            }
        }
        inputFile.close();
    }
    return 0;
}

bool users::changePassword(const string& ac, const string& opa, const string& npa){
    string tarline;
    if (usersAccountLegality(ac)){
        ifstream inputFile("users.txt");
        if (!inputFile){
            cerr << "could not open users.txt" << endl;
            return 0;
        }
        else{
            ofstream tempFile("temp.txt");
            if (!tempFile){
                cerr << "could not build temp.txt" << endl;
                return 0;
            }
            else{
                string line, lpa;
                bool loginJug = 0;
                while(getline (inputFile, line)){
                    istringstream iss(line);
                    string firstword, secondword, thirdword;
                    iss >> firstword >> secondword >> thirdword;
                    if (secondword == ac){
                        loginJug = 1;
                        if(thirdword != opa){
                            cout << "old password error" <<endl;
                            tempFile << line << endl;
                        }
                        else{
                            tarline = firstword + " " + secondword + " " + npa;
                            tempFile << tarline << endl;
                        }
                    }
                    else{
                        tempFile << line << endl;
                    }
                }
                if (!loginJug){
                    cout << "account does not exist" << endl;
                    return 0;
                }

                inputFile.close();
                tempFile.close();

                if (remove("users.txt") != 0){
                    cerr << "could not delete users.txt" << endl;
                    return 0;
                }
                else{
                    if (rename("temp.txt", "users.txt") != 0){
                        cerr << "could not rename temp.txt" << endl;
                        return 0;
                    }
                    else{
                        cout << "password change successful"  << endl;
                        return 1;
                        }
                    }
                }
            }

    }
    return 0;
}

bool users::addUsers(){
    if (usersAccountLegality(account)){
        ofstream outputFile("users.txt", std::fstream::app);
        if (!outputFile){
            cerr << "could not open users.txt" << endl;
            return 0;
        }
        else{
            string addLine = name + " " + account + " " + password;
            outputFile << addLine << endl;
            outputFile.close();
            cout << "add user successful" << endl;
            return 1;
        }
    }
    return 0;
}

bool users::deleteUsers(const string& ac){
    if (usersAccountLegality(ac)){
        ifstream inputFile("users.txt");
        if (!inputFile){
            cerr << "could not open users.txt" << endl;
            return 0;
        }
        else{
            ofstream tempFile("temp.txt");
            if (!tempFile){
                cerr << "could not build tempFile" << endl;
                return 0;
            }
            else{
                string line;
                while(getline(inputFile, line)){
                    istringstream iss(line);
                    string firstword, secondword, thirdword;
                    iss >> firstword >> secondword >> thirdword;
                    if (secondword != ac){
                        tempFile << line << endl;
                    }
                }
                inputFile.close();
                tempFile.close();

                if(remove("users.txt") != 0){
                    cerr << "could not delete users.txt" << endl;
                    return 0;
                }
                else{
                    if (rename("temp.txt", "users.txt") != 0){
                        cerr << "could not rename temp.txt" << endl;
                        return 0;
                    }
                    else{
                        cout << "delete successful" << endl;
                        return 1;
                    }
                }
            }
        }


    }
    return 0;
}

bool users::submintComments(const string& dN, const string& co){
    string tarline = dN + " 反馈：" + co;
    ofstream outputFile("comments.txt", std::fstream::app);
    if (!outputFile){
        cerr << "could not open commments.txt" << endl;
        return 0;
    }
    else{
        outputFile << tarline << endl;
        outputFile.close();
        cout << "add successful" << endl;
        return 1;
    }
    return 0;
}
