class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (const auto& str : strs) {
            encoded += to_string(str.length()) + "#" + str;
        }

        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0;
        while (i < s.size()) {
            int j = i;

            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            int start = j + 1;
            decoded.push_back(s.substr(start, len));

            i = start + len;
        }

        return decoded;
    }
};
