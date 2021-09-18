def solution(s):
    seq = s + '+'
    stack = ['+']
    for i in seq:
        if stack[-1] == i:
            stack.pop()
        else:
            stack.append(i)
    
    return int(stack == [])

s = 'baabaa'
print(solution(s))