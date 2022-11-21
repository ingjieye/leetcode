class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ret = -1;
        for (int i=1; i<nums.size(); i++) {
            nums[i] += nums[i-1];
        }
        auto sum = nums[nums.size() - 1];
        auto partialSum = 0;
        for (int i=0; i<nums.size(); i++) {
            if (partialSum + nums[i] == sum) {
                ret = i;
                break;
            }
            partialSum = nums[i];
        }
        return ret;
    }
};