#ifndef DISHES_H
#define DISHES_H
#include<string>
#include<vector>

class dishes{
    public:
        dishes(const std::string& dN, const std::string& dI, const std::string& loc, const std::string& pr);
        ~dishes();
        static bool deleteDish(const std::string& dN);
        static std::vector<std::string> showDish();
        static std::string searchDish(const std::string& dN);
        
    protected:
        std::string dishName;
        std::string dishIngredients;
        std::string location;
        std::string price;

};

class stir_fry : public dishes{
    public:
        stir_fry(const std::string& dN, const std::string& dI, const std::string& loc, const std::string& pr, const std::string& mv, const std::string& sp);
        ~stir_fry();
        void addDish();

    private:
        std::string meat_vegetable;
        std::string spicy;
};

class noodle_soup : public dishes{
    public:
        noodle_soup(const std::string& dN, const std::string& dI, const std::string& loc, const std::string& pr, const std::string& fl, const std::string& fe);
        ~noodle_soup();
        void addDish();

    private:
        std::string flavour;
        std::string feeding;
};

class otherdish : public dishes{
    public:
    otherdish(const std::string& dN, const std::string& dI, const std::string& loc, const std::string& pr, const std::string& sort, const std::string& note1, const std::string& note2, const std::string& note3 );
    ~otherdish();
    void addDish();

    private:
        std::string sort;
        std::string note1;
        std::string note2;
        std::string note3;

};

#endif
