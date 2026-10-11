class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // vector<int> lst;
        // for (int i=0; i < 2*nums.size(); i++) {
        //     lst.push_back(nums[i % nums.size()]);
        // }
        // return lst;


        // nums.reserve(nums.size() * 2) //optional, allocates enough space upfront
        // int n = nums.size();
        // for (int i = 0; i < n; i++)
        //     nums.push_back(nums[i]);
        // return nums;


        vector<int> ans = nums;
        ans.insert(ans.end(), nums.begin(), nums.end());

        return ans;

    }
};