class Solution {
public:
    bool isValid(string s) {
        map<char, char> mp;
        
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        
        stack<int> st;

        for(int i=0; i < s.length(); i++){
            if(s[i] == '(' || s[i]== '{' || s[i]=='['){
                st.push(s[i]);
            }else{
                if(st.empty() || (mp[st.top()] != s[i])){
                    return false;
                }else{
                    st.pop();
                }
            }
        }

        return st.empty() ? true : false;
    }
};
