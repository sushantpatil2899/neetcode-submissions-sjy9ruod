class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for l in s:
            if l in ('(','{','['):
                stack.append(l)
            else:
                last_ele = ''
                if stack:
                    last_ele = stack.pop()
                if last_ele == '':
                    stack.append(l)
                elif l == ')':
                    if last_ele!='' and last_ele!='(':
                        stack.append(last_ele)
                        stack.append(l)
                elif l == '}':
                    if last_ele!='' and last_ele!='{':
                        stack.append(last_ele)
                        stack.append(l)
                elif l == ']':
                    if last_ele!='' and last_ele!='[':
                        stack.append(last_ele)
                        stack.append(l)
        return len(stack)==0
        