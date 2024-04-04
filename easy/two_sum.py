class Solution:
    def twoSum(self, nums, target):
        dicc = {}
        for i, num in enumerate(nums):
            rest = target - num
            if rest in dicc:
                return [dicc[rest], i]
            dicc[num] = i
        
    
    print(twoSum(0, [-1,-2,-3,-4,-5], -8))