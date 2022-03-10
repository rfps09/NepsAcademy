pai = [0]
tam = [0]
ans = ['N','S']

n,k = input().split()

for i in range(int(n)):
    pai.append(i+1)
    tam.append(1)

def find(x):
    if pai[x] == x: 
        return x
    pai[x] = find(pai[x])
    return pai[x]

def join(x,y):
    x = find(x)
    y = find(y)

    if(not x^y): return

    if tam[x] > tam[y]:
        pai[y] = x
        tam[x] += tam[y]
    else:
        pai[x] = y
        tam[y] += tam[x]

for i in range(int(k)):
    z,x,y = input().split()

    if z == 'C':
        print(ans[find(int(x))==find(int(y))])
    else: join(int(x), int(y))