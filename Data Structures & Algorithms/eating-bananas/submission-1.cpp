class Solution {
public:
    bool canEat(vector<int>& piles, int bananasPerHr, int availableHrs){
        for(int i=0; i<piles.size(); i++){   
            int pileSize = piles[i];
            int reqHrsForPile = pileSize/bananasPerHr;
            if(pileSize%bananasPerHr != 0)reqHrsForPile++;
            availableHrs -= reqHrsForPile;

            if(availableHrs <0) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int minimumSpeed = INT_MAX;

        int l=1, r=INT_MAX;
        while(l<=r){
            int midSpeed = l + (r-l)/2;
            bool isPossible = canEat(piles, midSpeed, h);

            if(isPossible){
                r=midSpeed-1;
                minimumSpeed = midSpeed;
            }else{
                l = midSpeed + 1;
            }
        }
        return minimumSpeed;
    }
};
