def solution(A,B):
    A = sorted(A, reverse = True)
    B = sorted(B)

    return sum([a*b for a,b in zip(A,B)])