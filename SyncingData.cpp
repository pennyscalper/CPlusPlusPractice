#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

//vector of list would be much much better
void SyncData(vector<vector<int> > &serverData, int first, int last); //contains logic
void CopyData(vector<vector<int> > &serverData, int first1, int last1, int first2, int last2); //merges data between two servers

int main() {
	
	string strtmp;
    vector<vector<int> > intMap;
	vector<int> vi;
	int i, j;
	vector<vector<int> >::iterator imap;

	fstream fs("./dataSets/IntKeyMap.txt", std::fstream::in | std::fstream::out);
    cout << "************************************************Reading integer key map" << endl;
	while(getline(fs, strtmp)) {
		istringstream iss(strtmp);
		
		int key;        
        iss >> key;        
		while(iss >> i) 
			vi.push_back(i);
        intMap.push_back(vi);
		vi.clear();
    }
    
    for(imap = intMap.begin(), i = 0; imap != intMap.end(); imap++, i++) {
		vector<int> tmp = *imap;
        cout << "map print:" << i << "=> ";// << intMap->second << endl;
        for(j = 0; j < tmp.size(); j++)
            cout << tmp[j] << " ";
        cout << endl;
    }
    fs.close();
 
	SyncData(intMap, 0, intMap.size() - 1);
	cout << "************************************************Sorted data" << endl;
    for(imap = intMap.begin(), i = 0; imap != intMap.end(); imap++, i++) {
		vector<int> tmp = *imap;
        cout << "map print:" << i << "=> ";// << intMap->second << endl;
        for(j = 0; j < tmp.size(); j++)
            cout << tmp[j] << " ";
        cout << endl;
	}
}

void SyncData(vector<vector<int> > &serverData, int first, int last) {
	//partition the server data into 
	if(first == last)	
		return;

	int mid = floor((first + last)/2);

	SyncData(serverData, first, mid);
	SyncData(serverData, mid + 1, last);

	CopyData(serverData, first, mid, mid + 1, last);
}


void CopyData(vector<vector<int> > &serverData, int first1, int last1, int first2, int last2) {
	set<int> dat(serverData[first1].begin(), serverData[first1].end());
	dat.insert(serverData[first2].begin(), serverData[first2].end());
	int i;
	for(i = first1; i <= last1; i++) {
		serverData[i].clear();
		serverData[i].insert(serverData[i].begin(), dat.begin(), dat.end());
	}
	for(i = first2; i <= last2; i++) {
		serverData[i].clear();
		serverData[i].insert(serverData[i].begin(), dat.begin(), dat.end());
	}
}