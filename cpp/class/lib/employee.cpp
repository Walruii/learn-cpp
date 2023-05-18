#include <iostream>
#include "include/employee.h"

    Employee::Employee(std::string name, std::string company, int age)
    {
        this->Name = name;
        this->Age = age;
        this->Company = company;
    }
    void Employee::IntroduceYourself()
    {
        std::cout << Name << std::endl;
        std::cout << Company << std::endl;
        std::cout << Age << std::endl;
    }

    void Employee::setName (std::string name)
    {
        this->Name = name;
    }
    void Employee::setAge (int age)
    {
        this->Age = age;
    }
    void Employee::setCompany (std::string company)
    {
        this->Company = company;
    }

    std::string Employee::getName ()
    {
        return Name;
    }
    int Employee::getAge ()
    {
        return Age;
    }
    std::string Employee::getCompany ()
    {
        return Company;
    }

    void Employee::AskForPromotion()
    {
        if (Age <= 30)
        {
            std::cout << "Sorry Better Luck next year." << std::endl;
        }
        else
        {
            std::cout << Name << ", GOT A PROMOTION!!" << std::endl;
        }
    }
    void Employee::Work()
    {
        std::cout << "IM WORKING HEREE!" << std::endl;
    }

    Developer::Developer(std::string name, std::string company, int age, std::string favlang) : Employee(name, company, age)
    {
        this->FavLang = favlang;
    }
    void Developer::setFavLang(std::string favlang)
    {
        this->FavLang = favlang;
    }
    
    std::string Developer::getFavLang()
    {
        return FavLang;
    }

    void Developer::FixBug()
    {
        std::cout << getName() << " fixes bugs using " << FavLang << std::endl;
    }
    void Developer::Work()
    {
        std::cout << "IM WORKING HEREE WITH COMPUTEREESSSJ!" << std::endl;
    }

    Teacher::Teacher(std::string name, std::string company, int age, std::string subject) : Employee(name, company, age)
    {
        this->Subject = subject;
    }

    void Teacher::Work()
    {
        std::cout << "IM WORKING HEREEEE WIT HBOKKSSS!!" << std::endl;
    }
