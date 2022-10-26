class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int>low;
        int n = nums.size();
        vector<int>pref(n);
        pref[0] = nums[0];
        pref[0] %= k;
        for(int i = 1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
            pref[i] %= k;
        }
        low[0] = 0;
        for(int i = 0; i<n; i++)
        {
            if(!low.count(pref[i])){
                low[pref[i]] = i+1;   
            }
            else{
                //already present hai
                if(low[pref[i]] < i){
                    return true;
                }
            }
        }
        return false;
        
    }
};