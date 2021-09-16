def GCD(num1,num2):
    if num1 == 0:
        return num2
    return GCD(num2 - (num2 // num1) * num1, num1)

def solution(w,h):    
    return w * h - (w + h - GCD(max(w,h), min(w,h)))