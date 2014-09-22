#include <iostream>
#include <vector>
#include <list> //doubly linked list <forward_list> are single link list
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream> 
#include <unordered_map> //use c++11 alias g++11='clang++ -std=c++11 -stdlib=libc++'..g++11 STL.cpp -o stl

#include <cstdlib>

using namespace std;

// a predicate implemented as a function:
bool is_negative (const int& value) { return (value<0); }
// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

//comparison functions for map
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
    bool operator() (const char& lhs, const char& rhs) const
    {return lhs<rhs;}
};

void vector_manip();
void list_manip();
void map_manip();
void set_manip();
void string_manip();
void readData();
//void c++11();

//typedef pair<string, int> value_type; //

int main()
{
    
    int i;
    if(0) {
        vector_manip();
        cout << "Done with Vectors*********...strating list manipulations" << endl;
    }
    
    if(0) {
        list_manip();
        cout << "Done with List*********...strating map manipulations" << endl;
    }
    if(0) {
        map_manip();
        cout << "Done with Maps*********...strating set manipulations" << endl;
    }
    
    if(0) {
        set_manip();
        cout << "Done with Sets*********...strating string manipulations" << endl;
    }
    
    if(0) {
        string_manip();
        cout << "Done with Strings*********...strating char & c functions manipulations" << endl;
    }
    
    
    if(1) {
        readData();
        cout << "Done with read data*********...strating char manipulations" << endl;
    }
    // do bit of char manipulations
    
    
    return 0;
}

void readData() {
    string path("/Users/praveen/Desktop/c++/dataSets");
    cout << "************************************************Reading integer array" << endl;
    std::fstream fs((path + "/intArr.txt").c_str(), std::fstream::in | std::fstream::out);
    vector<int> vi;
    int i, itmp;
    while(fs >> itmp)
        vi.push_back(itmp);
    
    
    for(i = 0; i < vi.size(); i++)
        cout << i << "=> " << vi[i] << endl;
    fs.close();
    cout << "************************************************Reading char array" << endl;
    vector<char> vc;
    char ctmp;
    fs.open((path + "/charArr.txt").c_str(), std::fstream::in | std::fstream::out);
    while(fs >> ctmp)
        vc.push_back(ctmp);
    
    for(i = 0; i < vc.size(); i++)
        cout << i << "=> " << vc[i] << endl;
    fs.close();
    cout << "************************************************Reading words array" << endl;
    
    vector<string> vstr;
    string strtmp;
    fs.open((path + "/strings.txt").c_str(), std::fstream::in | std::fstream::out);
    while(fs >> strtmp)
        vstr.push_back(strtmp);
    
    for(i = 0; i < vstr.size(); i++)
        cout << i << "=> " << vstr[i] << endl;
    fs.close();
    
    cout << "************************************************Reading integer and words into long and string vectors resp" << endl;
    fs.open((path + "/stringsIntArr.txt").c_str(), std::fstream::in | std::fstream::out);
    vstr.clear();
    vi.clear();
    while(fs >> strtmp) {
        if(isdigit(strtmp[strtmp.size() -1]))
            vi.push_back(atoi(strtmp.c_str()));
        else
            vstr.push_back(strtmp);
    }
        
    for(i = 0; i < vstr.size(); i++)
        cout << i << "=> " << vstr[i] << endl;
    for(i = 0; i < vi.size(); i++)
        cout << i << "=> " << vi[i] << endl;
    fs.close();
    
    
    cout << "************************************************Reading integer key map" << endl;
    map<int, vector<int> > intMap;
    fs.open((path + "/IntKeyMap.txt").c_str(), std::fstream::in | std::fstream::out);
    while(getline(fs, strtmp)) {
        istringstream iss(strtmp);
        int key;
        iss >> key;
        vi.clear();
        while(iss >> i)
            vi.push_back(i);
        //make pair and insert
        intMap.insert(std::pair<int, vector<int> >(key, vi));
    }
    
    map<int, vector<int> >::iterator imap;
    for(imap = intMap.begin(); imap != intMap.end(); imap++) {
        cout << "map print:" << imap->first << "=> ";// << intMap->second << endl;
        vi.clear();
        vi = imap->second;
        for(i = 0; i < vi.size(); i++)
            cout << vi[i] << " ";
        cout << endl;
    }
    fs.close();
    
    cout << "************************************************Reading string key map" << endl;
    unordered_map<string, vector<int> > strMap;
    fs.open((path + "/StringKeyMap.txt").c_str(), std::fstream::in | std::fstream::out);
    while(getline(fs, strtmp)) {
        istringstream iss(strtmp);
        iss >> strtmp;
        vi.clear();
        while(iss >> i)
            vi.push_back(i);
        //make pair and insert
        strMap.insert(std::pair<string, vector<int> >(strtmp, vi));
    }
    
    unordered_map<string, vector<int> >::iterator smap;
    for(smap = strMap.begin(); smap != strMap.end(); smap++) {
        cout << "map print:" << smap->first << "=> ";// << intMap->second << endl;
        vi.clear();
        vi = smap->second;
        for(i = 0; i < vi.size(); i++)
            cout << vi[i] << " ";
        cout << endl;
    }
    
    
}


void string_manip() {
    
    int i;
    std::string s0 ("Initial string");
    
    // constructors used in the same order as described above:
    std::string s1;
    std::string s2 (s0);
    std::string s3 (s0, 8, 3);
    std::string s4 ("A character sequence", 6);
    std::string s5 ("Another character sequence");
    std::string s6 (10, 'x');
    std::string s7a (10, 42);      // 42 is the ASCII code for '*'
    std::string s7b (s0.begin(), s0.begin()+7);
    
    std::cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
    std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6: " << s6;
    std::cout << "\ns7a: " << s7a << "\ns7b: " << s7b << '\n';
    
    s1.append(s0);
    cout << "There are around as many append/insert/replace overloaded functions as various constructors" << endl;
    cout << "getting substring:" << s0.substr(0, 7) << endl;
    cout << "finding position of 'str':" << s0.find("str") << endl;
    
    string::iterator is;
    for (i=0, is = s0.begin(); i< s0.length(); ++i, is++)
        cout <<"s0 size&capacity: "<< s0.size() << "&" << s0.capacity() << s0.at(i) << " " << s0[i] << " " << *is << endl;
    s0 = s0 + " appended";
    for (i=0, is = s0.begin(); i< s0.length(); ++i, is++)
        cout <<"s0 size&capacity: "<< s0.size() << "&" << s0.capacity() << s0.at(i) << " " << s0[i] << " " << *is << endl;
    
    
}

void set_manip() {
    
    cout << "exactly like map except that the data type is just 'key'...all functions are similar" << endl;
}

void map_manip() {
    int i;
    std::map<char,int> m1;
    map<char, int>::iterator im;
    
    m1['a']=10; m1['b']=30; m1['c']=50; m1['d']=70;
    
    im = m1.begin(); ++im; ++im;
    std::map<char,int> m2 (m1.begin(), im);
    
    std::map<char,int,classcomp> m3;// = {{ 'a', 1 }, { 'b', 2 }, { 'c', 3 } };                 // using class compare
    
    bool(*fn_pt)(char,char) = fncomp;
    std::map<char,int,bool(*)(char,char)> m4 (fn_pt); // function pointer as Compare
    
    
    for(im = m1.begin(), i = 0; im != m1.end(); im++, i++)
        cout << "m1: size" << m1.size() << " " << i << " " << im->first << ":" << im->second << endl;
    for(im = m2.begin(), i = 0; im != m2.end(); im++, i++)
        cout << "m2: size" << m2.size() << " " << i << " " << im->first << ":" << im->second << endl;
    
    cout << "inserting x,y pairs in m2, removing a, b & adding c&d using iteratos" << endl;
    m2.insert ( std::pair<char,int>('y',250) );
    m2.insert ( std::pair<char,int>('z',260) );
    m2.erase(m2.find('a'));
    im=m2.find('b'); //find returns the iterator
    m2.erase(im);
    m2.insert(m1.find('c'), m1.end());
    
    for(im = m2.begin(), i = 0; im != m2.end(); im++, i++)
        cout << "m2: size" << m2.size() << " " << i << " " << im->first << ":" << im->second << endl;
    
    cout << "clearing the map" << endl;
    m1.clear();
    cout << "m1 is empty? " << m1.empty() << endl;
    

    
}


void list_manip() {
    int i;
    std::list<int> l1;                       // four ints with value 100
    for(i =0; i < 5; i++)
        l1.push_back(i);
    int arr[5] = {10,9,8,7,6};
    std::list<int> l2(arr, arr + 5);
    
    list<int>::iterator il;
    for(il = l1.begin(), i = 0; il != l1.end(); il++, i++)
        cout << "l1: size" << l1.size() << " " << i << " " << *il << endl;
    for(il = l2.begin(), i = 0; il != l2.end(); il++, i++)
        cout << "l2: size" << l2.size() << " " << i << " " << *il << endl;
    cout << "l1 is empty? " << l1.empty() << " So erasing last elements, resizing up by 2, sorting, reversing twice" << endl;
    il = l1.end();
    l1.erase(--il);
    l1.resize(l1.size() + 2, -1); //resize the vector...there is no sort in vector
    l1.sort();
    l1.reverse();l1.reverse();
    
    for(il = l1.begin(), i = 0; il != l1.end(); il++, i++)
        cout << "l1: size" << l1.size() << " " << i << " " << *il << endl;
    cout << "removing negative then, clearing the list" << endl;
    l1.remove_if (is_negative);
    for(il = l1.begin(), i = 0; il != l1.end(); il++, i++)
        cout << "l1: size" << l1.size() << " " << i << " " << *il << endl;
    
    //l1.splice();
    l1.clear();
    cout << "l1 is empty? " << l1.empty() << endl;
    
    //l1.unique();//removed duplicate when list is sorted; can remove based on some other criteria as well based on (i-1) & ith element
    double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
        12.77, 73.35, 72.25, 15.3,  72.25 };
    std::list<double> mylist (mydoubles,mydoubles+10);
    list<double> l3 = mylist;
    list<double>::iterator ild;
    for(ild = l3.begin(), i = 0; ild != l3.end(); ild++, i++)
        cout << "new l1: size" << l3.size() << " " << i << " " << *ild << endl;
    
    l3.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
    // 15.3,  72.25, 72.25, 73.0,  73.35
    for(ild = l3.begin(), i = 0; ild != l3.end(); ild++, i++)
        cout << "sort l1: size" << l3.size() << " " << i << " " << *ild << endl;
    
    l3.unique();           //  2.72,  3.14, 12.15, 12.77
    // 15.3,  72.25, 73.0,  73.35
    for(ild = l3.begin(), i = 0; ild != l3.end(); ild++, i++)
        cout << "unique l1: size" << l3.size() << " " << i << " " << *ild << endl;
    
    l3.unique (same_integral_part);  //  2.72,  3.14, 12.15
    // 15.3,  72.25, 73.0
    for(ild = l3.begin(), i = 0; ild != l3.end(); ild++, i++)
        cout << "unique integral l1: size" << l3.size() << " " << i << " " << *ild << endl;

}

void vector_manip() {
    vector<int> v1 (4,10); //10 ints with value 100
    vector<int> v2(v1.begin(), v1.end() - 2);
    //vector<*int> vp1[4];
    //vector<*int>::iterator ivp1 = vp1.begin();
    vector<int>::iterator iv1;
    int i;
    for(i=0; i < v1.size(); i++)
        cout << "v1: capacity" << v1.capacity() << " " << i << " " << v1[i] << endl;
    for(iv1 = v2.begin(), i = 0; iv1 != v2.end(); iv1++, i++)
        cout << "v2: " << i << " " << *iv1 << endl;
    cout << "pushing into v1" << endl;
    for(i = 0;i < 3; i++)
        v1.push_back(i);
    for(i=0; i < v1.size(); i++)
        cout << "v1: capacity" << v1.capacity() << " " << "v1: size" << v1.size() << " "<< i << " " << v1[i] << endl;
    cout << "v1 is empty? " << v1.empty() << " So erasing last elements and then resizing up by 2" << endl;
    v1.erase(v1.end() - 1);
    v1.resize(v1.size() + 2); //resize the vector...there is no sort in vector
    
    for(i=0; i < v1.size(); i++)
        cout << "v1: capacity" << v1.capacity() << " " << "v1: size" << v1.size() << " "<< i << " " << v1[i] << endl;
    
}