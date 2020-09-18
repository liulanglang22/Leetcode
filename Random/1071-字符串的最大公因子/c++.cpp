#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)
            return "";
        return str1.substr(0,gcd((int)str1.length(), (int)str2.length()));
    }
    int gcd(int a, int b) {
        return !b?a:gcd(b, a%b);
    }
};