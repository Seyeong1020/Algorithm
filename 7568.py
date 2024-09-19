N = int(input())
l = []
for _ in range(N):
     a = list(map(int, input().split()))
     l.append(a)

for i in l:
    grade = 1
    for j in l:
        if (i[0] < j[0]) & (i[1] < j[1]):
            grade += 1
    print(grade, end=" ")
    