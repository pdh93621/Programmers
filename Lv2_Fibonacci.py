def solution(n):
    dp = [0 for _ in range(n + 1)]
    dp[1] = 1
    
    i = 2
    while i <= n:
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567
        i += 1
        
    answer = dp[n]
    
    return answer

print(solution(3))