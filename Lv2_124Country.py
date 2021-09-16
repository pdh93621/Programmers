def solution(n):
    answer = ''
    while True:
        k = n % 3
        
        if k == 0:
            k = 3
            answer = str(4) + answer
        else:
            answer = str(k) + answer

        if n < 4:
            break
        
        n = (n - k) // 3
        
    return answer

print(solution(27))