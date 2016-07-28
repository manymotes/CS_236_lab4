#pragma once
#include "Predicate3.h"
#include "Rule3.h"
#include <vector>


class DLP {

	public:
		DLP();
		DLP(vector<Rule> rulel, vector<Predicate> factl, vector<Predicate> queryl, vector<Predicate> schemel);
		vector<Predicate> getFacts();
		vector<Rule> getRules();
		vector<Predicate> getQueries();
		vector<Predicate> getSchemes();

private:
	vector<Rule> Rulel;
	vector<Predicate> Factl;
	vector<Predicate> Queryl;
	vector<Predicate> Schemel;

			//database calsee containng schemes facts and queries
};