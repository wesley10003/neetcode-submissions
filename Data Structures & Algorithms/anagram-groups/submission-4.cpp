class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1. CONTAINER TYPES
        // unordered_map is a hash table allowing O(1) average lookup time.
        // Key:   string (the sorted letters acting as an anagram signature, e.g., "aet").
        // Value: vector<string> (a list of all original matching words, e.g., ["eat", "tea"]).
        unordered_map<string, vector<string>> res;

        // 2. PASS-BY-REFERENCE LOOP (&)
        // 'const string& str' creates a read-only reference to each string in 'strs'.
        // The '&' acts as an alias, meaning C++ points directly to the existing memory
        // instead of wasting time making a brand-new photocopy of the string text.
        for (const string& str : strs) {
            
            // We make an explicit copy here because we need to scramble/sort the letters 
            // without ruining the original word stored in 'strs'.
            string str_copy = str;
            
            // 3. IN-PLACE SORTING METHODS
            // std::sort takes two iterators: the beginning and the end of the string.
            // It modifies the characters alphabetically *in-place* and returns 'void'.
            // Because anagrams share identical letters, "eat" and "tea" both become "aet".
            sort(str_copy.begin(), str_copy.end());
            
            // 4. AUTOMATIC MAP INITIALIZATION
            // The map bracket operator res[key] checks if "aet" exists. 
            // If it doesn't, it automatically instantiates an empty vector<string> for it.
            // .push_back(str) then appends our original word (like "eat") into that vector.
            res[str_copy].push_back(str);
        }

        // 5. OUTPUT CONTAINER & MEMORY ALLOCATION
        // 'ans' is our final return grid containing vectors inside a vector.
        vector<vector<string>> ans;
        
        // res.size() returns the number of unique hash map keys (unique anagram groups).
        // .reserve() pre-allocates that exact amount of rows inside our 'ans' vector.
        // This prevents the computer from constantly pausing to resize memory blocks.
        ans.reserve(res.size()); 

        // 6. STRUCTURED BINDING SYNTAX (C++17)
        // Instead of using confusing syntax like 'pair.first' and 'pair.second',
        // 'auto& [key, val]' instantly unpacks each map entry into clean, named variables.
        // 'key' gets the sorted string signature, and 'val' gets the vector of matching words.
        for (auto& [key, val] : res) {
            
            // 7. MEMORY TRANSFERS (std::move)
            // std::move() converts 'val' into an rvalue reference.
            // Instead of executing an expensive deep copy of strings into 'ans', it 
            // instantly "steals" the internal data pointers of 'val' and hands them to 'ans'.
            ans.push_back(move(val)); 
        }
        
        // Return the gathered matrix back to the LeetCode judge.
        return ans;
        
    }
};
