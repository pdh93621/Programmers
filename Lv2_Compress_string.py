def solution(s):
    s += '+'
    len_s = len(s)
    result = 10000
    for n in range(1, len_s // 2 + 1):
        temp_seq = s[:n]
        temp_num = 1
        temp_result = ''
        for m in range(1, len_s // n + 1):
            try:
                temp = s[n * m: n * (m + 1)]
            except:
                temp = s[n * m: -1]
            #print(temp)
            if temp_seq == temp:
                temp_num += 1
            else:
                if temp_num == 1:
                    temp_result += temp_seq
                else:
                    temp_result += str(temp_num) + temp_seq
                    temp_num = 1
                temp_seq = temp
        temp_result += temp_seq
        #print(temp_result)    
        result = min(result, len(temp_result))     
        
    return result - 1

s = "abcabcdede"
print(solution(s))

