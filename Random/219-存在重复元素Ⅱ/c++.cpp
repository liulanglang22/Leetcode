#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // key: 数组元素， value：元素所在下表
        for (int i = 0; i < nums.size(); i++) {
            // 找到了在索引i之前就出现过nums[i]这个元素
            if (map.find(nums[i]) != map.end()) { 
                int distance = i - map[nums[i]];
                if (distance <= k) {
                    return true;
                }
                map[nums[i]] = i; // 更新元素nums[i]所在的最新位置i
            } else { // 如果map里面没有，就把插入一条数据<元素，元素所在的下表>
                map[nums[i]] = i;
            }
        }
        return false;
    }
};

// 作者：carlsun-2
// 链接：https://leetcode-cn.com/problems/contains-duplicate-ii/solution/219-cun-zai-zhong-fu-yuan-su-iiha-xi-ce-lue-shi-yo/
// 来源：力扣（LeetCode）