#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) x.begin(), x.end()
#define _sort(x) sort(all(x))
#define __sort(x, y) sort(all(x), y)
#define vi vector<int>
#define vl vector<ll>
#define loop(i, N) for (int i = 0; i < N; i++)
#define _loop(i, x, N) for (int i = x; i < N; i++)
#define __loop(i, x, N, y) for (int i = x; i < N; i += y)
#define mod 1000000007

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) 
    {
        unordered_map<string, vector<string>> check;
        
        for (int i = 0; i < string_list.size(); i++)
        {
            string tmp = string_list[i];
            sort(tmp.begin(), tmp.end());
            check[tmp].push_back(string_list[i]);
        }
        
        vector<vector<string>> ans;
        for (auto i : check)
        {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vi arr(N);

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        vi count(100, 0);

        for (int i = 0; i < N; i++)
        {
            count[abs(arr[i])]++;
        }
    }
}