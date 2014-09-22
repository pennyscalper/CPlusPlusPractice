#include <iostream>
#include <string>

using namespace std;

string CheckPangrams(const string str)
{
    string s = str;
    string result = "";
    int hist[26] = {};
    
    for (int i=0; i<str.length(); i++) {
        if (isalpha(s[i])) {
            s[i] = tolower(s[i]);
            hist[s[i]-'a']++;
        }
    }
    
    for (int i=0; i<26; i++) {
        if (!hist[i])
            result += (char) (i+'a');
    }
    return result;
}

int main()
{
    
    string s = "";
    
    cout<<"Enter a sentence to check: ";
    std::getline(cin, s);
    
    cout<<"Input: "<<s<<endl;
    
    string result = CheckPangrams(s);
    
    if ("" == result)
        cout<<"Input sentence is a pangrams"<<endl;
    else
        cout<<"Missing characters: "<<result<<endl;
    
    return 0;
}