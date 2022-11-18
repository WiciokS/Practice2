#include "Reader.h"

//seterai
void Reader::setreader(std::string& nam, std::string& surnam, std::string& usernam, std::string& ema, std::string& pas)
{

	setname(nam);
	setsurname(surnam);
	setusername(usernam);
	setemail(ema);
	setpassword(pas);
}

void Reader::setname(std::string& nam)
{
	name = nam;
}
void Reader::setsurname(std::string& surnam)
{
	surname = surnam;
}
void Reader::setusername(std::string& usernam)
{
	username = usernam;
}
void Reader::setemail(std::string& ema)
{
	email = ema;
}
void Reader::setpassword(std::string& pas)
{
	password = pas;
}

//geterai
std::string Reader::getname()
{
	return name;
}
std::string Reader::getsurname()
{
	return surname;
}
std::string Reader::getusername()
{
	return username;
}
std::string Reader::getemail()
{
	return email;
}
std::string Reader::getpassword()
{
	return password;
}

//methods
bool Reader::logincheck()
{
	if (username == "") return false;
	else return true;
}
void Reader::readerregistration(std::string& nam, std::string& surnam, std::string& usernam, std::string& ema, std::string& pas)
{
	Reader newregister;
	newregister.setreader(nam, surnam, usernam, ema, pas);
	std::string file = "readerregistrationlist.txt";
	std::string line = newregister.getname() + "," + newregister.getsurname() + "," + newregister.getusername() + ","
		+ newregister.getemail() + "," + newregister.getpassword() + ",\n";
	std::vector<std::vector<std::string>> cursave;

	InformationSystem system;
	system.setdata(file);
	cursave = system.getdata();
	system.insert(cursave, file, line);

	std::cout << "Successful registration of: " << newregister.getusername() << "\n";
}
	

void Reader::login(std::string& usernam, std::string& pas)
{
	std::string file = "readerregistrationlist.txt";
	std::vector<std::vector<std::string>> cursave;
	InformationSystem system;
	system.setdata(file);
	cursave = system.getdata();
	for (int i=0;i<cursave.size();i++)
	{
		if (cursave[i][2] == usernam && cursave[i][4] == pas)
		{
			setusername(usernam);
			std::cout << "Successful login of: " << getusername() << "\n";
			break;
		}
		if (i == cursave.size() -1)
		{
			std::cout << "Login declined!" << "\n";
		}
	}
}
void Reader::takeabook(std::string& title, std::string& genre, std::string& author)
{
	if (logincheck())
	{
		std::string file = "booklist.txt";
		std::string debtor = "debtorlist.txt";
		std::string line;
		InformationSystem system;
		std::vector<std::vector<std::string>> cursave;
		system.setdata(file);
		cursave = system.getdata();
		for (int i = 0; i < cursave.size(); i++)
		{
			if (cursave[i][0] == title && cursave[i][1] == genre && cursave[i][2] == author)
			{
				line = getusername() + "," + title + "," + genre + "," + author + ",\n";
				system.setdata(debtor);
				cursave = system.getdata();
				system.insert(cursave, debtor, line);
				std::cout << "Book: " + title + " successfuly taked)" << std::endl;
				system.setdata(file);
				cursave = system.getdata();
				for (int i = 0; i < cursave.size(); i++)
				{
					if (cursave[i][0] == title && cursave[i][1] == genre && cursave[i][2] == author)
					{
						cursave[i][3] = std::to_string(std::stoi(cursave[i][3]) + 1);
						break;
					}
				}
				break;
			}
			if (i == cursave.size() - 1)
			{
				std::cout << "Book not found!" << "\n";
			}
		}
		system.update(cursave, file,true,3,5);

	}
	else std::cout << "You are not logged in!\n";
	
}
void Reader::returnabook(std::string& title, std::string& genre, std::string& author)
{
	if (logincheck())
	{
		std::string debtor = "debtorlist.txt";
		std::string line;
		InformationSystem system;
		std::vector<std::vector<std::string>> cursave;
		system.setdata(debtor);
		cursave = system.getdata();
		for (int i = 0; i < cursave.size(); i++)
		{
			if (cursave[i][1] == title && cursave[i][2] == genre && cursave[i][3] == author)
			{
				line = getusername() + "," + title + "," + genre + "," + author + ",\n";
				system.deleteline(cursave, debtor, line);
				std::cout << "Book returned!\n";
				break;
			}
		}
	}
	else std::cout << "You are not logged in!\n";
	
}
void Reader::showbooklist()
{
	std::string file = "booklist.txt";
	InformationSystem system;
	std::vector<std::vector<std::string>> output;
	system.setdata(file);
	output = system.getdata();
	for (int i = 0; i < output.size(); i++)
	{
		std::cout << "Title: " << output[i][0] << " Genre: " << output[i][1] << " Author: " << output[i][2] << "\n";
	}

}
void Reader::showbooks()
{
	std::string file = "booklist.txt";
	InformationSystem system;
	std::vector<std::vector<std::string>> output;
	std::vector<std::string> check;
	system.setdata(file);
	output = system.getdata();
	system.sortbycolumn(output, "1");
	//sort(output.begin(),output.end(), compare_col);
	for (int i = 0; i < output.size(); i++)
	{
		//std::cout << output[i][0] + "," + output[i][1] + "," + output[i][2] + "," + output[i][3] + ",\n";
		check.push_back(output[i][1]);
	}
	//for descending add , std::greater <std::string>()
	//sort(check.begin(), check.end());
	int num = 1;
	for (int i = 0; i < check.size(); i++)
	{
		if (i != 0)
		{
			if (check[i] == check[i - 1])
			{
				num++;
			}
			if (check[i] != check[i - 1])
			{
				std::cout << "Genre: " << check[i - 1] << " Count: " << num << "\n";
				num = 1;
			}
			if (i == check.size() - 1) std::cout << "Genre: " << check[i] << " Count: " << num << "\n";
		}

	}
}
void Reader::showbooklistbycolumn(std::string num)
{
	std::string file = "booklist.txt";
	InformationSystem system;
	std::vector<std::vector<std::string>> output;
	system.setdata(file);
	output = system.getdata();
	system.sortbycolumn(output, num);
	system.outvector(output);
}
void Reader::showbooklistbyname(std::string name, std::string col)
{
	std::string file = "booklist.txt";
	InformationSystem system;
	std::vector<std::vector<std::string>> output;
	system.setdata(file);
	output = system.getdata();
	system.outbyname(output,name, col);
}