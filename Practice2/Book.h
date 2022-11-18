#pragma once

#include "InformationSystem.h"

class Book
{
private:
	std::string title;
	std::string genre;
	std::string author;
public:

	//methods
	void showbookpopularity(std::string& titl, std::string& genr, std::string& autho);
	void showbooktext(std::string& titl);

private:

	//seter
	void setbook(std::string& titl, std::string& genr, std::string& autho);
	void settitle(std::string& titl);
	void setgenre(std::string& genr);
	void setauthor(std::string& autho);

	//geter
	std::string gettitle();
	std::string getgenre();
	std::string getauthor();

};