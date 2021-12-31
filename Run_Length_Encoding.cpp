/*
Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.

Input:
str = aaaabbbccc
Output: a4b3c3
Explanation: a repeated 4 times consecutively b 3 times, c also 3 times.

Problem Link :- 
https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#
*/


string encode(string str)
{     
    string ans = "";
    int cnt = 1;
    int i;
    for (i = 0; i < str.length() - 1; i++)
    {
        if (str[i] == str[i + 1])
            cnt++;
            
        else
        {
            ans += str[i];
            ans += to_string(cnt);
            cnt = 1;
        }
    }
    
    ans += str[i];
    ans += to_string(cnt);
    
    return ans;
}