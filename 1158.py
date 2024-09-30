N, K = map(int, input().split())
l = [i+1 for i in range(N)]
q = []
index = K-1
while(len(l)):
    if (index >= len(l)):
        index = index % len(l)
    q.append(l[index])
    l.remove(l[index])
    index += K-1
print('<', end="")
print(', '.join(str(s) for s in q), end="")
print('>', end="")
    