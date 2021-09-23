def solution(arr1, arr2):
    
    answer = [[sum([arr1[n][m] * arr2[m][k] for m in range(len(arr1[0]))]) for k in range(len(arr2[0]))] for n in range(len(arr1))]            

    return answer