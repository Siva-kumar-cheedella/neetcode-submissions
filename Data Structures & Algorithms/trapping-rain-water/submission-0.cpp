class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefixMaxHeights(height.size(),0);
        vector<int> suffixMaxHeights(height.size(),0);

        prefixMaxHeights[0] = 0;
        suffixMaxHeights[height.size()-1] = 0;

        int preMax = height[0];
        for(int i=1; i<height.size(); i++){
            prefixMaxHeights[i] = preMax;
            preMax = max(height[i], preMax);
        }

        int sufMax = height[height.size()-1];
        for(int i=height.size()-2; i>=0; i--){
            suffixMaxHeights[i] = sufMax;
            sufMax = max(height[i], sufMax);
        }

        int totalTrappedWater=0;
        for(int i=0; i<height.size(); i++){
            int trappedWaterOnCurPillar = min(prefixMaxHeights[i], suffixMaxHeights[i]) - height[i];
            if(trappedWaterOnCurPillar > 0)
            {
                totalTrappedWater+=trappedWaterOnCurPillar;
            }
        }

        return totalTrappedWater;
    }
};
