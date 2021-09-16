import math

def solution(progresses, speeds):
    complete = [math.ceil((100 - p[0]) / p[1]) for p in list(zip(progresses, speeds))]
    complete.append(1000)
    answer = []
    result = 1
    temp = complete[0]
    for c in complete[1:]:
        if temp < c:
            temp = c
            answer.append(result)
            result = 1
        else:
            result += 1
    
    return answer
   

progresses = [93,30,55]
speeds = [1,30,5]
print(solution(progresses, speeds))