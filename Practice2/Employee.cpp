#include "Employee.h"

//methods
void Employee::showdebtorlist()
{
    std::string debtor = "debtorlist.txt";
    InformationSystem system;
    std::vector<std::vector<std::string>> output;
    system.setdata(debtor);
    output = system.getdata();
    for (int i = 0; i < output.size(); i++)
    {
        std::cout << "User: " << output[i][0]<<" Title: "<< output[i][1] << " Genre: " << output[i][2] << " Author: " << output[i][3] << "\n";
    }
}
void Employee::addbook(std::string& titl, std::string& genr, std::string& autho)
{
    std::string file = "booklist.txt";
    std::string line = titl+","+genr+","+autho+",00000,\n";
    InformationSystem system;
    std::vector<std::vector<std::string>> output;
    system.setdata(file);
    output = system.getdata();
    system.insert(output, file, line);
}
void Employee::deletebook(std::string& titl)
{
    std::string file = "booklist.txt";
    std::string word = titl;
    InformationSystem system;
    std::vector<std::vector<std::string>> output;
    system.setdata(file);
    output = system.getdata();
    system.deletebyword(output, file, word);
}