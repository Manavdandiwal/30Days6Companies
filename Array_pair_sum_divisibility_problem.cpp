/*
Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

Example 1 :
Input : arr = [9, 5, 7, 3], k = 6
Output: True
Explanation: {(9, 3), (5, 7)} is a 
possible solution. 9 + 3 = 12 is divisible
by 6 and 7 + 5 = 12 is also divisible by 6.

Example 2:
Input : arr = [2, 4, 1, 3], k = 4
Output: False
Explanation: There is no possible solution.

Problem Link :- 
https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1#
*/

class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        int arr[k] = {0};
        
        for (int i = 0; i < nums.size(); i++)
        {
            int tmp = nums[i] % k;
            arr[tmp]++;
        }
        
        int i = 1, j = k - 1;
        
        if (arr[0] % 2)
            return false;
        while (i <= j)
        {
            if (i == j)
            {
                if (arr[i] % 2 == 1)
                {
                    return false;
                }
                    
                i++;
                j--;
            }
            
            else if (arr[i] != arr[j])
                return false;
                
            i++;
            j--;
        }
        
        return true;
    }
};