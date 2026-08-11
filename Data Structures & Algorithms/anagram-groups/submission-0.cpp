class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for(auto& str : strs){
            string tempKey = str;
            sort(tempKey.begin(), tempKey.end());
            mp[tempKey].push_back(str);
        }

        vector<vector<string>> res;

        for(auto& i:mp){
            res.push_back(i.second);
        }
        return res;
    }
};
