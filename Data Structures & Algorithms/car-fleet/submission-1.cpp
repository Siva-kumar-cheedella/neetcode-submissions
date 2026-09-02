class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vp;
        for(int i=0; i<position.size(); i++){
            vp.push_back({position[i], speed[i]});
        }
        sort(vp.begin(), vp.end());

        stack<double> st;

        for(int i=position.size()-1; i>=0; i--){
            double time = (target - vp[i].first)/(double)vp[i].second;
            if(!st.empty() && st.top() >= time){
                continue;
            }
            st.push(time);
        }

        return st.size();
    }
};
