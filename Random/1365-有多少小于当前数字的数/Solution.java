
public class Solution {
    //计数排序思想，定范围的数排序
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] data = new int[101];
        int[] result = new int[nums.length];
        for (int i : nums) {
            data[i] += 1;
        }
        for (int j = 0; j < nums.length; j++) {
            for (int i = 0; i < nums[j]; i++)
                result[j] += data[i];
        }
        return result;
    }
}
