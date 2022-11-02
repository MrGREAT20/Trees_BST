class Solution {
public:
    int c;
void conquer(int low, int mid, int high, vector<int>&a)
{
    vector<int>temp;
	int left = low;
	int right = mid + 1;
	while(left <= mid and right <= high)
    {
        if((long)a[left] > (long)2 * a[right])
        {
            //temp.pb(a[left]);
            c += (mid - left) + 1;
            right++;
        }
        else
        {
           left++;  
        }
    }
    left = low;
    right = mid + 1;
    while(left <= mid and right <= high)
    {
        if(a[left] < a[right])
        {
            temp.push_back(a[left]);
            left++;
        }
        else
        {
            temp.push_back(a[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(a[left++]);
    }
    while(right <= high){
        temp.push_back(a[right++]);
    }
    for(int i = low; i<=high; i++)
    {
        a[i] = temp[i-low];
    }
    return;
}
void merges(int low, int high, vector<int>&a)
{
	if(low >= high) return;
	int mid = (low + high)>>1;
	merges(low, mid, a);
	merges(mid+1, high, a);
	conquer(low, mid, high, a);
}
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        c = 0;
    	merges(0, n-1, nums);
    	return c;
    }
};