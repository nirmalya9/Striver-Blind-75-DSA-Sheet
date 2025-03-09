class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
    unordered_set<int> seen(nums.begin(), nums.end()); // O(n) storage
        int ans = 0;

        for (int num : seen) { 
            if (!seen.count(num - 1)) { 
                int length = 1;
                int current = num;

                while (seen.count(current + 1)) {
                    current++;
                    length++;
                }

                ans = max(ans, length);
            }
        }
        return ans;
    }
};