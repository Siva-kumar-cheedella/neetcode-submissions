class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        
        if(nums.size()==2) return nums[0]<nums[1] ? nums[0] : nums[1];

        if(nums[0] < nums[nums.size()-1]) return nums[0];
        if(nums[nums.size()-2] > nums[nums.size()-1]) return nums[nums.size()-1];
        
        int l=1, r=nums.size()-2;
        while(l<=r){
            int mid = l + (r-l)/2;
            int midVal = nums[mid];
            if(midVal < nums[mid-1] && midVal < nums[mid+1]){
                return midVal;
            }else{
                int firstVal = nums[0];
                if(midVal < firstVal){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
        return 0;
    }
};