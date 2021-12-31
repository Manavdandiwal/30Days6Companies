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
