class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Define quicksort as a recursive lambda function
        auto quicksort = [&](auto& self, vector<int> arr) -> vector<int> {
            if (arr.size() <= 1) {
                return arr; // Added missing semicolon
            }

            int pivot = arr[arr.size() / 2]; // Added missing semicolon

            vector<int> left;
            vector<int> right;
            vector<int> middle;

            for (int n : arr) {
                if (n < pivot) {
                    left.push_back(n);
                } 
                else if (n > pivot) {
                    right.push_back(n);
                }
                else {
                    middle.push_back(n);
                }
            }

            // Optimization: Use std::move to transfer data instead of copying it
            vector<int> sorted_left = self(self, move(left));
            vector<int> sorted_right = self(self, move(right));

            vector<int> res;
            res.reserve(arr.size());

            // Use move iterators to reassemble without copying elements
            res.insert(res.end(), make_move_iterator(sorted_left.begin()), make_move_iterator(sorted_left.end()));
            res.insert(res.end(), make_move_iterator(middle.begin()), make_move_iterator(middle.end()));
            res.insert(res.end(), make_move_iterator(sorted_right.begin()), make_move_iterator(sorted_right.end()));

            return res; // Added missing semicolon
        };

        return quicksort(quicksort, move(nums));




        // // Traditional high-performance C++ In-Place Quicksort
        // void quicksortInPlace(std::vector<int>& arr, int low, int high) {
        //     if (low < high) {
        //         int pivot = arr[high];
        //         int i = low - 1;
                
        //         for (int j = low; j < high; j++) {
        //             if (arr[j] < pivot) {
        //                 i++;
        //                 std::swap(arr[i], arr[j]);
        //             }
        //         }
        //         std::swap(arr[i + 1], arr[high]);
        //         int pivotIndex = i + 1;

        //         quicksortInPlace(arr, low, pivotIndex - 1);
        //         quicksortInPlace(arr, pivotIndex + 1, high);
        //     }
        // }
        // return quicksortInPlace(nums, 0, nums.size())



    }
};
