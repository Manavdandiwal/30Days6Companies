/*
Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.
Input:
N = 5
words[] = {act,god,cat,dog,tac}
Output: 
god dog
act cat tac

Problem Link :- 
https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
*/

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
