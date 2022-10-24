class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int>m;
        vector<int>ans;
        for(auto x : nums){
            m[x]++;
        }
        priority_queue<pair<int, int>>pq;
        for(auto x : m){
            if(pq.size() < k){
                pq.push({(x.second * -1), x.first});
            }
            else{
                if(x.second * -1 < pq.top().first){
                    pq.pop();
                    pq.push({(x.second * -1), x.first});
                }
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};