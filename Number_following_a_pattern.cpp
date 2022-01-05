/*
Given a pattern containing only I's and D's. I for increasing and D for decreasing.
Devise an algorithm to print the minimum number following that pattern.
Digits from 1-9 and digits can't repeat.

Example 1:
Input:
D
Output:
21
Explanation:
D is meant for decreasing,
So we choose the minimum number
among 21,31,54,87,etc.

Example 2:
Input:
IIDDD
Output:
126543
Explanation:
Above example is self- explanatory,
1 < 2 < 6 > 5 > 4 > 3
I - I - D - D - D

Problem Link :-
https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#
*/

class Solution{   
public:
    string printMinNumberForPattern(string S)
    {
        int N = S.length();
        int arr[N + 1] = {0};

        int curr_fill = 1, filled_pos = 0;
        bool flag = false;
        for (int i = 0; i < N; i++)
        {
            if (S[i] == 'I')
            {
                int cnt = 0;
                while (i < N && S[i] == 'I')
                {
                    cnt++;
                    i++;
                }
                i--;
                int j = filled_pos;
                while (j <= filled_pos + cnt)
                {
                    arr[j] = curr_fill++;
                    j++;
                }
                filled_pos += cnt;
                curr_fill--;
            }

            else
            {
                int cnt = 0;
                while (i < N && S[i] == 'D')
                {
                    cnt++;
                    i++;
                }
                i--;

                if (flag)
                {
                    curr_fill = max(curr_fill - 1, 1);
                    filled_pos = max(0, filled_pos - 1);
                }

                int j = filled_pos + cnt;
                while (j >= filled_pos)
                {
                    arr[j] = curr_fill++;
                    j--;
                }
                filled_pos += cnt + 1;
                flag = true;
            }
            //print(arr, N);
        }

        string ans;
        for (int i = 0; i < N + 1; i++)
            ans += arr[i] + '0';

        return ans;
    }
};