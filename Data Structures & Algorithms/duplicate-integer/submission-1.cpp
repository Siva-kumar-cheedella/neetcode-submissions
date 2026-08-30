class Solution {
    public:
        bool hasDuplicate(vector<int>& nums) {
                   map<long, int> mp;

                           for (auto& i : nums) {
                                       if (mp.find(i) != mp.end())
                                                       return true;

                                                                   mp[i]++;
                                                                           }

                                                                                   return false;
                                                                                       }
                                                                                       };