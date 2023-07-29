#pragma once
#include <cwchar>
#include <iostream>
#include <random>

class IEmployee {
  virtual void AskForPromotion() = 0;
};

class Employee : IEmployee {
  // There are three access modifiers
  // public / private / protected
private:
  std::string Name;
  std::string Company;
  int Age;

public:
  Employee(std::string name, std::string company, int age);
  void IntroduceYourself();
  void setName(std::string name);
  void setAge(int age);
  void setCompany(std::string company);
  std::string getName();
  int getAge();
  std::string getCompany();
  void AskForPromotion();
  virtual void Work();
};

class Developer : public Employee {
private:
  std::string FavLang;

public:
  Developer(std::string name, std::string company, int age,
            std::string favlang); // : Employee(name, company, age);
  void setFavLang(std::string favlang);
  std::string getFavLang();
  void FixBug();
  void Work();
};

class Teacher : public Employee {
private:
  std::string Subject;

public:
  Teacher(std::string name, std::string company, int age,
          std::string subject); // : Employee(name, company, age);
  void Work();
};
