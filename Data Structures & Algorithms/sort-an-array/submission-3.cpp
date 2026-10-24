class Solution {
public:
    void quicksortInPlace(std::vector<int>& arr, int low, int high) {
        if (low < high) {
            // BUG FIX: Randomise pivot selection to prevent O(N²) TLE on sorted inputs
            int pivotIndex = low + rand() % (high - low + 1);
            std::swap(arr[pivotIndex], arr[high]);

            int pivot = arr[high];
            int i = low - 1;
            
            for (int j = low; j < high; j++) {
                if (arr[j] < pivot) {
                    i++;
                    std::swap(arr[i], arr[j]);
                }
            }
            std::swap(arr[i + 1], arr[high]);
            int actualPivotIndex = i + 1;

            quicksortInPlace(arr, low, actualPivotIndex - 1);
            quicksortInPlace(arr, actualPivotIndex + 1, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // // Define quicksort as a recursive lambda function
        // auto quicksort = [&](auto& self, vector<int> arr) -> vector<int> {
        //     if (arr.size() <= 1) {
        //         return arr; // Added missing semicolon
        //     }

        //     int pivot = arr[arr.size() / 2]; // Added missing semicolon

        //     vector<int> left;
        //     vector<int> right;
        //     vector<int> middle;

        //     for (int n : arr) {
        //         if (n < pivot) {
        //             left.push_back(n);
        //         } 
        //         else if (n > pivot) {
        //             right.push_back(n);
        //         }
        //         else {
        //             middle.push_back(n);
        //         }
        //     }

        //     // Optimization: Use std::move to transfer data instead of copying it
        //     vector<int> sorted_left = self(self, move(left));
        //     vector<int> sorted_right = self(self, move(right));

        //     vector<int> res;
        //     res.reserve(arr.size());

        //     // Use move iterators to reassemble without copying elements
        //     res.insert(res.end(), make_move_iterator(sorted_left.begin()), make_move_iterator(sorted_left.end()));
        //     res.insert(res.end(), make_move_iterator(middle.begin()), make_move_iterator(middle.end()));
        //     res.insert(res.end(), make_move_iterator(sorted_right.begin()), make_move_iterator(sorted_right.end()));

        //     return res; // Added missing semicolon
        // };

        // return quicksort(quicksort, move(nums));




        // // Traditional high-performance C++ In-Place Quicksort
        if (nums.empty()) return nums;
        
        // BUG FIX: The final index must be `nums.size() - 1`, not `nums.size()`
        quicksortInPlace(nums, 0, nums.size() - 1);
        
        return nums;

    }
};
