#include "InformationSystem.h"

//data manipulations
void InformationSystem::insert(std::vector<std::vector<std::string>>& vect, std::string& filename, std::string& line)
{
    std::ofstream out(filename);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[0].size(); j++)
        {
            if (j != vect[0].size() - 1) out << vect[i][j] << ",";
            else out << vect[i][j]<<",\n";
        }
    }
    out << line;
    out.close();
}
void InformationSystem::deleteline(std::vector<std::vector<std::string>>& vect, std::string& filename, std::string& line)
{
    bool linedeleted = false;
    std::ofstream out(filename);
    for (int i = 0; i < vect.size(); i++)
    {
        std::string checkline{};
        for (int j = 0; j < vect[0].size(); j++)
        {
            if (j != vect[0].size() - 1) checkline +=vect[i][j]+",";

            else checkline +=vect[i][j] +",\n";

        }
        if (checkline == line && linedeleted == true)
        {
            for (int j = 0; j < vect[0].size(); j++)
            {
                if (j != vect[0].size() - 1) out << vect[i][j] << ",";

                else out << vect[i][j] << ",\n";


            }
        }
        if (checkline != line)
        {
            for (int j = 0; j < vect[0].size(); j++)
            {
                if (j != vect[0].size() - 1) out << vect[i][j] << ",";

                else out << vect[i][j] << ",\n";


            }
        }
        else linedeleted = true;
    }
    out.close();
}
void InformationSystem::deletebyword(std::vector<std::vector<std::string>>& vect, std::string& filename, std::string& word, int col)
{
    bool linedeleted = false;
    std::ofstream out(filename);
    for (int i = 0; i < vect.size(); i++)
    {
        
        std::string checkword{};
        checkword = vect[i][col];
        if (checkword == word && linedeleted == true)
        {
            for (int j = 0; j < vect[0].size(); j++)
            {
                if (j != vect[0].size() - 1) out << vect[i][j] << ",";

                else out << vect[i][j] << ",\n";


            }
        }
        if (checkword != word && linedeleted == false)
        {
            for (int j = 0; j < vect[0].size(); j++)
            {
                if (j != vect[0].size() - 1) out << vect[i][j] << ",";

                else out << vect[i][j] << ",\n";


            }
        }
        else linedeleted = true;
    }
    out.close();
}
void InformationSystem::update(std::vector<std::vector<std::string>>& vect, std::string& filename, bool isint, int col, int wide)
{
    std::ofstream out(filename);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[0].size(); j++)
        {
            if (isint == true)
            {
                if (j != col)
                {
                    out << vect[i][j] << ",";
                }
                else
                {
                    out << std::setw(wide) << std::setfill('0') << vect[i][j] << ",\n";
                }
            }
            else
            {
                if (j != vect[0].size() - 1) out << vect[i][j] << ",";
                else out << vect[i][j] << ",\n";
            }
            
        }
    }
    out.close();
}
bool columnstring(const std::vector<std::string>& v1, const std::vector<std::string>& v2)
{
    InformationSystem system;
    std::string file = "column.txt";
    std::vector<std::vector<std::string>> output;
    system.setdata(file);
    output = system.getdata();
    return v1[std::stoi(output[0][0])] < v2[std::stoi(output[0][0])];
}
void InformationSystem::sortbycolumn(std::vector<std::vector<std::string>>& vect, std::string num)
{
    std::string file = "column.txt";
    std::ofstream out(file);
    out << num;
    out.close();
    sort(vect.begin(), vect.end(), columnstring);
}
void InformationSystem::outtext(std::string& filename)
{
    std::ifstream in(filename);
    std::string line;
    while (std::getline(in, line))
    {
        std::cout << line <<std::endl;
    }
    in.close();
}
void InformationSystem::outvector(std::vector<std::vector<std::string>>& vect)
{
    for (int i = 0; i < vect.size(); i++)
    {

        for (int j = 0; j < vect[0].size(); j++)
        {
            std::cout << vect[i][j]+" ";
        }
        std::cout << "\n";
    }
}
void InformationSystem::outbyname(std::vector<std::vector<std::string>>& vect, std::string& name, std::string& col)
{
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i][std::stoi(col)]==name)
        {
            for (int j = 0; j < vect[0].size(); j++)
            {
                std::cout << vect[i][j] + " ";
            }
            std::cout << "\n";
        }
        
       
    }
}
void InformationSystem::testprogram()
{
    Book book;
    Reader reader;
    Employee employee;
    int select, man;
    std::string manstr = " 1. Use prefab\n 2. Set manually\n";

    
        while (true)
        {
            try 
            {
            std::string booktitle = "Bride of Princes", bookgenre = "Fantasy", bookauthor = "SCOUT WARREN";
            std::string booktitle1 = "Bride", bookgenre1 = "Xz", bookauthor1 = "SCOUT";
            std::string title1 = "titletext1", title2 = "titletext2";
            std::string nam = "gg", surnam = "gg", usernam = "gg", mail = "gg", password = "gg";
            std::cout
                << "Select method\n"
                << " 1. Show book popularity\n"
                << " 2. Show book text\n"
                << " 3. Reader registration\n"
                << " 4. Reader login\n"
                << " 5. Show book list\n"
                << " 6. Show books(bt genre + count)\n"
                << " 7. Show book list by column\n"
                << " 8. Show book list by name\n"
                << " 9. Take a book\n"
                << "10. Return a book\n"
                << "11. Show debtors list\n"
                << "12. Add book\n"
                << "13. Delete book\n"
                << "14. End program\n";

            std::cin >> select;

            if (select < 1 || select>14) break;
            if (select == 1)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) book.showbookpopularity(booktitle, bookgenre, bookauthor);
                if (man == 2)
                {
                    std::cout << "Enter: book title; book genre; book author\n";
                    std::getline(std::cin, booktitle);
                    std::getline(std::cin, booktitle);
                    std::getline(std::cin, bookgenre);
                    std::getline(std::cin, bookauthor);
                    //std::cin >> booktitle >> bookgenre >> bookauthor;
                    book.showbookpopularity(booktitle, bookgenre, bookauthor);
                }
            }
            else if (select == 2)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) book.showbooktext(title2);;
                if (man == 2)
                {
                    std::cout << "Enter: book title\n";
                    std::getline(std::cin, title2);
                    std::getline(std::cin, title2);
                    //std::cin >> title2;
                    book.showbooktext(title2);;
                }
            }
            else if (select == 3)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) reader.readerregistration(nam, surnam, usernam, mail, password);
                if (man == 2)
                {
                    std::cout << "Enter: name; surname; username; mail; password\n";
                    std::cin >> nam >> surnam >> usernam >> mail >> password;
                    reader.readerregistration(nam, surnam, usernam, mail, password);
                }
            }
            else if (select == 4)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) reader.login(usernam, password);
                if (man == 2)
                {
                    std::cout << "Enter: username; password\n";
                    std::cin >> usernam >> password;
                    reader.login(usernam, password);
                }
            }
            else if (select == 5)
            {
                reader.showbooklist();
            }
            else if (select == 6)
            {
                reader.showbooks();
            }
            else if (select == 7)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) reader.showbooklistbycolumn("3");
                if (man == 2)
                {
                    std::string colu;
                    std::cout << "Enter: column(0/1/2/3)\n";
                    std::cin >> colu;
                    reader.showbooklistbycolumn(colu);
                }
            }
            else if (select == 8)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) reader.showbooklistbyname(bookgenre, "1");
                if (man == 2)
                {
                    std::string colu;
                    std::cout << "Enter: name; col(0/1/2)\n";
                    std::getline(std::cin, bookgenre);
                    std::getline(std::cin, bookgenre);
                    std::cin >> colu;
                    reader.showbooklistbyname(bookgenre, colu);
                }
            }
            else if (select == 9)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) reader.takeabook(booktitle, bookgenre, bookauthor);
                if (man == 2)
                {
                    std::cout << "Enter: book title; book genre; book author\n";
                    std::getline(std::cin, booktitle);
                    std::getline(std::cin, booktitle);
                    std::getline(std::cin, bookgenre);
                    std::getline(std::cin, bookauthor);
                    //std::cin >> booktitle >> bookgenre >> bookauthor;
                    reader.takeabook(booktitle, bookgenre, bookauthor);
                }
            }
            else if (select == 10)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) reader.returnabook(booktitle, bookgenre, bookauthor);
                if (man == 2)
                {
                    std::cout << "Enter: book title; book genre; book author\n";
                    std::getline(std::cin, booktitle);
                    std::getline(std::cin, booktitle);
                    std::getline(std::cin, bookgenre);
                    std::getline(std::cin, bookauthor);
                    //std::cin >> booktitle >> bookgenre >> bookauthor;
                    reader.returnabook(booktitle, bookgenre, bookauthor);
                }
            }
            else if (select == 11)
            {
                employee.showdebtorlist();
            }
            else if (select == 12)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) employee.addbook(booktitle1, bookgenre1, bookauthor1);
                if (man == 2)
                {
                    std::cout << "Enter: book title; book genre; book author\n";
                    std::getline(std::cin, booktitle1);
                    std::getline(std::cin, booktitle1);
                    std::getline(std::cin, bookgenre1);
                    std::getline(std::cin, bookauthor1);
                    //std::cin >> booktitle1 >> bookgenre1 >> bookauthor1;
                    employee.addbook(booktitle1, bookgenre1, bookauthor1);
                }
            }
            else if (select == 13)
            {
                std::cout << manstr;
                std::cin >> man;
                if (man == 1) employee.deletebook(booktitle1);
                if (man == 2)
                {
                    std::cout << "Enter: book title\n";
                    std::getline(std::cin, booktitle1);
                    std::getline(std::cin, booktitle1);
                    //std::cin >> booktitle1;
                    employee.deletebook(booktitle1);
                }
            }
            else if (select == 14)
            {
                break;
            }
            }
            catch (...) 
            {
                std::cout << "Error\n";
            }
        }
    
    
   
}

//seter
void InformationSystem::setdata(std::string& filename)
{
    data.clear();
    std::ifstream in(filename);
    std::string line, word;
    while (std::getline(in, line))
    {
        std::istringstream ss(line);
        std::vector<std::string> substrings{};
        std::string substring{};
        while (std::getline(ss, substring, ','))
        {
            substrings.push_back(substring);
        }
        data.push_back(substrings);
    }
    in.close();
}


//geter
std::vector<std::vector<std::string>> InformationSystem::getdata()
{
    return data;
}