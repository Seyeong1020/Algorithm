import sys
N = int(input())

A =list(map(int, sys.stdin.readline().split()))
A.sort()

B =list(map(int, sys.stdin.readline().split()))

result = 0
for i in A:
    result += max(B)*i
    B.remove(max(B))
    #del B[B.index(max(B))]
print(result)