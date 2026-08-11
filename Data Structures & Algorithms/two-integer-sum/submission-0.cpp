class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int requiredSum = target - nums[i];
            if(mp.find(requiredSum) != mp.end()){
                vector<int> res;
                res.push_back(mp[requiredSum]);
                res.push_back(i);
                return res;
            }
            mp[nums[i]]=i;
        }

    }
};
