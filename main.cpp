#include <iostream>
#include <string>

using namespace std;

std::string intToString(int);

int main() {
 
    int x = 12345;
    string convrt = intToString(x);
    
    std::cout << convrt << '\n';
   
    return 0;
}

string intToString(int x) {
    bool is_negative;
    if (x < 0) {
        x = -x, is_negative = true;
        } else {
            is_negative = false;
            }
    
     string s;
     while (x) {
        s.push_back('0' + x % 10);
         std::cout << '0' + x % 10 << '\n';
         x /= 10;
         }
     if (s.empty()) {
        return {"0"}; // x is 0.
        }
    
     if (is_negative) {
         s.push_back('-');
         }
    reverse(s.begin(), s.end());
     return s;
}