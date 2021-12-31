/*
Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

Input : 
n = 4, k = 10
a[] = {1, 2, 3, 4}
Output : 
7
Explanation:
The contiguous subarrays are {1}, {2}, {3}, {4} 
{1, 2}, {1, 2, 3} and {2, 3} whose count is 7.

Problem Link :- 
https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#
*/


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) 
    {
        long long i = 0, ans = 0, j = 0, curr_product = 1;

        while (j < a.size())
        {
            while (curr_product < k && j < a.size())
            {
                curr_product *= a[j];
                ans += j - i + 1;
                j++;
            }

            while (curr_product >= k)
            {
                ans--;
                curr_product /= a[i];
                i++;

                if (i == j && curr_product >= k)
                {
                    curr_product = 1;
                    i++;
                    j++;
                }
            }
        }

        return ans;
    }
};