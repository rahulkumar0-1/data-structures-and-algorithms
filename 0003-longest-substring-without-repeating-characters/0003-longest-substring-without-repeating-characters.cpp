class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = -1, maxLen = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.find(s[i]) != mp.end() && left <= mp[s[i]]) {
                left = mp[s[i]];
            }
            mp[s[i]] = i;
            maxLen = max(maxLen, i - left );
        }
        return maxLen;
    }
};