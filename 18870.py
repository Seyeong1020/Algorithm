N = int(input())
l = list(map(int, input().split()))
a = []
for i in range(len(l)):
    a.append([i, l[i]])
a.sort(key=lambda x:x[1])
result = [0]*N

f = a[0][1]
i = 0
for elem in a:
    if (elem[1]==f):
        result[elem[0]]+=i
    else:
        i+=1
        result[elem[0]]+=i
    f = elem[1]
print(' '.join(map(str,result)))