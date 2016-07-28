#pragma once
#include "Predicate3.h"

class Scheme {

public:
	Scheme();
	Scheme(string a, vector<string> list);
	string getid();
	vector<string> getList();
	
private:
	string A;
	vector<string> List;
};
