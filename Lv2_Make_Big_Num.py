def solution(number, k):
    
    answer = ""
    while True:
        
        temp = number.index(max(number[:k+1]))
        k -= temp
        answer += number[temp]
        if not k:
            if temp < len(number):
                answer += number[temp + 1:]
            break    
        number = number[temp + 1:]    
    return answer

number = "1231234"
k = 3

print(solution(number, k))