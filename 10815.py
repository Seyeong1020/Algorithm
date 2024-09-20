N = int(input())
s = set(map(int, input().split()))
M = int(input())
checks = list(map(int, input().split()))

print(' '.join('1' if check in s else '0' for check in checks))

