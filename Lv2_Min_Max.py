def solution(s):
    integers = list(map(int, s.split()))
    return " ".join([str(min(integers)), str(max(integers))])

s = "-1 -2 -3 -4"
print(solution(s))