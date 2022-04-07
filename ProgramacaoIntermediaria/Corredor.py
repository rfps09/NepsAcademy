n = int(input())
vetor = input().split()
sum = -100
ans = -100

for i in range(n):
    v = int(vetor[i])
    if sum+v > v:
        sum += v
    else: sum = v
    if sum > ans: ans = sum

print(ans)