
#pragma once
#include <iostream>
#include <vector>
#include "Token3.h"
using namespace std;
class Scanner
{
private:
	string ary[13];
	int counter;
public:
	Scanner();
	vector<Token> collector;
	int number_of_lines;

	string converter;

	void Export1(string file_name);
	void Export2(string file_name);
	vector<Token> scan(std::string file_name);
	bool nonalpha1(char ch, ifstream &File);
	bool nonalpha2(char ch, ifstream &File);
	bool testerb(char ch);
	string alphaSchemehleper(char ch, ifstream &File);
	bool white_help(char ch, ifstream &File);
	void alphaScheme(char ch, ifstream &File);
	void white(char ch, ifstream &File);
	int liner();
	void ARY();
	int Rcounter();
	bool tester(char ch);
	void pound(char ch, ifstream &File);


};
