#include"dishes.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

dishes::dishes(const string& dN, const string& dI, const string& loc, const string& pr)
    : dishName(dN), dishIngredients(dI), location(loc), price(pr){ }

dishes::~dishes(){}

bool dishes::deleteDish(const string& dN){
    ifstream inputFile("dishes.txt");
    if(!inputFile){
        cerr << "could not open dishes.txt" << endl;
        return 0;
    }
    else{
        ofstream tempFile("temp.txt");
        if(!tempFile){
            cerr << "could not build temp.txt" << endl;
            return 0;
        }
        else{
            string line;
            while (getline(inputFile, line)){
                stringstream ss(line);
                string firstWord;
                ss >> firstWord;

                if(firstWord != dN){
                    tempFile << line << endl;

                }
            }

            inputFile.close();
            tempFile.close();

            if (remove("dishes.txt") != 0){
                cerr << "could not delete dishes.txt" << endl;
                return 0;
            }
            else{
                if (rename("temp.txt", "dishes.txt") != 0){
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
    return 0;
}

vector<string> dishes::showDish(){
    vector<string> lines;

    ifstream inputFile("dishes.txt");
    if(!inputFile){
        cerr << "could not open dishes.txt" << endl;
    }
    else{
        string line;
        while (getline(inputFile, line)){
            lines.push_back(line);
        }

        inputFile.close();

        
        for (const auto& line : lines){
            cout << line << "\n" ;
        }


    }
    return lines;
}

string dishes::searchDish(const string& dN){
    string tarline ;
    ifstream inputFile("dishes.txt");
    if (!inputFile){
        cerr << "could not open dishes/txt" << endl;
    }
    else{
        string line;
        while(getline(inputFile, line)){
            stringstream ss(line);
            string firstWord;
            ss >> firstWord;

            if (firstWord == dN){
                tarline = line;
                break;
            }
        }
        if (tarline.empty()){
            cout << "dish does not exist" << endl;
        }
        else{
            cout << tarline << endl;
        }

        inputFile.close();
    }
    return tarline;
}

stir_fry::stir_fry(const std::string& dN, const string& dI, const string& loc, const string& pr, const string& mv, const string& sp)
    : dishes(dN, dI, loc, pr), meat_vegetable(mv), spicy(sp) {}

stir_fry::~stir_fry(){}

void stir_fry::addDish(){
    ofstream outputFile("dishes.txt", std::fstream::app);
    if (!outputFile){
        cerr << "could not opendishes.txt" << endl;
    }
    else{
        string addLine = dishName + " 炒菜类 " + dishIngredients+ " " + location + " " + price + " " + meat_vegetable + " " + spicy;
        outputFile << addLine << endl;
        outputFile.close();
        cout << "dish add successful" << endl;
    }
    outputFile.close();
}

noodle_soup::noodle_soup(const std::string& dN, const std::string& dI, const std::string& loc, const std::string& pr, const std::string& fl, const std::string& fe)
    : dishes(dN, dI, loc, pr), flavour(fl), feeding(fe){}

noodle_soup::~noodle_soup(){}

void noodle_soup::addDish(){
    ofstream outputFile("dishes.txt", std::fstream::app);
    if (!outputFile){
        cerr << "could not open dishes.txt" << endl;
    }
    else{
        string addLine = dishName + " 汤面类 " + dishIngredients+ " " + location + " " + price + " " + flavour + " " + feeding;
        outputFile << addLine << endl;
        outputFile.close();
        cout << "dish add successful" << endl;
    }

    outputFile.close();
}

otherdish::otherdish(const string& dN, const string& dI, const string& loc, const string& pr, const string& sort, const string& note1, const string& note2, const string& note3)
    : dishes(dN, dI, loc, pr), sort(sort), note1(note1), note2(note2), note3(note3){}

otherdish::~otherdish(){}

void otherdish::addDish(){
    ofstream outputFile("dishes.txt", std::fstream::app);
    if (!outputFile){
        cerr << "could not open dishes.txt" << endl;
    }
    else{
        string addLine = dishName + " " + sort + " " + dishIngredients+ " " + location + " " + price + " " + note1 + " " + note2 + " " + note3;
        outputFile << addLine << endl;
        outputFile.close();
        cout << "dish add successful" << endl;
    }
    outputFile.close();

}
