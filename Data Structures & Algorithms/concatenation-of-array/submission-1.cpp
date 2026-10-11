class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> lst;
        for (int i=0; i < 2*nums.size(); i++) {
            lst.push_back(nums[i % nums.size()]);
        }
        return lst;
    }
};