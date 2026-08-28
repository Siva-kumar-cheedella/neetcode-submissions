class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result (n, 0);
        stack<int> st;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temperatures[st.top()]<=temperatures[i]){
                st.pop();
            }
            if(!st.empty()){
                int nextWarmerIndex = st.top();
                result[i] = nextWarmerIndex - i ;
            }else{
                result[i] =0;
            }
            st.push(i);
        }
        return result;
    }
};
