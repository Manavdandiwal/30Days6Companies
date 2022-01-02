/*
An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
original string: abbbababbbababbbab 
encoded string : 3[a3[b]1[ab]]

Example 2:
Input: s = 3[b2[ca]]
Output: bcacabcacabcaca
Explaination: 2[ca] means 'ca' is repeated 
twice which is 'caca' which concatenated with 
'b' becomes 'bcaca'. This string repeated 
thrice becomes the output.

Problem Link :- 
https://practice.geeksforgeeks.org/problems/decode-the-string2444/1
*/

class Solution{
public:
    string make_str(string str, int n)
    {
        string ans = "";
        for (int i = 0; i < n; i++)
            ans += str;
            
        return ans;
    }
    
    bool is_num(char ch)
    {
        if (ch >= '0' && ch <= '9')
            return true;
            
        return false;
    }
    
    string decodedString(string s)
    {
        stack<int> nums;
        stack<char> st;
        
        for (int i = 0; i < s.length(); i++)
        {
            if (is_num(s[i]))
            {
                int tmp = 0;
                while (is_num(s[i]))
                {
                    tmp *= 10;
                    tmp += s[i] - '0';
                    i++;
                }
                nums.push(tmp);
                i--;
            }
            
            else if (s[i] == '[')
            {
                st.push('[');
                
                if (i == 0 || !is_num(s[i - 1]))
                    nums.push(1);
            }
            
            else if (s[i] == ']')
            {
                int cnt = nums.top();
                nums.pop();
                
                string tmp = "";
                
                while (!st.empty() && st.top() != '[')
                {
                    tmp = st.top() +tmp;
                    st.pop();
                }
                
                tmp = make_str(tmp, cnt);
                
                if (!st.empty() && st.top() == '[')
                    st.pop();
                    
                for (int i = 0; i < tmp.length(); i++)
                    st.push(tmp[i]);
            }
            
            else
                st.push(s[i]);
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};