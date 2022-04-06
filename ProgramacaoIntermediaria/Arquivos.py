n,b = input().split()
vetor = input().split()

for i in range(int(n)):
    vetor[i] = int(vetor[i])

vetor.sort() 

ans=0
i=0; j=int(n)-1
while i<j:
    if vetor[i] + vetor[j] > int(b):
        j-=1
        ans+=1
    else:
        i+=1;j-=1
        ans+=1
if i==j and vetor[i] <= int(b):
    print(ans+1)
else: print(ans)