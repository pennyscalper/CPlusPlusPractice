#include <iostream>
#include <cctype>
#include <cmath>

using namespace std;

int main()
{
    
    //cctype
    int i;
    char str[]="c3poc?";
    i=0;
    while (isalnum(str[i])) {
        cout << i << " " << isalnum(str[i]) << " " << str[i] << " " << toupper(str[i]) << " " << (char)toupper(str[i]) << " " << (int)toupper(str[i]) << endl;
        i++;
    }
    cout << i << "done with the cctype***************" << endl;
    //cmath
    
    
    return 0;
}