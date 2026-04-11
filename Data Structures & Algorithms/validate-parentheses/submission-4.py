class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        close_to_open = {")":"(", "}":"{", "]":"["}
        for l in s:
            if l in close_to_open.keys():
                if stack and stack[-1] == close_to_open[l]:
                    stack.pop()
                else:
                    return False
            else:
                stack.append(l)
                
        return len(stack)==0
        