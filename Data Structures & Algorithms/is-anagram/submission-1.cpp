class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        array<int, 26> arr1{};
        array<int, 26> arr2{};

        for (int i = 0; i < s.size(); i++) {
            arr1[s[i] - 'a'] += 1;
            arr2[t[i] - 'a'] += 1;
        };

        for (int j = 0; j < 26; j++) {
            if (arr1[j] != arr2[j]) return false;
        };

        return true;
    }
};
