#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void permute(string &str, int first, int last);

int main(int argc, char* argv[]) {
 
	if(argc <= 1) {
		cout << "need to pass string" << endl;
		return 0;
	}
	
    string str(argv[1]);
  
	std::cout << "string to permute: " << str << "; starting permutation" << endl;

	permute(str, 0, str.size() - 1);
	
	sort(str.begin(), str.end());
	std::cout << "permuting using C++ inbuilt function" << endl;
	do {
		cout << str << endl; 	
	} while(next_permutation(str.begin(),str.end()));
	return 0;
}

void permute(string &str, int first, int last) {
	if(first > last) {
		cout << str << endl;
		return;
	}
	int i;
	map<char, int> allchar;

	for(i = first; i <= last; i++) {
		if(allchar.find(str[i]) != allchar.end()) //if found then dont permute
			continue;
		allchar.insert(std::pair<char,int>(str[i],1));

		swap(str[i], str[first]);
		permute(str, first + 1, str.size() - 1);
		swap(str[i], str[first]);
	}

}
