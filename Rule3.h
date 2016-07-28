#pragma once
#include "Predicate3.h"
#include "Token3.h"


class Rule {
public:
	Rule(Predicate ID, Token col_dash, vector<Predicate> list);
	string toString();
	//predicate COLON_DASH predicate predicateList PERIOD
private:
	Predicate id; 
	Token Col_dash;
	vector<Predicate> List;
};