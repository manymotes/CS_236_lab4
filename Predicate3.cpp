#include "Predicate3.h"   
#include "DLP3.h"
#include "Parameter3.h"
#include <sstream>
Parameter pram;
Predicate::Predicate() {
	ID = Token(-1, "", ""); 
	vector<Parameter> list;
	prams = list;
}
string Predicate::toString()
{
//	cout << "in prdcate to string : " << endl;
//	cout << "size of prams: " << prams.size() << endl;
	stringstream zz;
	zz << ID.getvalue() << "(";
	int a = prams.size();
	for (int i = 0; i < a; i++)
	  {
		zz << prams[i].toString();
	}
	zz << ")";
	return zz.str();
}
Predicate::Predicate(Token id, vector<Parameter> pram) {
	
	ID = id;
	prams = pram;

}

vector<Parameter> Predicate::getPlist() {
	return prams;
	
}
string Predicate::getID() {
	return ID.getvalue();
}
Token Predicate::getID_token()
{
	return ID;
}