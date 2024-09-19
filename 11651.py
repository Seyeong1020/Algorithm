N = int(input())

a = []
for _ in range(N):
    p = list(map(int, input().split()))
    a.append(p)
a.sort(key=lambda x: (x[1], x[0]))

for i in a:
    print(f"{i[0]} {i[1]}")
    