#include "Relation3.h"
#include <algorithm>

Relation::Relation(string id, Scheme sch) {
	ID = id;
	Schemy = sch;


}
Relation::Relation() {
	ID = "";
	Scheme sch;
	Schemy = sch;
	
}
void Relation::addID(string id) {
	ID = id;
}
void Relation::addscheme(Scheme sch) {
	Schemy = sch;
}
void Relation::addtuple(Tuple tupleset) {
	//Tupleset.insert(tupleset);
}
void Relation::addSvector(vector<string> stringy) {

		stringlist.insert(stringy);
	
}
Relation Relation::select(string stringy, int inty) {
	
	Relation toreturn(ID, Schemy);
//	set<vector<string>> addSet;
	set<vector<string>>::iterator ir;
	for (ir = stringlist.begin(); ir != stringlist.end(); ++ir)
	{
		vector<string> searchlist = *ir;
		
		if (searchlist[inty] == stringy)
		{
			toreturn.addSvector(searchlist);
		}
		
	}
	return toreturn;
}
Relation Relation::selectTwo(int first, int second) {
	Relation toreturn(ID, Schemy);
	set<vector<string>>::iterator ir;
	for (ir = stringlist.begin(); ir != stringlist.end(); ++ir)
	{
		vector<string> tempvect = *ir;
		if (tempvect[first] == tempvect[second]) {
			toreturn.addSvector(tempvect);
		}

	}
	return toreturn;
}
Relation Relation::project(vector<int> pullSpots) {
	vector<string> pulledString;


	vector<string> schemelist = Schemy.getList();
	for (int p = 0; p < pullSpots.size(); p++)
	{
		pulledString.push_back(schemelist[pullSpots[p]]);
	}
		
	Scheme tempScheme(ID, pulledString);
	Relation toreturn(ID, tempScheme);
		
	set<vector<string>>::iterator ir;
	for (ir = stringlist.begin(); ir != stringlist.end(); ++ir)
	  {
		vector<string> newTuple;
		vector<string> tempvect = *ir;
		for (int k = 0; k < pullSpots.size(); k++)
		{
			newTuple.push_back(tempvect[pullSpots[k]]);
		}
		toreturn.addSvector(newTuple);
	}
	return toreturn;

}
Relation Relation::rename(vector<string> pulledstring) {
	Scheme tempscheme(ID, pulledstring);
	Relation Toreturn(ID, tempscheme);
	Toreturn.setSet(stringlist);
	
//	Scheme tempscheme(ID, pulledstring);
//	Relation returner(ID, pulledstring);

	return Toreturn;
}
string Relation::getID()
{
	return ID;
}
set<vector<string>> Relation::getSvector() {
	return stringlist;
}
Scheme Relation::getScheme() {
	return Schemy;
}

void Relation::changescheme(vector<string> pulledstring)
{
	Scheme temp(ID, pulledstring);
		Schemy = temp;
}
void Relation::setSet(set<vector<string>> newSet)
{
	stringlist = newSet;
}
/*
-select
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
*/
