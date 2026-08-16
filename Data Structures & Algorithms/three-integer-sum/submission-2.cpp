class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for(int i=0; i<=nums.size()-3; i++){

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = (-1)*nums[i];
            int l=i+1;
            int r=nums.size()-1;

            while(l<r){
                int curSum = nums[l]+nums[r];
                if(curSum == target){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    result.push_back(temp);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
                else if(curSum < target){
                    l++;
                }else{
                    r--;
                }
            }
        }
        return result;
    }
};
