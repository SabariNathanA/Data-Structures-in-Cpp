#include <stack>
#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::stack<std::string> sstr;
	while(std::cin>>s)
	{
		sstr.push(s);
	}
	while(!sstr.empty())
	{
		std::cout<<sstr.top()<<std::endl;
		sstr.pop();
	}
}	

//top returns not removes
//pop removes doesnot return
