import random
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def quicksort(arr):
            if len(arr) <= 1:
                return arr

            pivot = arr[len(arr) // 2]

            left = []
            right = []
            middle = []

            for i in range(len(arr)):
                if arr[i] < pivot:
                    left.append(arr[i])
                elif arr[i] > pivot:
                    right.append(arr[i])
                else:
                    middle.append(arr[i])
            
            return quicksort(left) + middle + quicksort(right)
        
        return quicksort(nums)



        def quicksort_in_place(low: int, high: int):
            if low < high:
                # 1. Randomise pivot selection to prevent O(N²) worst-case
                pivot_idx = random.randint(low, high)
                nums[pivot_idx], nums[high] = nums[high], nums[pivot_idx]
                
                # 2. Partition using Lomuto's scheme
                pivot = nums[high]
                i = low - 1
                
                for j in range(low, high):
                    if nums[j] < pivot:
                        i += 1
                        nums[i], nums[j] = nums[j], nums[i]
                
                # Place pivot in its correct sorted position
                nums[i + 1], nums[high] = nums[high], nums[i + 1]
                actual_pivot_idx = i + 1
                
                # 3. Recursively sort left and right partitions
                quicksort_in_place(low, actual_pivot_idx - 1)
                quicksort_in_place(actual_pivot_idx + 1, high)

        if not nums:
            return nums
            
        quicksort_in_place(0, len(nums) - 1)
        return nums

            

        