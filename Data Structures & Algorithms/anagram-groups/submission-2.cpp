
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create a map from frequency signature -> vector of anagrams
        unordered_map<string, vector<string>> map;
        // For each string in strs, create its frequency signature
        for (const string& str : strs) {
            int count[26] = {0};
            for (char c : str) {
                count[c - 'a']++;
            }

            // Create a string key for this signature
            string key = "";
            for (int i : count) {
                key += std::to_string(i) + "#";
            }

            // Using the frequency signature as the key, push the anagram into its respective vector
            map[key].push_back(str);
        }

        // Put each vector of anagrams in the hashmap into a 2D vector for returning
        vector<vector<string>> result;
        for (auto& entry : map) {
            result.push_back(std::move(entry.second));
        }

        return result;
    }
};
