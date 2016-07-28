#include "Scheme3.h"
#include "Parameter3.h"

Scheme::Scheme() {
	string b;
	A = b;
	vector<string> ist;
	List = ist;
}

Scheme::Scheme(string a, vector<string> list) {
	A = a;
	List = list;
}
string Scheme::getid() {
	return A;
}
vector<string> Scheme::getList() {
	return List;
}