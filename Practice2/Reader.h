#pragma once

#include "InformationSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

class Reader
{
private:
	std::string name{""};
	std::string surname{""};
	std::string username{""};
	std::string email{""};
	std::string password{""};
public:

	//methods
	void readerregistration(std::string& nam, std::string& surnam, std::string& usernam, std::string& ema, std::string& pas);
	void login(std::string& usernam, std::string& pas);
	void takeabook(std::string& title, std::string& genre, std::string& author);
	void returnabook(std::string& title, std::string& genre, std::string& author);
	void showbooklist();
	void showbooks();
	void showbooklistbycolumn(std::string num);
	void showbooklistbyname(std::string name, std::string col);

private:

	//seterai
	void setreader(std::string& nam, std::string& surnam, std::string& usernam, std::string& ema, std::string& pas);
	void setname(std::string& nam);
	void setsurname(std::string& surnam);
	void setusername(std::string& usernam);
	void setemail(std::string& ema);
	void setpassword(std::string& pas);

	//geterai
	std::string getname();
	std::string getsurname();
	std::string getusername();
	std::string getemail();
	std::string getpassword();

	//check
	bool logincheck();
};