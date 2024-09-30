import sys
N = int(input())
l = sys.stdin.readline().split()
s = set(map(int,l)) #숫자 정렬 하기 위해서
l = list(s)
l.sort()

for i in l:
    print(i, end= " ")