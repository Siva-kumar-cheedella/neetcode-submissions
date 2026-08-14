class Solution {
public:
    bool isValidChar(char ch){
        if((ch-'0'>=0 && ch-'0'<=9) ||
            (ch-'a'>=0 && ch-'a'<=25) ||
            (ch-'A'>=0 && ch-'A'<=25)
        ){
            return true;
        }

        return false;
    }

    bool isPalindrome(string s) {
        string str="";
        for(int i=0; i<s.length(); i++){
            if(isValidChar(s[i])){
                str+=tolower(s[i]);
            }
        }
        
        int l=0;
        int r=str.length()-1;
        while(l<str.length() && r>=0){
            if(str[l]!=str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
