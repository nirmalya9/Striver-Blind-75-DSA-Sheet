class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
           int n = nums.size();
    vector<int> ans(n);
    if(0 == n)  return ans;

    ans[0] = 1;
    int prod = 1;
    for(int i = 1; i < n; i++)
    {
        prod = prod * nums[i - 1];
        ans[i] = prod;
    }

    prod = 1;
    for(int i = n - 1; i >= 0; i--)
    {
        ans[i] = prod * ans[i];
        prod = nums[i] * prod;
    }

    return ans;
    }
};