def n_divided(num, prime):
    n = 0
    while not (num % prime):
        num = num // prime 
        n += 1
    return n

def solution(arr):
    div_dict = {}
    num_primes = max(arr)
    primes = [True for _ in range(num_primes + 1)]
    for prime in range(2, num_primes + 1):
        if primes[prime]:
            temp = 0
            for num in arr:
                temp = max(temp, n_divided(num, prime))
            if temp:
                div_dict[prime] = temp 

            for i in range(2, num_primes // prime + 1):
                primes[prime * i] = False
    
    result = 1
    for p in div_dict:
        result *= (p ** div_dict[p])
    #print(div_dict)

    return result

#print(solution([2,6,8,14]))