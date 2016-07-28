#include "Work.h"
#include "Relation3.h"
#include "Predicate3.h"
#include "Database.h"
#include <fstream>

Database databasepoint;
void Work::importDLP(DLP temp) {
	dlphold = temp;
}
void Work::doWork(ofstream &out) {
	/*
	-----------------------------------------
	evaluate schemes
	-----------------------------------------
	*/
	
	out << "Scheme Evaluation" << endl << endl;
		int z = dlphold.getSchemes().size();
		vector<Predicate> predlist;
		predlist = dlphold.getSchemes();
		for (int i = 0; i < z; i++)
		{
			
			int pl = predlist.size();
			for (int k = 0; k < pl; k++)
			{
				vector<Parameter> temp = predlist[i].getPlist();
				vector<string> holder;

				for (int l = 0; l < temp.size(); l++)
				{
					if (temp[l].getParameter().getvalue() != ",")
					{

						holder.push_back(temp[l].getParameter().getvalue());
					}
				}

				Scheme Sa = (Scheme(predlist[i].getID(), holder));

				/*-----------------------------
				build relations vectors with scheme list
				------------------------------------
				*/
				Relation a = Relation(predlist[i].getID(), Sa);
			
				databasepoint.mappy[predlist[i].getID()] = a;
				databasepoint.newIDset.insert(predlist[i].getID());
			}
		}
	
}

void Work::factEval(ofstream &out) {
	out << "Fact Evaluation" << endl << endl;
	vector<Predicate> factlist = dlphold.getFacts();
	
	//loop through the fact list
	for (int i = 0; i < factlist.size(); i++) {
		  
		vector<Parameter> temp = factlist[i].getPlist();
		vector<string> addVec;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j].getParameter().getvalue() != ",")
			{
				addVec.push_back(temp[j].getParameter().getvalue());
			}
		}
			databasepoint.mappy[factlist[i].getID()].addSvector(addVec);
			//databasepoint.IDset.insert(factlist[i].getID());
	}
}
void Work::printfacts(ofstream &out) {
	set<string>::iterator it;
	for (it = databasepoint.newIDset.begin(); it != databasepoint.newIDset.end(); ++it)
	{
		string f = *it; // error here
		set<vector<string>> tuples = databasepoint.mappy[f].getSvector();
		vector<string> relscheme = databasepoint.mappy[f].getScheme().getList();

		out << databasepoint.mappy[f].getID() << endl;

		set<vector<string>>::iterator ir;
		for (ir = tuples.begin(); ir != tuples.end(); ++ir) {
			vector<string> tupletemp = *ir;
			for (int j = 0; j < tupletemp.size(); j++) {
				//for (int a = 0; a < relscheme.size(); a++) {
				if (j == 0)
				{
					out << "  ";
				}
				out << "" << relscheme[j] << "=" << tupletemp[j];
				if (j < tupletemp.size() - 1)
				{
					out << " ";
				}

			}
			out << endl;
		}
		out << endl;
	}
}


void Work::further_work(ofstream &out) {

	// update queries to update_queries set!!!
	vector<Predicate> predlist = dlphold.getQueries();

	out << "Query Evaluation" << endl << endl;


	for (int i = 0; i < predlist.size(); i++)
	{
		
		vector<Parameter> pram_up;
		vector<Parameter> temp = predlist[i].getPlist();

		pram_up = FW_print_parmUp(predlist[i].getID(), temp, out);
		

		/*cout pram_up*/
		
		
		//databasepoint.mappy[predlist[i].getID()];
		map<string, vector<int>> mapone;
		vector<string> mone;
		vector<string> mtwo;
		map<string, vector<int>> maptwo;

		
		for (int l = 0; l < pram_up.size(); l++) {
			if (pram_up[l].getParameter().gettype() == "ID") {
				{
				//	cout << "ID!!!! on  " << l << endl;
					mapone[pram_up[l].getParameter().getvalue()].push_back(l);
					mone.push_back(pram_up[l].getParameter().getvalue());
				}


			}
			else if (pram_up[l].getParameter().gettype() == "STRING")
			{
				//cout << "STRING!!!!  on  " << l << endl;
				maptwo[pram_up[l].getParameter().getvalue()].push_back(l);
				mtwo.push_back(pram_up[l].getParameter().getvalue());
			}
		}

		
		//use maps
		set<vector<string>> factholder = databasepoint.mappy[predlist[i].getID()].getSvector();
		Relation tempRelation = databasepoint.mappy[predlist[i].getID()];

		update_further_work(mtwo, mone, mapone, maptwo, tempRelation);

		
		
		/*---------------------
		print temp relation select portion
		-----------------------*/
		
		set<vector<string>> tuples = tempRelation.getSvector();
		if (tuples.size() <= 0) {
			out << "No" << endl << endl;
		}
		else {

			out << "Yes(" << tuples.size() << ")" << endl;

			out << "select" << endl;

			/*--------------
			print select
			----------------*/
			
			print_select(tempRelation, out);

			Relation newprojection;
			newprojection = project_print(tempRelation, pram_up, out);

			rename_Help(newprojection, temp, pram_up, out);


			// 	else bracket
		}
	}
	
}
vector<Parameter> Work::FW_print_parmUp(string preID, vector<Parameter> tempy, ofstream &out) {
	vector<Parameter> pram_up;
	out << preID << "(";
	for (int k = 0; k < tempy.size(); k++)
	{

		if (tempy[k].getParameter().getvalue() != ",") {
			pram_up.push_back(tempy[k]);
			out << tempy[k].toString();
		}
		else {
			out << ",";
		}

	}
	out << ")? ";
	return pram_up;
}
void Work::print_select(Relation tempRelation, ofstream &out) {
	set<vector<string>> tuples = tempRelation.getSvector();

	set<vector<string>>::iterator ir;
	vector<string> relscheme = tempRelation.getScheme().getList();
	for (ir = tuples.begin(); ir != tuples.end(); ++ir) {
		vector<string> tupletemp = *ir;
		for (int j = 0; j < tupletemp.size(); j++) {
			//for (int a = 0; a < relscheme.size(); a++) {
			if (j == 0)
			{
				out << "  ";
			}
			out << "" << relscheme[j] << "=" << tupletemp[j];
			if (j < tupletemp.size() - 1)
			{
				out << " ";
			}

		}
		out << endl;
	}

}

Relation Work::project_print(Relation tempRelation, vector<Parameter> temp, ofstream &out) {

	map<string, vector<int>> schemeFilter;
	vector<string> Keys;


	vector<int> spotsToPull = returnspotsToPull(schemeFilter, Keys, temp);
		
	
	
	/*--- -
	print spots to pull
	------
	cout << "____________________" << endl;
	for (int r = 0; r < spotsToPull.size(); r++) {
		cout << spotsToPull[r] << endl;
	}
	cout << endl << "_________________ " << endl;
	*/
	Relation returnRel = tempRelation.project(spotsToPull);
	
	out << "project" << endl;
	set<vector<string>> tuplesSet = returnRel.getSvector();
	set<vector<string>>::iterator ir;
	for (ir = tuplesSet.begin(); ir != tuplesSet.end(); ++ir)
	{
		vector<string> temp_tuple = *ir;
		vector<string> tempSchemeList = returnRel.getScheme().getList();
		for (int q = 0; q < tempSchemeList.size(); q++)
		{
			if (q == 0)
			{
				out << "  ";
			}
			out << tempSchemeList[q] << "=" << temp_tuple[q];
			if (q < (tempSchemeList.size() - 1))
			{
				out << " ";
			}
			
		}
		if (tempSchemeList.size() != 0)
		{
			out << endl;
		}
	}



	return returnRel;


} 
Relation Work::rename_Help(Relation tempRelation, vector<Parameter> temp, vector<Parameter> querylayout, ofstream &out)
{
	Relation returner;
	//-------------
	vector<int> spotsToPull = rename_help_condeser(querylayout);
	//-----------
	
	
	//


	//
	vector<string> pulledString;
	querylayout;
	for (int p = 0; p < spotsToPull.size(); p++)
	{
		pulledString.push_back(querylayout[spotsToPull[p]].getParameter().getvalue());
	}

	returner = tempRelation.rename(pulledString);

	out << "rename" << endl;
	set<vector<string>> tuplesSet = tempRelation.getSvector();
	set<vector<string>>::iterator ir;
	for (ir = tuplesSet.begin(); ir != tuplesSet.end(); ++ir)
	{
		vector<string> temp_tuple = *ir;
		vector<string> tempSchemeList;
		for (int q = 0; q < pulledString.size(); q++)
		{
			if (q == 0)
			{
				out << "  ";
			}
			out << pulledString[q];
			out << "=" << temp_tuple[q];
			if (q < (pulledString.size() - 1))
			{
				out << " ";
			}

		}
		if (pulledString.size() != 0)
		{
			out << endl;
		}
	}
	out << endl;

	// goal
	
	return returner;
}
void Work::update_further_work(vector<string> mtwo, vector<string> mone, map<string, vector<int>> mapone, map<string, vector<int>> maptwo, Relation &tempRelation)
{
	
	for (int p = 0; p < mtwo.size(); p++) {
		vector<int> positionInts = maptwo[mtwo[p]];
		for (int y = 0; y < positionInts.size(); y++)
		{

			tempRelation = tempRelation.select(mtwo[p], positionInts[y]);


		}


	}
	for (int g = 0; g < mone.size(); g++) {
		if (mapone[mone[g]].size() > 1)
		{
			for (int h = 0; h < mapone[mone[g]].size() - 1; h++)
			{
				vector<int> selectInts = mapone[mone[g]];
				tempRelation = tempRelation.selectTwo(selectInts[h], selectInts[h + 1]);
			}
		}

	}
}
vector<int> Work::returnspotsToPull(map<string, vector<int>> schemeFilter, vector<string> Keys, vector<Parameter> temp) 
{
	vector<int> spotsToPull;
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i].getParameter().gettype() == "ID") {
			schemeFilter[temp[i].getParameter().getvalue()].push_back(i);
			if (std::find(Keys.begin(), Keys.end(), temp[i].getParameter().getvalue()) == Keys.end())
			{
				Keys.push_back(temp[i].getParameter().getvalue());
			}

		}
	}


	for (int w = 0; w < Keys.size(); w++)
	{
		vector<int> filterHelp = schemeFilter[Keys[w]];

		spotsToPull.push_back(filterHelp[0]);
	}
	return spotsToPull;
}
vector<int> Work::rename_help_condeser(vector<Parameter> querylayout) {
	map<string, vector<int>> schemeFilter;
	vector<string> Keys;
	vector<int> spotsToPull;
	for (int i = 0; i < querylayout.size(); i++)
	{
		if (querylayout[i].getParameter().gettype() == "ID") {
			schemeFilter[querylayout[i].getParameter().getvalue()].push_back(i);
			if (std::find(Keys.begin(), Keys.end(), querylayout[i].getParameter().getvalue()) == Keys.end())
			{
				Keys.push_back(querylayout[i].getParameter().getvalue());
			}

		}
	}


	for (int v = 0; v < Keys.size(); v++)
	{
		vector<int> filterHelp = schemeFilter[Keys[v]];

		spotsToPull.push_back(filterHelp[0]);
	}

	return spotsToPull;
}

// chagne the relations class to take an Id and a scheme;
//	if the  fact id == the relation id push the fact tuples into the relation. 
//	get all of the tuples from the facts
//	chagne 

//	put the tuples into the relation that match the set


/*For each fact in the Datalog program,
add a Tuple to a Relation.
Use the predicate name from the fact to determine the Relation to which the Tuple should be added.
Use the values listed in the fact to provide the values for the Tuple.
*/
//vector<Parameter> pramlist;
//vector<string> AB;
//pramlist = .getPlist();
//	for (int j = 0; j < pramlist.size(); j++)
//{
//cout << pramlist[j].getParameter().getvalue() << endl;
//}

// select pas in location in vector and value it is soppose to be
// 1, and c for sk (a,c)

/*other slecet takes two indexes

check if there is a duplicate A for the query sk(A,A)


more simply if first index token ins string or id


select takes rows

Project:it takes vertical columns
it only takes colems marked by and iD and not a string,
sk(a,'c')
project([0]) for A
create now relation for sk
new woul dbe like sk(A)
with :
a
b 
in the vector for the new relation

newame switches A to X. to relfect the variables in my query.

reslust of select yo call project
with result of project you call rename 


*/