#include "Scanner3.h"
#include <fstream>
#include <vector>
#include "Token3.h"
#include <sstream>
#include <stdio.h>
#include <ctype.h>
using namespace std;
Scanner::Scanner() {
	number_of_lines = 1;
	counter = 0;
}
vector<Token> Scanner::scan(string file_name) {
	try {
		char ch = NULL;

		ifstream File(file_name);


		while (!File.eof())
		{

			File.get(ch);
			if (File.eof())
			{

				throw 5;
			}

			if (!tester(ch))
			{

				throw 20;
			}
			if (ch == '\n') {

			}
			pound(ch, File);

			white(ch, File);

			nonalpha1(ch, File);

			nonalpha2(ch, File);

			alphaScheme(ch, File);
			if (File.peek() == EOF)
			{
				//	cout << "WHAT?! " << endl;
				collector.push_back(Token(number_of_lines, "EOF", ""));
				counter += 1;
			}
		}


		File.close();
		//Export2(file_name2);
	}
	catch (int e)
	{
		if (e == 5)
		{
			collector.push_back(Token(number_of_lines, "EOF", ""));
			counter += 1;
		//	Export2(file_name2);
		}

		else {
			//Export1(file_name2);
		}

	}
	return collector;
}
bool Scanner::nonalpha2(char ch, ifstream &File)
{
	if (ch == ':')
	{
		//string converter;
		string converter2;
		char temp = File.peek();
		if (temp == '-')
		{
			//cout << "COLON DAHS :-" << endl;
			char ch2;
			File.get(ch2);
			stringstream ss;
			ss << ch;
			ss >> converter;
			stringstream mm;
			mm << ch2;
			mm >> converter2;

			collector.push_back(Token(number_of_lines, "COLON_DASH", (converter + converter2)));
			counter += 1;
			return true;
		}
		else {

			stringstream ss;
			ss << ch;
			ss >> converter;
			collector.push_back(Token(number_of_lines, "COLON", converter));
			counter += 1;
			return true;

		}
		return true;
	}
	if (ch == '\'')
	{
		stringstream rr;
		do {
			rr << ch;
			File.get(ch);
		} while (ch != '\'' && ch != '\n');
		if (ch == '\n')
		{

			throw 20;


		}
		rr << ch;
		collector.push_back(Token(number_of_lines, "STRING", rr.str()));
		counter += 1;
		return true;
	}
	return false;
	//
}
bool Scanner::nonalpha1(char ch, ifstream & File)
{
	if (ch == ',')
	{
		stringstream ss;
		ss << ch;
		ss >> converter;
		collector.push_back(Token(number_of_lines, "COMMA", converter));
		counter += 1;
		return true;
	}
	if (ch == '.')
	{
		stringstream ss;
		ss << ch;
		ss >> converter;
		collector.push_back(Token(number_of_lines, "PERIOD", converter));
		counter += 1;
		return true;
	}
	if (ch == '?')
	{
		stringstream ss;
		ss << ch;
		ss >> converter;
		collector.push_back(Token(number_of_lines, "Q_MARK", converter));
		counter += 1;
		return true;
	}
	if (ch == '(')
	{

		stringstream ss;
		ss << ch;
		ss >> converter;
		collector.push_back(Token(number_of_lines, "LEFT_PAREN", converter));
		counter += 1;
		return true;

	}
	if (ch == ')')
	{
		stringstream ss;
		ss << ch;
		ss >> converter;
		collector.push_back(Token(number_of_lines, "RIGHT_PAREN", converter));
		counter += 1;
		return true;
	}
	return false;
}
string Scanner::alphaSchemehleper(char ch, ifstream &File)
{
	stringstream zz;
	if (isalpha(ch))
	{
		zz << ch;
		while (isalpha(File.peek()) || isdigit(File.peek()))
		{
			File.get(ch);
			zz << ch;

		}

	}

	return zz.str();
}
void Scanner::alphaScheme(char ch, ifstream &File)
{

	string holder;
	holder = alphaSchemehleper(ch, File);
	//holder = zz.str();


	if (holder == "Schemes")
	{
		collector.push_back(Token(number_of_lines, "SCHEMES", holder));
		counter += 1;
	}
	else if (holder == "Facts")
	{
		collector.push_back(Token(number_of_lines, "FACTS", holder));
		counter += 1;
	}
	else if (holder == "Rules")
	{
		collector.push_back(Token(number_of_lines, "RULES", holder));
		counter += 1;
	}
	else if (holder == "Queries")
	{
		collector.push_back(Token(number_of_lines, "QUERIES", holder));
		counter += 1;
	}
	else {
		if (holder != "") {

			collector.push_back(Token(number_of_lines, "ID", holder));
			counter += 1;
		}
	}


}
bool Scanner::white_help(char ch, ifstream &File)
{
	if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\v' || ch == '\f' || ch == '\r')
	{
		return true;
	}
	return false;
}
void Scanner::white(char ch, ifstream &File) {
	//cout << "got above blank space" << endl;

	if (white_help(ch, File))
	{

		//	cout << "got into blank space" << endl;
		if (File.peek() == EOF)
		{
			//	cout << "here " << endl;
			//	collector.push_back(Token(number_of_lines, "EOF", "\"\""));
		}
		if (ch == '\n') {
			//	cout << "Number ++ in secnd " << endl;
			number_of_lines += 1;
		}
		while (isspace(File.peek()))
		{
			File.get(ch);
			if (File.peek() == EOF)
			{
				//	cout << "here << end";
				//collector.push_back(Token(number_of_lines, "EOF", "\"\""));
			}
			if (ch == '\n') {
				number_of_lines += 1;
			}
		}
	}

}


void Scanner::ARY() {
	ary[0] = "COMMA";
	ary[1] = "PERIOD";
	ary[2] = "Q_MARK";
	ary[3] = "LEFT_PAREN";
	ary[4] = "RIGHT_PAREN";
	ary[5] = "COLO";
	ary[6] = "COLON_DASH";
	ary[7] = "SCHEMES";
	ary[8] = "FACTS";
	ary[9] = "RULES";
	ary[10] = "QUERIES";
	ary[11] = "ID";
	ary[11] = "STRING";
	ary[12] = "EOF";
}
int Scanner::liner()
{
	return number_of_lines;
}
int Scanner::Rcounter() {
	return counter;
}
bool Scanner::tester(char ch) {
	if (ch != '(' && ch != ':' && !isspace(ch) && ch != '\n' && ch != '\t') {
		stringstream ll;
		if (!testerb(ch)) {
			// PROBLEM
			throw 20;
			//Export1();
			//cout << "Input Error on Line: " << number_of_lines << endl;
			//cout << "CHAR: " << ch << endl;

			system("pause");
			exit(number_of_lines);
			return false;
		}
	}
	return true;
}
bool Scanner::testerb(char ch) {
	if (!isalpha(ch) && ch != '#' && ch != ',' && ch != '?' && ch != '.' && ch != ')' && ch != '\'') {
		return false;
	}
	return true;
}
void Scanner::pound(char ch, ifstream &File) {
	if (ch == '#')
	{
		while (ch != '\n')
		{
			File.get(ch);
		}
		if (ch == '\n')
		{
			number_of_lines += 1;
		}
	}
}
void Scanner::Export2(string file_name2) {
	ofstream out(file_name2);
	int cap = collector.size();
	for (int i = 0; i < cap; i++) {
		out << collector[i].toString() << endl;
		//	if (i != collector.size())
		//	{
		//		out << endl;
		//	}
	}

	out << "Total Tokens = " << Rcounter() << endl;
	out.close();
}

void Scanner::Export1(string file_name2)
{
	ofstream out(file_name2);
	int cap = collector.size();
	for (int i = 0; i < cap; i++) {
		out << collector[i].toString() << endl;;
		//	if (i != collector.size())
		//{
		//	out << endl;
		//}
	}
	out << "Input Error on line " << number_of_lines << endl;
	out.close();
}
