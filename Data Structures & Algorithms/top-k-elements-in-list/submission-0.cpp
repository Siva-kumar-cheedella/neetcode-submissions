class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      
      map<int, int> mp;

      for(int i=0; i<nums.size(); i++) {
        if(mp.find(nums[i]) == mp.end()){
            mp[nums[i]] = 1;
        }else{
            mp[nums[i]]++;
        }  
      }

       vector<pair<int, int>> vpairs;
      for(auto& i:mp){
        pair<int, int> pr;
        pr.first = i.second;
        pr.second = i.first;
        vpairs.push_back(pr);
      }
    
      sort(vpairs.begin(), vpairs.end());

      reverse(vpairs.begin(), vpairs.end());

      vector<int> result;

      for(int i=0; i<k; i++){
        result.push_back(vpairs[i].second);
      }

      return result;

    }
};
