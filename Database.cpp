#include "Database.h"
#include "Relation3.h"
#include <map>
#include "Predicate3.h"
#include "Parameter3.h"
#include "DLP3.h"

Database::Database() {
	
}
void Database::intbase(DLP holder) {
	dlphold = holder;
}
void Database::work() {
/*	//evaluate schemes
	int z = dlphold.getSchemes().size();
	for (int i = 0; i < z; i++)
	{
		vector<Predicate> predlist;
		predlist = dlphold.getSchemes();
	
		for (int k = 0; k < predlist.size(); k++)
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

			for (int l = 0; l < holder.size(); l++)
			{
				cout << holder[l] << endl;
			}
		}



		vector<Parameter> pramlist;
		vector<string> AB;
	//pramlist = .getPlist();
//	for (int j = 0; j < pramlist.size(); j++)
	//{
		//cout << pramlist[j].getParameter().getvalue() << endl;
	//}
	}
	*/
}
/*


classes
database 
map form strings to relations
sk is string to relation object


relation
 - namee sk string
  - shceme (A,B) vector of strings
  - set<tuples> of vector of strings

  $ funcitons $
  - select
      compares (first under query evaluation)
		it lookes at your set and it looks at which tuple has a c in the second via location of the vector. 
		it collects any tuple that fits the requirements

  -project
	after you    grabbed te tuples you need and it grabs the columbs that are variable columbs.
	grab the A in (A,c)
  - rename
     rename will basicall change the name of the schema
		you just chagne the place of the scheme to the query.
		look under query evaluation under rrename. 
scheme


tuple
inherit a vector of strings via buplic vector






*/


/*caalss 7/14
use set for places, it is faster

select : select(position of value, val) example: position = vector[1], val = 'c'
two different select operations
select:
for SK(X,X)
pull out the tuples that have repeated values

poroject: project(vector<int>)
SK(A,B) = project(vector{0,1})
SK(a) = project(vector{0})

rename: Rename(scheme object)
rename scheme


should all reutnr a new protect


*/