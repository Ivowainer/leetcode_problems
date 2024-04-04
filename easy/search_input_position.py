class Solution:
    def searchInsert(self, nums, target):
        half = len(nums) // 2
        start = 0
        end = len(nums) - 1

        while start <= end and nums[half] != target:
            if nums[half] < target:
                start = half + 1
            else:
                end = half - 1

            half = (start + end) // 2

        if nums[half] != target:
            nums.insert(half + 1, target)
            return half+1
            
        return half

        
    
    print(searchInsert(0, [1,3,5,6], 2))