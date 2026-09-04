class Solution {
public:

    bool searchTargetInRow(vector<vector<int>>& mat, int rowIndex, int target){
        int l = 0;
        int r = mat[0].size()-1;

        while(l<=r){
            int midIndex = l + (r-l)/2;
            int cur = mat[rowIndex][midIndex];

            if(cur < target){
                l = midIndex+1;
            }else if(cur > target){
                r = midIndex -1;
            } else {
                return true;
            }
        }
        return false;
    }

    int getLowerBoundaryIndex(vector<vector<int>>& mat, int target){
        int l = 0;
        int r = mat.size()-1;

        int lowerBoundary=0;

        while(l<=r){
            int midIndex = l + (r-l)/2;
            int cur = mat[midIndex][0];

            if(cur == target){
                return midIndex;      
            }else if(cur < target){
                lowerBoundary = midIndex;
                l = midIndex+1;
            }else{
                r = midIndex -1;
            }
        }
        return lowerBoundary;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowIndex = getLowerBoundaryIndex(matrix, target);
        return searchTargetInRow(matrix, rowIndex, target);
    }
};
