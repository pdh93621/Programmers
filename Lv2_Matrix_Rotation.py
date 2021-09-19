def rotation(matrix, query):
    x1, y1, x2, y2 = [coord - 1 for coord in query]
    
    coord_list = [[x1, y1 + i] for i in range(y2 - y1)] + [[x1 + i, y2] for i in range(x2 - x1)] \
                    + [[x2, y2 - i] for i in range(y2 - y1)] + [[x2 - i, y1] for i in range(x2 - x1)] \
                    + [[x1,y1]]
        
    coord_num = len(coord_list)
    
    before = matrix[x1][y1]
    result = before
    for num in range(1, coord_num):
        next_x, next_y = coord_list[num]
        current = matrix[next_x][next_y]
        matrix[next_x][next_y] = before
        if result > current:
            result = current
        before = current
    
    #print(matrix)
    return matrix, result
        
        
def solution(rows, columns, queries):
    
    matrix = [[columns * r + c + 1 for c in range(columns)] for r in range(rows)]
    answer = []
    #print(matrix)
    
    for q in queries:
        matrix, result = rotation(matrix, q)
        answer.append(result)
    
    return answer

rows = 3
columns = 3
queries = [[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]

print(solution(rows, columns, queries))