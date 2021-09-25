def solution(s):

    s = ' '.join(map(lambda s: s[0].upper() + s[1:].lower() if s else s, s.split(' ')))

    return s

s = "3people unFollowed me"

print(solution(s))