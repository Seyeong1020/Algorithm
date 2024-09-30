n = int(input())
num = [j for j in range(n, 0, -1)]
s = []
for _ in range(n):
    s.append(int(input()))

stack = []
i=0
l=[]
r = []

while (len(r)!=n):
    if (len(stack)==0 or stack[-1]!= s[i]):
        if (len(num)==0):
            break
        stack.append(num.pop())
        l.append('+')
    elif (stack[-1]==s[i]):
        r.append(stack.pop())
        l.append('-')
        i+=1
if (len(stack)==0):
    for p in l:
        print(p)
else:
    print("NO")

    