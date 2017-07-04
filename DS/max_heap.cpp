#include <iostream>
#include <queue>
using namespace std;

class human
{
	public:
	unsigned int age;
	string name;
};
class MYINE{
	public:
	bool operator()(human a, human b)
	{
		return a.age < b.age;//sorts in descending order of age. Meaning value with least true is on top
	}
}; 
/*
 * option 1
 * struct MYINE{
 * bool operator()(human a, human b)
	{
		return a.age < b.age;//sorts in descending order of age. Meaning value with least true is on top
	}
	}; 
 */
/*
 * option 2
 * bool operator<(human a, human b)
 * {
 * 	return a.age < b.age;
 * }
 */
 /*
  * option 3
  * struct human{
  * int age;
  * }
  * bool operator<(human &a, human &b){
  * return a.age<b.age;
  * }	
  * 
  * priority_queue<human>
  */


int main()
{
	human temp;
	temp.age = 45;
	temp.name = "sas";
	priority_queue<human,vector<human>, MYINE> max_heap;
	max_heap.push(temp);
	temp.age = 65;
	max_heap.push(temp);
	//temp=NULL;
	//temp = new human;
	temp.age = 25;
	max_heap.push(temp);
	//temp=NULL;
	//temp = new human;
	temp.age = 55;
	max_heap.push(temp);
	//temp=NULL;
	//temp = new human;
	temp.age = 425;
	max_heap.push(temp); 
	while (!max_heap.empty())
	{
		cout<<(max_heap.top()).age<<endl;
		max_heap.pop();
	}
	return 0;
}
