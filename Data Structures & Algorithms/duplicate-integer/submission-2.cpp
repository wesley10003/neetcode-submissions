class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.contains(n)) {
                return true;
            }
            seen.insert(n);
        }

        // for (int n : nums) {
        //     if (!seen.insert(n).second) {
        //         return true;
        //     }
        // }
        // auto [it, inserted] = seen.insert(n);
        // it: iterator to the new or existing element
        // inserted: true if newly inserted, false if already present
        // WE LOOK AT the second returned value from insert(), which is true if
        // successfully inserted, else false if dupe

        return false;
    }
};