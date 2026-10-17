class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;

        for (int i=0; i<nums.size(); i++) {
            int rem = target - nums[i];
            if (num_map.contains(rem)) {
                return vector<int> {num_map[rem], i};
            }
            num_map[nums[i]] = i;
        }
    }
};
