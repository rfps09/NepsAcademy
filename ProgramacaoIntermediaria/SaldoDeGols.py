n = int(input())
count = 1

while n != 0:
    sum = 0
    left = -1
    right = -1
    print(f"Teste {count}")
    for i in range(1,n+1):
        x,y = input().split()
        x = int(x); y = int(y)
        saldo = x-y
        if(saldo > sum): 
            sum = saldo
            left = i
            right = i
        elif(saldo+sum >= sum):
            sum += saldo
            right = i
    if(left == -1): print("nenhum")
    else: print(f"{left} {right}")
    n = int(input())
    count+=1