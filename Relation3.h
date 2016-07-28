#pragma once
#include <string>
#include <iostream>
#include "Scheme3.h"
#include <vector>
#include <set>
#include "Tuple.h"

using namespace std;
class Relation {

public:
	Relation(string id, Scheme sch);
	Relation();
	void addID(string id);
	void addscheme(Scheme sch);
	void addtuple(Tuple tupleset);
	void addSvector(vector<string> stringy);
	Relation select(string, int);
	Relation selectTwo(int first, int second);
	Relation project(vector<int> pullSpots);
	Relation rename(vector<string> pulledstring);
	string getID();
	set<vector<string>> getSvector();
	Scheme getScheme();
	void setSet(set<vector<string>> newSet);
	void changescheme(vector<string> pulledstring);

	
	

private:
	string ID;
	Scheme Schemy;
	set<Tuple> Tupleset;
	set<vector<string>> stringlist;

};


/*
relation
- name sk string
- shceme(A, B) vector of strings
- set<tuples> of vector of strings

$ funcitons $
- select
compares(first under query evaluation)
it lookes at your set and it looks at which tuple has a c in the second via location of the vector.
it collects any tuple that fits the requirements

- project
after you have grabbed te tuples you need and it grabs the columbs that are variable columbs.
grab the A in(A, c)
- rename
rename will basicall change the name of the schema
you just chagne the place of the scheme to the query.
look under query evaluation under rrename.


WRITE intepreter after classes are finished

interpreter calss that is the equivalanet of the parcer class

*/