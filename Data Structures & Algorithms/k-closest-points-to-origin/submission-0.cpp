class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<points.size(); i++){
            int dist = points[i][0] * points[i][0] +
           points[i][1] * points[i][1];
            if(pq.size() < k){
                pq.push({dist, i});
            }else{
                if(pq.top().first > dist){
                    pq.pop();
                    pq.push({dist,i});
                }
            }
        }
        vector<vector<int>> result;
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            result.push_back(points[temp.second]);
            pq.pop();
        }
        return result;
    }
};
