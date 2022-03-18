r,k = input().split()
r = int(r)
k = int(k)

def solve(opcao,qtd,valor):
    if qtd == 0:
        return valor == 0
    
    ans = 0
    for i in range(opcao+1,valor+1):
        ans += solve(i,qtd-1,valor-i)

    return ans

print(solve(0,k,r))