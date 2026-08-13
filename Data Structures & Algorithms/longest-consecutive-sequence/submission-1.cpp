class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int x = nums[i]-1;
            if(mp.find(x)!=mp.end()){
                mp[nums[i]] = mp[x]+1;
            }else{
                mp[nums[i]]=1;                
            }
        }

        int longestLength=0;
        for(auto& i:mp){
            longestLength=max(longestLength, i.second);
        }
        return longestLength;
    }
};
