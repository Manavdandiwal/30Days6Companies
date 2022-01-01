/*
M items are to be delivered in a circle of size N. Find the position where the M-th item will be delivered if we start from a given position K. Note that items are distributed at adjacent positions starting from K.

Example 1:
Input:
N = 5, M = 2, K = 1
Output:
2
Explanation:
If we start from 1st position, the
2nd item will land at the 2nd position.

Problem Link :- 
https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1#
*/

class Solution {
  public:
    int findPosition(int N , int M , int K) {
        int ans = M + K - 1;
        if (ans > N)
        {
            if (ans % N)
                return ans % N;
                
            return N;
        }
            
        return ans;
    }
};