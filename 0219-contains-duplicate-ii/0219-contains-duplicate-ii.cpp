class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int>m;
        int x = min(k, (int)(nums.size()-1));
        for(int i = 0; i<=x; i++){
            m[nums[i]]++;
        }
        if(nums.size() == 1 and k!=0){
            return false;
        }
        if(m.size() < k+1 and m.size()!=nums.size()){
                return true;
        }
        for(int i = k+1; i<nums.size(); i++)
        {
            m.erase(nums[i - (k+1)]);
            m[nums[i]]++;
            if(m.size() < k+1){
                return true;
            }
        }
        return false;
    }
};