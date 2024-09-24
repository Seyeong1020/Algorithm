N, K = map(int, input().split())

idx = 0

l = [i for i in range(1, N+1)]
res = []
while l:
    idx += K-1
    if (idx >= len(l)):
        idx %= len(l)
    res.append(str(l.pop(idx)))
print("<", end="")
print(', '.join(res), end="")
print(">")