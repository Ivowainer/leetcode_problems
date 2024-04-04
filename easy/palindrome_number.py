class Solution:
    def isPalindrome(self, x) -> bool:
        x = str(x)
        end = len(x)

        for i in range(0, end):
            if(x[i] != x[-i-1]):
                return False
        
        return True
    
    print(isPalindrome(0, 22255222))