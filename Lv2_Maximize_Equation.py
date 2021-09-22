from itertools import permutations
from collections import deque

def exp2equ(expression, operations):
    expression += '+'
    temp = ''
    equation = []
    for e in expression:
        if e in operations:
            equation.append(int(temp))
            equation.append(e)
            temp = ''
        else:
            temp += e
    return deque(equation[:-1])

def calculate(num1, num2, ope):
    if ope == '+':
        return num1 + num2
    elif ope == '-':
        return num1 - num2
    else:
        return num1 * num2

def get_result(equation, permute):  
    equ = equation.copy()
    temp = deque([])
    for ope in permute:
        while equ:
            x = equ.popleft()
            if x == ope:
                #print(x)
                temp[-1] = calculate(temp[-1], equ.popleft(), ope)
            else:
                temp.append(x)
        equ = temp.copy()
        #print(equation)
        temp = deque([])
    #print(equation)
    return abs(equ[0])

def solution(expression):
    operations = ['+', '-', '*']
    equation = exp2equ(expression, operations)
    #print(equation)

    permutes = list(permutations(operations))
    #print(permutes)
    answer = 0
    for permute in permutes:
        answer = max(answer, get_result(equation, permute))
    return answer

expression  = "100-200*300-500+20"
print(solution(expression))