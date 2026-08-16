class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> freq;

    // Count frequency
    for(char ch : s) {
        freq[ch]++;
    }

    // Store {frequency, character}
    vector<pair<int, char>> v;

    for(auto it : freq) {
        v.push_back({it.second, it.first});
    }

    // Sort by frequency in decreasing order
    sort(v.begin(), v.end(), greater<pair<int, char>>());

    string ans = "";

    // Add characters according to their frequency
    for(auto it : v) {
        ans += string(it.first, it.second);
    }

    return ans;
    }
};