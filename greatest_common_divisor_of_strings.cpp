/*
For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:
Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"

Example 2:
Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"

Problem Link :- 
https://leetcode.com/problems/greatest-common-divisor-of-strings/
*/

class Solution {
public:
    bool check(string a, string b)
    {
        int x = a.length() / b.length();
        string tmp = "";
        for (int i = 0; i < x; i++)
            tmp += b;
        
        return a == tmp;
    }
    
    string gcdOfStrings(string str1, string str2) 
    {
        int L = __gcd(str1.length(), str2.length());
        string ans = str1.substr(0, L);
        
        if (check(str1, ans) && check(str2, ans))
            return ans;
        
        return "";
    }
};