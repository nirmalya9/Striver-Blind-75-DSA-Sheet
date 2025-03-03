class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (const int num : nums)
            ++count[num];

        // Define a struct for priority queue
        struct Compare {
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second; // Min-Heap based on frequency
            }
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

        for (const auto& [num, freq] : count) {
            minHeap.emplace(num, freq);
            if (minHeap.size() > k)
                minHeap.pop();
        }

        vector<int> ans;
        while (!minHeap.empty()) {
            ans.push_back(minHeap.top().first);
            minHeap.pop();
        }

        // Reverse to get the correct order
        reverse(ans.begin(), ans.end());
        return ans;
    }
};