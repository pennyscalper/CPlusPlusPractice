#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>
#include <map>

using namespace std;

void myfunction (int i) {  // function:
  std::cout << '-' << i;
}
struct myclass {           // function object type:
  void operator() (int i) {std::cout << '-' << 2*i;}
} myobject;

bool IsOdd (int i) {
  return ((i%2)==1);
}

int main() {
 
	int i;
	std::vector<int> myvector;	for(i = 1; i < 11; i++) myvector.push_back(i);
	std::list<int> mylist;	for(i = 1; i < 11; i++) mylist.push_back(i);
	vector<int>::iterator itv;
	list<int>::iterator itl;

	//applies the function myfunction(or function object) to each element between the iterator range provided
    for_each (myvector.begin(), myvector.end(), myfunction); cout << " <= vector" << endl;
	for_each (mylist.begin(), mylist.end(), myobject); cout << " <= list" << endl;

	itv = find(myvector.begin(), myvector.end(), 5); 
	if(itv != myvector.end())
		cout << "found the value: " << *itv << endl;
	itl = find(mylist.begin(), mylist.end(), 5); 
	if(itl != mylist.end())
		cout << "found the value: " << *itl << endl;
	//find if using a function as criteria
	itl = find_if(mylist.begin(), mylist.end(), IsOdd); 
	if(itl != mylist.end())
		cout << "first odd value: " << *itl << endl;

    return 0;
}
