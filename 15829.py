L = int(input())
r = 31; M = 1234567891
l = input()
sum = 0
i = 0
for c in l:
    n = ord(c)-96
    sum += n*(r**i)
    i+=1
sum %= M
print(sum)