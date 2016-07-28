#include "DLP3.h"

DLP::DLP(vector<Rule> rulel, vector<Predicate> factl, vector<Predicate> queryl, vector<Predicate> schemel) {
	Rulel = rulel;
	Factl = factl;
	Queryl = queryl;
	Schemel = schemel;
}
DLP::DLP() {

}
vector<Predicate> DLP::getFacts() {
	return Factl;
}
vector<Rule> DLP::getRules() {
	return Rulel;
}
vector<Predicate> DLP::getQueries() {
	return Queryl;
}
vector<Predicate> DLP::getSchemes() {
	return Schemel;
}