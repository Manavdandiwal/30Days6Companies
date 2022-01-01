/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. Find these two numbers.

Example 1:
Input:
N = 2
Arr[] = {2, 2}
Output: 2 1
Explanation: Repeating number is 2 and 
smallest positive missing number is 1.

Problem Link :- 
https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#
*/

class Solution
{
public:
    int ans[2];
    int *findTwoElement(int *arr, int n)
    {
        vector<bool> check(n + 1, false);

        for (int i = 0; i < n; i++)
        {
            // cout << arr[i] << endl;
            if (check[arr[i]])
                ans[0] = arr[i];

            check[arr[i]] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!check[i])
            {
                ans[1] = i;
                // cout << i << endl;
            }
        }

        return ans;
    }
};