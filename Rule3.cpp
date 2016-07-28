#include "Rule3.h"
#include <sstream>

Rule::Rule(Predicate ID, Token col_dash, vector<Predicate> list)
{
	id = ID;
	Col_dash = col_dash;
	List = list;
}
string Rule::toString() {
	stringstream zz;
	zz << id.toString() << " " << Col_dash.getvalue() << " ";
	for (int i = 0; i < List.size(); i++)
	{
		
		zz << List[i].toString();
		if (i < List.size()-1)
		{
			zz << ",";
		}
	}
	return zz.str();
}