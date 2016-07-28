#pragma once

//#include "Enum.h"
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;
class Token
{
public:
	Token();
	Token(int line, std::string type, std::string value);
	int getline();
	std::string getvalue();
	std::string gettype();
	std::string toString();

private:
	std::string value;
	std::string type;
	int line;




};