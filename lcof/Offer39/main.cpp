#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        map<int, int> hashMap;
        for (int i : nums) {
            hashMap[i] += 1;
            if (hashMap[i] > (nums.size() / 2)) {
                return hashMap[i];
            }
        }
        return 0;
    }
    
};
int main() {
    vector<int> m = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    Solution::majorityElement(m);
}