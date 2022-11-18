#include "Book.h"

//methods
void Book::showbookpopularity(std::string& titl, std::string& genr, std::string& autho)
{
	std::string file = "booklist.txt";
	setbook(titl, genr, autho);
	InformationSystem system;
	std::vector<std::vector<std::string>> output;
	system.setdata(file);
	output = system.getdata();
	for (int i = 0; i < output.size(); i++)
	{
		if (gettitle() == output[i][0] && getgenre() == output[i][1] && getauthor() == output[i][2])
		{
			std::cout << "Title: " << output[i][0] << " Genre: " << output[i][1] << " Author: " << output[i][2]
				<< " Book popularity: " << std::stoi(output[i][3]) << "\n";
			break;
		}
		if (i == output.size() - 1 && gettitle() != output[i][0] && getgenre() != output[i][1] && getauthor() != output[i][2]) 
			std::cout << "Book not found" << "\n";
	}
}
void Book::showbooktext(std::string& titl)
{
    InformationSystem data;
	settitle(titl);
    std::string book = titl+".txt";
	std::string file = "booklist.txt";
	std::vector<std::vector<std::string>> output;
	data.setdata(file);
	output = data.getdata();
	for (int i = 0; i < output.size(); i++)
	{
		if (gettitle() == output[i][0])
		{
			data.outtext(book);
			break;
		}
	}
	
}

//seter
void Book::setbook(std::string& titl, std::string& genr, std::string& autho)
{
    settitle(titl);
    setgenre(genr);
    setauthor(autho);
}
void Book::settitle(std::string& titl)
{
    title = titl;
}
void Book::setgenre(std::string& genr)
{
    genre = genr;
}
void Book::setauthor(std::string& autho)
{
    author = autho;
}

//geter
std::string Book::gettitle()
{
    return title;
}
std::string Book::getgenre()
{
    return genre;
}
std::string Book::getauthor()
{
    return author;
}