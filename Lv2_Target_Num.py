def DFS(N, n, k, numbers, target):
    global answer
    if n == N - 1:
        if k == target:
            answer += 1
        return
    
    DFS(N, n + 1, k + numbers[n+1], numbers, target)
    DFS(N, n + 1, k - numbers[n+1], numbers, target)

def solution(numbers, target):
    global answer
    answer = 0
    N = len(numbers)
    
    DFS(N, 0, numbers[0], numbers, target)
    DFS(N, 0, -numbers[0], numbers, target)
    
    return answer

numbers = [1,1,1,1,1]
target = 3
print(solution(numbers, target))