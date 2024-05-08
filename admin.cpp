#include"admin.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

//账号合法性判断
bool adminAccountLegality(const string& ac){
    for (char ch : ac){
        if (!isdigit(ch)){
            cerr << "illegal user account" << endl;
            return 0;
        }
    }

    if (ac.length() != 8){
        cerr << "illegal uesr account" << endl;
        return 0;
    }

    return 1;
}

//密码合法性判断
bool adminPasswordLegality(const string& ac){
    for (char ch : ac){
        if (!isdigit(ch)){
            cerr << "illegal user password" << endl;
            return 0;
        }
    }

    if (ac.length() != 9){
        cerr << "illegal uesr password" << endl;
        return 0;
    }

    return 1;
}

admin::admin(const string& ac, const string& pa)
    :account(ac), password(pa){}

admin::~admin(){}

bool admin::login(){
    if (adminAccountLegality){
        ifstream inputFile("admin.txt");
        if(!inputFile){
            cerr << "Could not open admin.txt" << endl;
            return 0;
        }
        else{
            string line;
            bool loginJug = 0;
            while(getline(inputFile, line)){
                istringstream iss(line);
                string firstword, secondword;
                iss >> firstword >> secondword;

                if(firstword == account){
                    loginJug = 1;
                    if (secondword == password){
                        cout << "login successful! Administrator:" << firstword <<endl;
                        return 1;
                    }
                    else{
                        cout << "password error" << endl;
                        return 0;
                    }
                }
            }
            if (!loginJug){
                cout << "account does not exist" << endl;
                return 0;
            }
            inputFile.close();
        }
    }
    return 0;
}

bool admin::deleteAdmin(){
    if (adminAccountLegality(account)){
        ifstream inputFile("admin.txt");
        if (!inputFile){
            cerr << "could not open admin.txt" << endl;
            return 0;
        }
        else{
            ofstream tempFile("temp.txt");
            if (!tempFile){
                cerr << "coold not build temp.txt" << endl;
                return 0;
            }
            else{
                string line;
                while(getline(inputFile, line)){
                    istringstream iss(line);
                    string firstword, secondword;
                    iss >> firstword >> secondword;
                    if (firstword != account){
                        tempFile << line << endl;
                    }
                }
                inputFile.close();
                tempFile.close();

                if (remove("admin.txt") != 0){
                    cerr << "could not delete admin.txt" << endl;
                    return 0;
                }
                else{
                    if (rename("temp.txt", "admin.txt") != 0){
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

bool admin::signupAdmin(){
    if (adminAccountLegality(account)){
        if (adminPasswordLegality(password)){
            string tarline = account + " " + password;
            ofstream outputFile("admin.txt", std::ofstream::app);
            if(!outputFile){
                cerr<< "could not open admin.txt" << endl;
                return 0;
            }
            else{
                outputFile << tarline << endl;
                outputFile.close();
                cout << "admin sign up successful!" << endl;
                return 1;
            }
        }
    }
    return 0;
}


bool admin::passwordChange(const string& npa){
    if (adminAccountLegality(account)){
        string tarline = account+ " " + npa;
        ifstream inputFile("admin.txt");
        if (!inputFile){
            cerr << "could not open admin.txt" << endl;
            return 0;
        }
        else{
            ofstream tempFile("temp.txt");
            if (!tempFile){
                cerr << "could not open temp.txt" << endl;
                return 0;
            }
            else{
                string line;
                bool loginJug = 0;
                while(getline(inputFile, line)){
                    istringstream iss(line);
                    string firstword, secondword;
                    iss >> firstword >> secondword;
                    if (firstword != account){
                        tempFile << line << endl;
                    }
                    else{
                        loginJug = 1;
                        if (secondword != password){
                            cerr << "password error" << endl;
                            return 0;
                        }
                        else{
                            tempFile << tarline << endl;
                        }
                    }
                }

                if (!loginJug){
                    cerr << "account does not exist" << endl;
                    return 0;
                }

                inputFile.close();
                tempFile.close();

                if (remove("admin.txt") != 0){
                    cerr << "could not delete admin.txt" << endl;
                    return 0;

                }
                else{
                    if (rename("temp.txt", "admin.txt") != 0){
                        cerr << "could not rename temp.txt" << endl;
                        return 0;
                    }
                    else{
                        cout << "change successful" << endl;
                        return 1;
                    }
                }

            }
        }
    }
    return 0;
}

vector<string> admin::showComments(){
    vector<string> lines;

    ifstream inputFile("comments.txt");
    if(!inputFile){
        cerr << "could not open comments.txt" << endl;
    }
    else{
        string line;
        while (getline(inputFile, line)){
            lines.push_back(line);
        }

        inputFile.close();
        
        for (const auto& line : lines){
            cout << line << "\n" ;
            return lines;
        }
    }
}
