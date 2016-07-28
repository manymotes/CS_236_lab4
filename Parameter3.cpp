#include "Parameter3.h"

Parameter::Parameter() {
	stored = Token(-1, "", "");
}
Parameter::Parameter(Token tk){
	stored = tk;
}
string Parameter::toString() {
	//cout << "in parameter tostring : " << stored.getvalue() << endl;
	return stored.getvalue();
}
Token Parameter::getParameter() {
	return stored;
}