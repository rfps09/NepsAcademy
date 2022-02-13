def fatorial(N):
    ans = 1
    for i in range(1,N+1):
        ans *= i
    return ans

N = int(input())
print(fatorial(N))