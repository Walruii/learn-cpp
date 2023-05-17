#include <iostream>
#include <fstream>

class student 
{
    public:
        std::string name;
        int roll;
};

int main (int argc, char *argv[]) 
{
    student s;
    std::cout << "Enter your name" << std::endl;
    std::cin >> s.name;
    std::cout << "What is your roll number" << std::endl;
    std::cin >> s.roll;

    std::ofstream fout;
    fout.open("./data/students.txt", std::ios::app);
    fout.write((char*)&s, sizeof(s));
    fout.close();
    std:: fstream fin;
    fin.open("./data/students.txt", std::ios::in);
    fin.read((char*)&s, sizeof(s));
    while (!fin.eof())
    {
        fin.read((char*)&s, sizeof(s));
        std::cout << s.name << std::endl;
        std::cout << s.roll << std::endl;
    }
    fin.close();
    return 0;
}
