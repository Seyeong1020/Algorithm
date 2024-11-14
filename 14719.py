h, w = map(int, input().split())
block = list(map(int, input().split()))

result = 0

for i in range(1, w-1):
    left = max(block[:i])
    right = max(block[i+1:])
    m = min(left, right)
    if (m > block[i]):
        result += m- block[i]

print(result)