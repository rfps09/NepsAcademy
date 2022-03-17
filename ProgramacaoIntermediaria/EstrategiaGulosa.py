from math import floor

v = int(input())
s = [100,50,25,10,5,1]
ans = 0

for i in s:
    chao = floor(v/i)
    if chao > 0:
        v -= chao*i
        ans += chao

print(ans)