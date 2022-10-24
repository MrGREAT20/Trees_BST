class Solution {
public:
    long long int mod = 1e9 + 7;
    int strStr(string haystack, string needle) {
        string s = haystack;
        string p = needle;
        int n = s.length();
    	int m = p.length();
        long long int ans = 0;
    	long long int hash = 0;
    	long long int pri = 1;
    	for(auto ch : p){
    		ans = (ans + ((ch - 'a' + 1) * pri)%mod)%mod;
    		pri = (pri * 31)%mod;
    	}
    	long long int pri1 = 1;
    	for(int i = 0; i<m; i++)
    	{
    		hash = (hash + ((s[i] - 'a' + 1) * pri1)%mod)%mod;
    		pri1 = (pri1 * 31)%mod;
    	}
        if(ans == hash){
            return 0;
        }
        else{
            long long int pri2 = 1;
            for(int i = m; i<n; i++)
            {
                hash = (hash + ((s[i] - 'a' + 1) * pri1)%mod)%mod;
                hash = (hash - ((s[i-m] - 'a' + 1) * pri2)%mod + mod)%mod;
                pri2  = (pri2 * 31)%mod;
                pri1 = (pri1 * 31)%mod;
                ans = (ans * 31)%mod;
                if(ans == hash){
                    return ((i - m) + 1);
                }
            }
            return -1;
        }
    }
};