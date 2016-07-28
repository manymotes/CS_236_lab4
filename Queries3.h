#pragma once
#include <iostream>
#include "Parameter3.h"
#include "Predicate3.h"
#include "Token3.h"
#include <vector>

class Query {
public:
	Query(vector<Predicate> qlist);



private:
	Token ID;
};