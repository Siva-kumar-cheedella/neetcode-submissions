class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length()==0)return 0;
        map<char, int> mp;
        
        int n = s.length();
        int l=0;
        mp[s[0]]=0;

        int r=1;
        int maxLength=1;
        while(r<n){
            if(mp.find(s[r]) == mp.end()){
                mp[s[r]] = r;
                maxLength = max(maxLength, r-l+1);
                r++;
            }else{
                int indexOfRepeatedChar = mp[s[r]];
                if(indexOfRepeatedChar < l){
                    maxLength = max(maxLength, r-l+1);
                    mp[s[r]] = r;
                    r++;
                }else{
                    maxLength = max(maxLength, r-l);
                    l = indexOfRepeatedChar + 1;
                    mp[s[r]] = r;
                    r++;
                }
            }

            
        }
        return maxLength;
    }
};
