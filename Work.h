#pragma once
#include "DLP3.h"
#include "Scheme3.h"
#include "Relation3.h"
#include <map>
class Work {
public:
	void importDLP(DLP temp);
	void doWork(ofstream &out);
	// this shoudl be in the database calss
	vector<Scheme> schemeVector;
	vector<Relation> relationvector;
	void further_work(ofstream &out);
	void printfacts(ofstream &out);
	vector<Parameter> FW_print_parmUp(string preID, vector<Parameter> tempy, ofstream &out);
	void print_select(Relation tempRelation, ofstream &out);
	void factEval(ofstream &out);
	Relation project_print(Relation tempRelation, vector<Parameter> temp, ofstream &out);
	Relation rename_Help(Relation tempRelation, vector<Parameter> temp, vector<Parameter> querylayout, ofstream &out);
	void update_further_work(vector<string> mtwo, vector<string> mone, map<string, vector<int>> mapone, map<string, vector<int>> maptwo, Relation &tempRelation);
	vector<int> returnspotsToPull(map<string, vector<int>> schemeFilter, vector<string> Keys, vector<Parameter> temp);
	vector<int> rename_help_condeser(vector<Parameter> querylayout);
private:
	DLP dlphold;

};
