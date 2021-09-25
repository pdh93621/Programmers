def solution(number, k):
    
    answer = [number[0]]
    
    for num in number[1:]:
        while answer and answer[-1] < num and k:
            answer.pop()
            k -= 1
        answer.append(num)
    if k:
        answer = answer[:-k]
    
    return "".join(answer)