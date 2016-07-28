#pragma once
#include "DLP3.h"
#include <set>
#include "Relation3.h"
#include <map>

class Database {
public: 

	Database();
	void intbase(DLP hold);
	void work();
	set<string, Relation> sety;
	map<string, Relation> mappy;
	set<string> IDset;
	set<string> newIDset;
	vector<vector<Parameter>> updated_quaries;

private:
	DLP dlphold;
	

};