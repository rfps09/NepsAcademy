n = int(input())
vetor = []

for i in range(n):
    aux = int(input())
    vetor.append(aux)

k = int(input())

i = 0; j = n-1
while i != j:
    if vetor[i] + vetor[j] == k: 
        print(f"{vetor[i]} {vetor[j]}")
        break
    elif vetor[i] + vetor[j] > k:
        j-=1
    else:
        i+=1
