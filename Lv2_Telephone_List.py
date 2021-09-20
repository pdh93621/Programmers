def solution(phone_book):
    
    phone_book = sorted(phone_book)
    
    for i in range(len(phone_book) - 1):
        temp_num1 = len(phone_book[i])
        temp_num2 = len(phone_book[i + 1])
        if temp_num1 <= temp_num2:
            if phone_book[i + 1][ : temp_num1] == phone_book[i]:
                return False
    
    return True