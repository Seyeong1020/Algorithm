import sys
n = int(input())

queue = []

for _ in range(n):
    s = sys.stdin.readline().split()
    if s[0]=="push":
        queue.insert(0, s[1])
    if s[0]=="pop":
        if (len(queue)>0): print(queue.pop())
        else: print(-1)
    if s[0]=="size":
        print(len(queue))
    if s[0]=="empty":
        if (len(queue)>0): print(0)
        else: print(1)
    if s[0]=="front":
        if (len(queue)>0): print(queue[-1])
        else: print(-1)
    if s[0]=="back":
        if (len(queue)>0): print(queue[0])
        else: print(-1)