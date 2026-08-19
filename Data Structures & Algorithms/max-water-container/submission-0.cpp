class Solution {
public:

    int getMaxWater(int i, int j, int x, int y){
        return abs((j-i)*(min(x,y)));
    }

    int maxArea(vector<int>& heights) {
        int i=0;
        int j=heights.size()-1;

        int result=INT_MIN;

        while(i<j){
            int curMax = getMaxWater(i,j,heights[i], heights[j]);
            result = max(result, curMax);

            if(min(heights[i], heights[j]) == heights[i]){
                i++;
            }
            else{
                j--;
            }
        }

        return result;
    }
};
