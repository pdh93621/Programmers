from collections import deque

def solution(number, k):
    
    number = deque(list(number))
    
    answer = ['0']
    
    while k:
        for _ in range(k):
            big = number.popleft()
            #print(temp)
            if big > answer[-1]:
                answer[-1] = big
                k -= 1
            else:
                
                break
        #print(answer)
    answer = "".join(answer + list(number))
    return answer

number = "1231234"
k = 3
print(solution(number, k + 1))