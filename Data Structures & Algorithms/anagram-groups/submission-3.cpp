class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. Fixed syntax: Added closing '>' for unordered_map
        unordered_map<string, vector<string>> res;

        // 2. Performance: Pass by const reference to avoid copying strings in the loop
        for (const string& str : strs) {
            string str_copy = str;
            // 3. Fixed syntax: std::sort modifies the string in-place, it doesn't return it
            sort(str_copy.begin(), str_copy.end());
            res[str_copy].push_back(str);
        }

        vector<vector<string>> ans;
        // 4. Fixed variable name: Changed 'my_map' to 'res'
        ans.reserve(res.size()); 

        for (auto& [key, val] : res) {
            ans.push_back(move(val)); 
        }
        
        // 5. Missing return statement
        return ans;
        
    }
};
