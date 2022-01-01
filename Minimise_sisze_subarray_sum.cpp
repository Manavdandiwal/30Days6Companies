/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 11, nums = [1,2,3,4,5]
Output: 3
Explanation: Sum of subarray [3,4,5] is higher than target and has minimum size of all subarrays with sum greater than or equal to target.

Problem Link :- 
https://leetcode.com/problems/minimum-size-subarray-sum/
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) 
    {
        int N = arr.size();
        
        int i = 0, j = -1, ans = 1e6, sum = 0;
        
        while (j < N)
        {
            if (sum >= target)
            {
                ans = min(ans, j - i + 1);
                
                sum -= arr[i];
                i++;
            }
            
            else if (sum < target)
            {
                j++;
                if (j < N)
                    sum += arr[j];
            }
        }
        
        return (ans == 1e6) ? 0 : ans;
    }
};