def next_location(grid, current):
    n, m, indir = current

    dir = grid[n][m]
    if dir == 'S':
        if indir == 0:
            return [n, m + 1, 0]
        elif indir == 1:
            return [n + 1, m, 1]
        elif indir == 2:
            return [n, m - 1, 2]
        elif indir == 3:
            return [n - 1, m, 3]

    elif dir == 'L':
        if indir == 0:
            return [n - 1, m, 3]
        elif indir == 1:
            return [n, m + 1, 0]
        elif indir == 2:
            return [n + 1, m, 1]
        elif indir == 3:
            return [n, m - 1, 2]
    
    elif dir == 'R':
        if indir == 0:
            return [n + 1, m, 1]
        elif indir == 1:
            return [n, m - 1, 2]
        elif indir == 2:
            return [n - 1, m, 3]
        elif indir == 3:
            return [n, m + 1, 0]

def solution(grid):
    N = len(grid)
    M = len(grid[0])

    all_root = [[[0] * 4 for _ in range(M)] for _ in range(N)]
    
    result = []

    for n in range(N):
        for m in range(M):
            for k in range(4):
                if not all_root[n][m][k]:
                    current = [n, m, k]
    
                    temp = 0
                    

                    while True:

                        current = next_location(grid, current)
                        
                        if current[0] < 0:
                            current[0] = N - 1
                        elif current[0] >= N:
                            current[0] = 0
                        if current[1] < 0:
                            current[1] = M - 1
                        elif current[1] >= M:
                            current[1] = 0
                        
                        #print(current, temp)
                        if all_root[current[0]][current[1]][current[2]]:
                            #print(all_root)
                            result.append(temp)
                            temp = 1
                            break    
                        else:
                            all_root[current[0]][current[1]][current[2]] = 1

                        temp += 1
    return sorted(result)

grid = ["RSR","SLS"]

print(solution(grid))