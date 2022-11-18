#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Book.h"
#include "Employee.h"
#include "Reader.h"

class  InformationSystem
{
private:
	std::vector<std::vector<std::string>> data;
public:
	//data manipulations
	void insert(std::vector<std::vector<std::string>>& vect, std::string& filename, std::string& line);
	void deleteline(std::vector<std::vector<std::string>>& vect, std::string& filename, std::string& line);
	void deletebyword(std::vector<std::vector<std::string>>& vect, std::string& filename, std::string& word, int col=0);
	void update(std::vector<std::vector<std::string>>& vect, std::string& filename, bool isint=false, int col=0, int wide=0);
	void sortbycolumn(std::vector<std::vector<std::string>>& vect, std::string num);
	void outtext(std::string& filename);
	void outvector(std::vector<std::vector<std::string>>& vect);
	void outbyname(std::vector<std::vector<std::string>>& vect, std::string& name, std::string& col);
	void testprogram();

	//seter(save data to vector)
	void setdata(std::string& filename);

	//geter(get vector)
	std::vector<std::vector<std::string>> getdata();
};
	