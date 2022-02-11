n = int(input())
ans = 0
sum = 0
for i in range(n):
    sum += int(input())
    if sum < 1000000:
        ans = i+1

print(ans+1)