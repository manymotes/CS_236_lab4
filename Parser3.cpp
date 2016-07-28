#include "DLP3.h"
#include "Parameter3.h"
#include "Predicate3.h"
#include "Parser3.h"
#include "Token3.h"
#include <sstream>
#include "Queries3.h"
#include "Scheme3.h"
#include "Rule3.h"
#include <fstream>
#include <algorithm>  

Parser::Parser()
{

}
void Parser::get_vector(vector<Token> scannedlist)
{
	collection = scannedlist;
	/*	int holder = scannedlist.size();
	for (int i = 0; i < holder; i++)
	{
	collection[i] = scannedlist[i];
	}
	*/
	location = 0;
}
Token Parser::match(string type) {
	//cout << "1" << endl;
	if (collection[location].gettype() != type)
	{
	//	cout << "Throwing in mathch expected: " << type  << endl;
		Token e = collection[location];
		throw e;
	}
	location += 1;
	//cout << "leaving 1" << endl;
	return collection[location - 1];
}
void Parser::schemeList() {
	//schemes();
	//schemeList();

	/*
	match("ID");
	match("LEFT_PAREN");
	match("ID");
	while (collection[location].gettype() != "Right _Paren") {
	match("COMMA");
	match("ID");
	}
	*/
}
void Parser::factList() {
	//facts();
	//factList();
}
void Parser::ruleList() {
//	rules();
//	ruleList();
}
void Parser::queryList() {
//	queries();
//	queryList();
}
vector<Predicate> Parser::facts() {
	//cout << "2" << endl;
	if (collection[location].gettype() == "RULES")
	{
	//	cout << "in empty FACT" << endl;
		vector<Predicate> empty;
		return empty;
 	}
	Token a = match("ID");
	vector<Predicate> list;
	location -= 1;
	list.push_back(predicate());
	match("PERIOD");
	while (collection[location].gettype() == "ID") {
		list.push_back(predicate());
		//cout << "about to call period mathc" << endl;
		match("PERIOD");
	}
//	Fact b = Fact(list);
	//cout << "leaving 2" << endl;
	return list;
}
vector<Predicate> Parser::schemes()
{
	
//	cout << "3" << endl;
	Token a = match("ID");
	location -= 1;
	
	vector<Predicate> list;
	list.push_back(predicate());
	//match("LEFT_PAREN");
	while (collection[location].gettype() == "ID") {
		list.push_back(predicate());
		/*if (collection[location].gettype() == "COMMA")
		{
			location += 1;
		}
		*/
	}
	//Scheme b = Scheme(a, list);
	//cout << "leaving 3" << endl;
	return list;

}
vector<Rule> Parser::rules() {
//	cout << "4" << endl;
	if (collection[location].gettype() == "SCHEMES")
	{
		//cout << "in empty FACT" << endl;
		vector<Rule> empty;
		return empty;
	}
	vector<Rule> ru;
	while (collection[location].gettype() == "ID")
	{
		Predicate p = predicate();
		Token a = match("COLON_DASH");
		if (collection[location].gettype() != "ID")
		{
			Token e = collection[location];
			throw e;
		}
	vector<Predicate> list;
	while (collection[location].gettype() == "ID" || collection[location].gettype() == "COMMA")
	{
		if (collection[location].gettype() == "COMMA") {
			match("COMMA");
		}
		list.push_back(predicate());
	}

	Rule b = Rule(p, a, list);
	ru.push_back(b);
	//cout << "about to matchte period in rules" << endl;
	match("PERIOD");
}
	//cout << "leaving 4" << endl;
	return ru;
	
	
	
	//
}
vector<Predicate> Parser::queries() {
	
//	cout << "5" << endl;
	Token a = match("ID");
	location -= 1;
	vector<Predicate> list;
	list.push_back(predicate());
	match("Q_MARK");
	while (collection[location].gettype() == "ID"){
		list.push_back(predicate());
		match("Q_MARK");
}
	//Query b = Query(list);
	//cout << "leaving 5" << endl;
	return list;
}

void Parser::toString() {
	if (collection[location].gettype() == "COMMA")
	{
		if (collection[location + 1].gettype() == "COMMA")
		{
			Token e = collection[location + 1];
			throw e;
		}
	}
}
Predicate Parser::predicate() {
	//cout << "6" << endl;

	Token a = match("ID");
//	cout << endl << "matched id in predicate: " << a.getvalue() << endl << endl;
	vector<Parameter> plist;
	Token b = match("LEFT_PAREN");
	//	cout << endl << "matched left paren in predicate: " << b.getvalue() << endl << endl;

	if (collection[location].gettype() == "RIGHT_PAREN")
	{
		Token e = collection[location];
		throw e;
	}
	if (collection[location].gettype() == "COMMA")
	{
		Token e = collection[location];
		throw e; 
	}
	while (collection[location].gettype() != "RIGHT_PAREN")
	{
		toString();

		if (collection[location].gettype() != "COMMA")
		{
			if (collection[location + 1].gettype() != "COMMA" && collection[location + 1].gettype() != "RIGHT_PAREN")
			{
				Token e = collection[location + 1];
				throw e;
			}
		}
		plist.push_back(parameter());
		location += 1;
	}
	//plist.push_back(parameter());
	//parameterList();
	//cout << "match in te prdicate function " << endl;
	match("RIGHT_PAREN");
	Predicate l = Predicate(a, plist);
//	cout << "leaving 6" << endl;
	return l;
}
void Parser::predicateList()
{
	//match("COMMA");
	//predicate();
	//predicateList();
	

}
Parameter Parser::parameter() {
//	cout << "7" << endl;
	if (collection[location].gettype() == "STRING")
	{
		
		Parameter l = Parameter(collection[location]);
	//	location += 1;
		return l;
	}
	else if (collection[location].gettype() == "ID")
	{
		Parameter l = Parameter(collection[location]);
		//location += 1;
		return l;
	}
	else if (collection[location].gettype() == "COMMA")
	{
		Parameter l = Parameter(collection[location]);
		//location += 1;
		return l;
	}
	else {
	//	cout << "throw int the parameter functionn " << endl;
		Token e =  collection[location];
		throw e;
	}
//	cout << "leaving 7" << endl;
}
/*
vecotr<Parameter> Parser::parameterList() {
	vector<Parameter> list;

	match("COMMA");
	 parameter();
	parameterList();
}*/
vector<string> Parser::getstring() {

	//domain should take facts and QUIREIOS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	vector<string> toReturn;

	//set<std::string> s
	vector<Parameter> holder;
	for (int i = 0; i < collection.size(); i++)
	{
		if (collection[i].gettype() == "STRING")
		{
			if (find(toReturn.begin(), toReturn.end(), collection[i].getvalue()) == toReturn.end()) {
				toReturn.push_back(collection[i].getvalue());
			}
		}
	}
	sort(toReturn.begin(), toReturn.end());
	return toReturn;
}
DLP Parser::datalogprogram(string name) {
	try {
		vector<Rule> rulel;
		vector<Predicate> factl;
		vector<Predicate> queryl;
		vector<Predicate> schemel;
		
		match("SCHEMES");
		match("COLON");
		schemel = schemes();

		/*cout << "scheme vector " << endl;
		cout << " schemel size " << schemel.size() << endl;
		for (int i = 0; i < schemel.size(); i++)
		{
			cout << schemel[i].toString() << endl;
		}
		*/
		//cout << endl;
		//	schemeList();
		match("FACTS");
		match("COLON");

		factl = facts();
		/*cout << "fact vector " << endl;
		cout << "factlist size " << factl.size() << endl;
 		for (int i = 0; i < factl.size(); i++)
		{
			cout << factl[i].toString() << endl;
		}*/
		//cout << endl;

		match("RULES");
		match("COLON");
		rulel = rules();
		 
		match("QUERIES");
		match("COLON");
		//queries();
		queryl = queries();
		/*cout << "queries vector " << endl;
		cout << " queries size " << queryl.size() << endl;
		for (int i = 0; i < queryl.size(); i++)
		{
			cout << queryl[i].toString() << endl;
		}
		*/
		//cout << endl;

		match("EOF");
		
		vector<string> domain;
		domain = getstring();

		string file_name;
	// 	ofstream out(name);
		//cout << "Success!" << endl;
		//cout << "Schemes(" << schemel.size() << "):" << endl;
		int h = schemel.size();
		for (int i = 0; i < h; i++)
		{
			//cout << "  " << schemel[i].toString() << endl;
		}
		//cout << "Facts(" << factl.size() << "):" << endl; 
		for (int i = 0; i < factl.size(); i++)
		{
			//cout << "  " << factl[i].toString() << endl;
		}
		//cout << "Rules(" << rulel.size() << "):" << endl;
		for (int i = 0; i < rulel.size(); i++)
		{
		//	cout << "  " << rulel[i].toString() << endl;
		}
		//cout << "Queries(" << queryl.size() << "):" << endl;
		for (int i = 0; i < queryl.size(); i++)
		{
			//cout << "  " << queryl[i].toString() << endl;
		}
		// Domain also has queries as well. 
	//	cout << "Domain(" << domain.size() << "): " << endl; 
		for (int i = 0; i < domain.size(); i++)
		{
			//cout << "  " << domain[i] << endl;
		}

		DLP dlp = DLP(rulel, factl, queryl, schemel); 
		return dlp;
		
	}
	catch (Token e)
	{
		//cout << "Failure!" << endl;
		//cout << "  " <<  e.toString() << endl;

	
		
	}
	DLP y;
	return y;
}


