class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq_map;
        for (int num : nums) {
            freq_map[num]++;
        }

        vector<vector<int>> buckets(n + 1);
        for (const auto& entry : freq_map) {
            int num = entry.first;
            int freq = entry.second;
            buckets[freq].push_back(num);
        }

        vector<int> result;
        for (int i = n; i >= 0; i--) {
            for (int num : buckets[i]) {
                if (result.size() == k) {
                    break;
                }
                result.push_back(num);
            }
        }

        return result;
    }
};