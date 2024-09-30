import sys
def vps(s):
    l = []
    for i in s:
        if i=='(':
            l.append(i)
        if i==')':
            if (len(l)==0):
                return 0
            else:
                l.pop()
    if (len(l)!=0):
        return 0
    else:
        return 1


T = int(input())
for _ in range(T):
    s = sys.stdin.readline()
    if (vps(s)):
        print("YES")
    else:
        print("NO")

