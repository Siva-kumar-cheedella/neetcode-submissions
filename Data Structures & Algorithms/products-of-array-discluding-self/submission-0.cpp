class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixMuls(n, 0);
        vector<int> suffixMuls(n, 0);
        
        prefixMuls[0]=nums[0];
        suffixMuls[n-1]=nums[n-1];

        for(int i=1; i<n; i++){
            prefixMuls[i] = prefixMuls[i-1]*nums[i];
            suffixMuls[n-1-i] = suffixMuls[n-i]*nums[n-i-1];
        }

        vector<int> resultMuls(n,0);
        for(int i=0; i<n; i++){
            int leftMul = i>0 ? prefixMuls[i-1] : 1;
            int rightMul = i<n-1 ? suffixMuls[i+1] : 1;
            resultMuls[i] = leftMul * rightMul;
        }
        return resultMuls;
    }
};
