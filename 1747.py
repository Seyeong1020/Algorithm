def is_palindrome(num):
    num = str(num)
    return num == num[::-1]

def is_prime(num):
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return num!=1

n = int(input())

while (1):
    if is_palindrome(n) and is_prime(n):
        print(n)
        break
    n+=1