#pragma once

#pragma once
#include "Predicate3.h"
#include <iostream>
#include <vector>
#include <string>
#include "Token3.h"
#include "Scheme3.h"
#include "Queries3.h"
#include "Fact3.h"
#include "Rule3.h"
#include <set>
#include "DLP3.h"
//#include "DatalogProgram.h"


using namespace std;
class Parser {


public:
	Predicate predicate();
	Parser();
	void get_vector(vector<Token> scannedlist);
	Token match(string type);
	void schemeList();

	void queryList();
	void factList();
	void ruleList();
	vector<Predicate> schemes();
	vector<Predicate> facts();
	vector<Rule> rules();
	vector<Predicate> queries();
	void predicateList();
	Parameter parameter();
	//void parameterList();
	vector<string> getstring();
	vector<Token> collection;


	//DatalogProgram prase(string parsename, string exportname);

	//vector<DatalogProgram> datalogs;
	void toString();
	DLP datalogprogram(string name);

private:

	vector<Predicate> vschemes;
	vector<Predicate> vfacts;
	vector<Predicate> vrules;
	vector<Predicate> vqueries;

	int location;

};