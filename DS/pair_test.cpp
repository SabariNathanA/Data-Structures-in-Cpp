#include <utility>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool comparee(pair<string,int> a, pair<string,int> b){
	return a.second < b.second;
}
int main(){
	string s;int i;
	pair<string,int> myp;
	vector<pair<string,int> > vectpairs;
	while(cin>>s){
		cin>>i;
		myp = make_pair(s,i);
		vectpairs.push_back(myp);
	}
	vector< pair <string,int> >::const_iterator iter= vectpairs.begin();
	while (iter < vectpairs.end()){
		cout<<(iter->first)<<endl;
		iter++;
	}
	sort(vectpairs.begin(),vectpairs.end());
	for(unsigned int j=0;j< vectpairs.size();j++)
		cout<<vectpairs[j].first<<endl;
		
	sort(vectpairs.begin(),vectpairs.end(),comparee);
	for(unsigned int jj=0;jj< vectpairs.size();jj++)
		cout<<vectpairs[jj].first<<endl;
	return 0;
}
