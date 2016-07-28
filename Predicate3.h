#pragma once
#include <iostream>
#include <vector>
#include "Parameter3.h"
#include "Token3.h"
using namespace std;
class Predicate {

public:
	Predicate();
	Predicate(Token id, vector<Parameter> preList);
	string toString();
	vector<Parameter> getPlist();
	string getID();
	Token getID_token();
	//vector<Parameter> getPredicates();
	
	
private:
	Token ID;
	vector<Parameter> prams;
};
/*
predicateList->COMMA predicate predicateList
predicateList->epsilon

predicate->ID LEFT_PAREN parameter parameterList RIGHT_PAREN
*/