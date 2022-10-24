class Solution {
public:
    long long int mod = 1e9 + 7;
    int strStr(string haystack, string needle) {
        string s = haystack;
        string p = needle;
        int n = s.length();
    	int m = p.length();
    	long long int ans = 0;
    	long long int pri = 1;
    	for(auto ch : p){
    		ans = (ans + ((ch - 'a' + 1) * pri)%mod)%mod;
    		pri = (pri * 31)%mod;
    	}
    	int finalans = INT_MAX;
    	for(int i = 0; i<=n-m; i++)
    	{
    		long long int hash = 0;
    		long long int pri = 1;
    		for(int j = i; j<m+i; j++)
    		{
    			hash = (hash + ((s[j] - 'a' + 1) * pri)%mod)%mod;
    			pri = (pri * 31)%mod;
    		}
    		if(hash == ans){
    			finalans = min(finalans, i);
    		}
    	}
        return (finalans >= INT_MAX ? -1 : finalans);
    }
};