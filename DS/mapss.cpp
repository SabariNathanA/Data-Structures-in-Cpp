#include <map>
#include <utility>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	map< string, int > mymap;
	mymap["sab"]=17;//indexing can insert if not present
	cout<<(mymap.find("sab"))->second;//find returns iterator
	cout<<endl;
	mymap["sab"]=100;//if present, changes the value
	cout<<(mymap.find("sab"))->second<<endl;//find returns an iterator
	map<string,int>::iterator it = mymap.find("nat");//non member returns, OFFTHEEND iterator
	if(it==mymap.end()){
		cout<<"sorry, key doesnot exist"<<endl;
	}
	
	pair<map<string,int>::iterator , bool> ret= mymap.insert(map<string, int>::value_type("sab",200));
	if(!ret.second)//if this is  not set, value remains 100
	{
		(ret.first)->second = 200;
	}
	cout<<(mymap.find("sab"))->second<<endl;// check the syntax here.
	
	//enquiring map
	cout<<mymap.count("nat")<<endl;//doesnot find nat, so returns 0
	cout<<mymap["nat"]<<endl;//doesnot find nat, so inserts nat and sets value to 0
	cout<<mymap.count("nat")<<endl;//finds nat, so returns its number of occurences
	
	
	return 0;
}
