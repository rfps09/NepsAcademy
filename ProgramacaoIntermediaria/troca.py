n,t =  input().split()
up = input().split()
down = input().split()
ans = [0]*int(1e5+1)

class teste:
    def __init__(x,y,self):
        self.cima = x
        self.baixo = y

for k in range(int(t)):
    i,j = input().split()
    i = int(i)
    j = int(j)
    ans[i-1] += 1
    ans[j] -= 1

for i in range(1,int(n)):
    ans[i] += ans[i-1]

for i in range(int(n)-1):
    if ans[i] % 2:
        print(down[i], end=" ")
    else:
        print(up[i], end=" ")
if ans[i+1] % 2:
    print(down[i+1])
else:
    print(up[i+1])