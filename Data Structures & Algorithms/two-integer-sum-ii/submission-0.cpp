class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int l=0, r=numbers.size()-1;
        while(l<r){
            int curSum = numbers[l]+numbers[r]; 
            if(curSum == target){
                result.push_back(l+1);
                result.push_back(r+1);
                return result;
            }
            if(curSum < target){
                l++;
            }else{
                r--;
            }
        }
    }
};
