L, C = map(int, input().split())
lis = list(map(str, input().split()))
lis.sort()
a = ['a', 'e', 'i', 'o', 'u']
result = []
cnt = 0

def solve(depth, now):
    cnt = 0
    if depth==L:
        for ai in a:
            if ai in result:
                cnt+=1
        if (cnt < 1 or cnt >L-2):
            return
        
        print(''.join(map(str, result)))
        return
    for i in range(now, C):
        result.append(lis[i])
        solve(depth+1, i+1)
        result.pop()
solve(0, 0)