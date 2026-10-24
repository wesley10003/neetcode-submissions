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

        