n,m = input().split()
vetorN = input().split()
pontuacoes = input().split()
forcas = input().split()

for i in forcas:
    l=0
    r=len(vetorN)

    search = int(i)
    
    ans=0

    while l<r:
        mid = (l+r)//2
        if search >= int(vetorN[mid]):
            ans = mid+1
            l = ans
        else:
            ans = mid
            r = mid

    print(pontuacoes[ans], end = " ")