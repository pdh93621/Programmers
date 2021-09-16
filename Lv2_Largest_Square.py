def solution(board):
    N = len(board)
    M = len(board[0])
    dp = board
    
    for n in range(1,N):
        for m in range(1,M):
            if dp[n][m]:
                dp[n][m] = min(dp[n-1][m], dp[n][m-1], dp[n-1][m-1]) + 1

    return pow(max(map(max,dp)),2)

board = [[0,1,1,1],[1,1,1,1],[1,1,1,1],[0,0,1,0]]
print(solution(board))