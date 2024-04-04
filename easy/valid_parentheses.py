class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        opn = ['(', '[', '{']
        close = [')', ']', '}']

        for character in s:
            if character in opn:
                stack.append(character)
            elif character in close:
                if len(stack) == 0 or close.index(character) != opn.index(stack.pop()):
                    return False
                    
        return len(stack) == 0

        
    print(isValid(0, "{[([])]}"))
