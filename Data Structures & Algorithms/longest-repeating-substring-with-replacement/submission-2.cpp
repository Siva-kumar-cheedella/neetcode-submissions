class Solution {
public:
    int getMaxLength(string s, int k){
        int l=0;
        int r=0;
        int available = k;
   
        int maxLength=1;
        while(r<s.length()){
            if(s[r]=='*'){
                if(available >0){
                    available--;
                    maxLength = max(maxLength, r-l+1);
                    r++;
                }else{
                   maxLength = max(maxLength, r-l);
                    while(s[l]!='*'){
                        l++;
                    }

                    l++; r++;
    
                }
            }else{
                maxLength = max(maxLength, r-l+1);
                r++;
            }
            
        }
        return maxLength;
    }

    int characterReplacement(string s, int k) {
        vector<string> v;

        for(int i=0; i<26; i++){
            char curChar = 'A' + i;
            string singleCharString = "";
            for(int j=0; j<s.length(); j++){
                if(s[j] == curChar){
                    singleCharString += curChar;
                }else{
                    singleCharString +="*";
                }
            } 
            v.push_back(singleCharString);
        }

        // for(auto & str : v){
        //     cout<<str<<endl;
        // }
        int maxSubstringLength=0;
        for(int i=0; i<26; i++){
            int maxSubstringLengthWithSingleChar = getMaxLength(v[i], k);
            // cout<<v[i]<<" "<<maxSubstringLengthWithSingleChar<<endl;
            maxSubstringLength = max(maxSubstringLength, maxSubstringLengthWithSingleChar);
        }

        return maxSubstringLength;

    }
};