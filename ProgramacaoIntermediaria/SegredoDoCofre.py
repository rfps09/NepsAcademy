n,m = input().split()
vetor = input().split()
consultas = input().split()
prefix = [[0,0,0,0,0,0,0,0,0,0]]

for i in range(int(n)):
    j = int(vetor[i])
    lista = prefix[i].copy()
    lista[j]+=1
    prefix.append(lista)

ans = [0,0,0,0,0,0,0,0,0,0]
start = int(consultas[0])-1

for i in range(1,int(m)):
    end = int(consultas[i])
    aux = end
    
    if end < start:
        end-=1
        start-=1
    
    for j in range(10):
        ans[j] += abs(prefix[end][j] - prefix[start][j])
    
    start = aux

for i in range(9):
    print(ans[i], end = " ")
print(ans[9])