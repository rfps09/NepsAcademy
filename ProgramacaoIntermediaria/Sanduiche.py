n,d = input().split()
vetor = input().split()
sum = 0; index = 0; ans = 0

for i in range(int(n)):
    while(sum < int(d)):
        sum += int(vetor[index])
        index = index+1 if index < (int(n)-1) else 0
        if index == i: break
    if sum == int(d): ans+=1
    sum -= int(vetor[i])

print(ans)