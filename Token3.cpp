#include "Token3.h"
#include <sstream>
Token::Token() {
	line = -1;
	value = "";
	type = "";
}
Token::Token(int line, std::string type, std::string value) {
	this->line = line;
	this->type = type;
	this->value = value;
}
int Token::getline() {
	return line;
}
std::string Token::getvalue() {
	return value;
}
std::string Token::gettype() {
	/*std::string ary[14];
	ary[0] = ",";
	ary[1] = ".";
	ary[2] = "?";
	ary[3] = "(";
	ary[4] = ")";
	ary[5] = ":";
	ary[6] = ":-";
	ary[7] = "Schemes";
	ary[8] = "Facts";
	ary[9] = "Rules";
	ary[10] = "Queries";
	ary[11] = "ID";
	ary[12] = "String";
	ary[13] = "EOF";
	*/
	return type;
}
std::string Token::toString() {
	std::stringstream ss;
	ss << "(" << type << ",\"" << value << "\"," << line << ")";
	return ss.str();
}
