import collections

N = int(input())
l = list(map(int, input().split()))
l.sort()
dict_l = collections.Counter(l)

M = int(input())
checks = list(map(int, input().split()))
print(' '.join(f"{dict_l[check]}" for check in checks))




