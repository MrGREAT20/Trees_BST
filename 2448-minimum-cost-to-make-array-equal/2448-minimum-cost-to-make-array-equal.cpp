class Solution {
public:
    long long int check(vector<int>&nums, vector<int>&cost, int x)
    {
        long long int ans = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            ans += (long long int)abs(nums[i] - x) * (long long int)cost[i];
        }
        return ans;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int maxi = nums[0];
        int mini = nums[0];
        for(int i = 1; i<nums.size(); i++){
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }
        // now i have to make my array to one of the elements in the range {mini ,  maxi}
        // now how to think to which number shall i convert my array to...
        long long int l = 1, r = 1000000, res = check(nums, cost, 1), x;
        while (l < r) {
            x = (l + r) / 2;
            long long int y1 = check(nums, cost, x), y2 = check(nums, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }
        
};