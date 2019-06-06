/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (26.11%)
 * Total Accepted:    440.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
	// can be done with S(1) though.. 
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> sorted;
        sorted.reserve(nums1.size() + nums2.size());
        auto p1 = nums1.begin();
        auto p2 = nums2.begin();
        while(p1 != nums1.end() && p2 != nums2.end()) {
            if (*p1 > *p2) {
                sorted.push_back(*p2);
                p2++;
            } else {
                sorted.push_back(*p1);
                p1++;
            }
        }
        while (p1 != nums1.end()) {
            sorted.push_back(*p1);
            p1 ++;
        }
        while (p2 != nums2.end()) {
            sorted.push_back(*p2);
            p2 ++;
        }
        
        auto mid = sorted.size() / 2;
        if (sorted.size() % 2 == 0) {
            return double(sorted[mid - 1] + sorted[mid]) / 2;
        }
        return sorted[mid];
    }
};
