#pragma once

#include <iostream>
#include <vector>
#include "Token3.h"
using namespace std;
class Parameter {

public:
	Parameter();
	Parameter(Token tk);
	Token getParameter();
	string toString();
	
	// just store the toke
private:
	Token stored;

};