N = int(input())
size = list(map(int, input().split()))
T, P = map(int, input().split())

tshirt = 0
for s in size:
    if s%T == 0:
        tshirt += s//T
    else:
        tshirt += s//T + 1
pen = N//P
pen1 = N%P

print(tshirt)
print(pen, pen1)