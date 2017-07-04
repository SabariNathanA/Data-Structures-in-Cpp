#include <list>
#include <iostream>

bool comparee(std::string s1,std::string s2)
{
	return s1.size()<s2.size();
}
int main()
{
	std::list<std::string> liststr;
	liststr.push_back("a");
	liststr.push_front("xx");
	std::list<std::string>::iterator itfront = liststr.begin();
	liststr.insert(++itfront, "bbb");
	itfront = liststr.begin();
	while(itfront!=liststr.end())
	{
		std::cout<<*itfront<<std::endl;
		itfront++;
	}
	liststr.sort();
	itfront = liststr.begin();
	while(itfront!=liststr.end())
	{
		std::cout<<*itfront<<std::endl;
		itfront++;
	}
	liststr.sort(comparee);
	itfront = liststr.begin();
	while(itfront!=liststr.end())
	{
		std::cout<<*itfront<<std::endl;
		itfront++;
	}
	return 0;
}
