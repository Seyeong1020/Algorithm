import sys
n = int(input())

stack = []

for _ in range(n):
    s = sys.stdin.readline().split()
    if s[0] == "push":
        stack.append(s[1])
    if s[0] == 'pop':
        if (len(stack) > 0): print(stack.pop())
        else: print(-1)
    if s[0] == 'size':
        print(len(stack))
    if s[0] == 'empty':
        if (len(stack) > 0): print(0)
        else: print(1)
    if s[0] == 'top':
        if(len(stack)>0): print(stack[-1])
        else: print(-1)