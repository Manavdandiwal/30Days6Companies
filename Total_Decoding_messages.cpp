/*
A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

Example 1:
Input: str = "123"
Output: 3
Explanation: "123" can be decoded as "ABC"(123),
"LC"(12 3) and "AW"(1 23).

Problem Link :- 
https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#
*/

class Solution {
	public:
		int CountWays(string str)
		{
		    int N = str.length();
		    vector<int> dp(N + 1, 0);
		    dp[0] = 1;
		    dp[1] = 1;
		    
		    if (str[0] == '0')
		        return 0;
		        
		    if (N == 1)
		        return 1;
		        
		    int mod = 1e9 + 7;
		    
		    for (int i = 2; i <= N; i++)
		    {
		        if (str[i - 1] > '0')
		            dp[i] += dp[i - 1];
		            
		        if (str[i - 2] == '1' || (str[i - 2] == '2' && str[i - 1] <= '6'))
		            dp[i] += dp[i - 2];
		            
		        dp[i] = dp[i] % mod;
		    }
		    
		    return dp[N];
		}

};