def solution(brown, yellow):
    total = brown + yellow
    for i in range(3, total):
        if not(total % i):
            j = total // i
            if yellow == (i - 2) * (j - 2):
                return [max(i, j), min(i,j)]