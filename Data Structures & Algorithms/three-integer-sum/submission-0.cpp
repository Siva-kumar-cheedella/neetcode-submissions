class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int, int> mp;
        map<pair<int, int>, int> pairmp;
        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]=i;
        }
        

        vector<vector<int>> result;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                int target = (-1)*(nums[i]+nums[j]);
                pair<int, int> p;
                p.first= nums[i];
                p.second = nums[j];
                if(mp[target]>j && pairmp.find(p)==pairmp.end()){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(target);
                    result.push_back(temp);
                    pairmp[p]=1;
                }
            }
        }

        return result;
    }
};
