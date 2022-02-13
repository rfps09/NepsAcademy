n = int(input())
x = input().split()

for i in range(n):
    x[i] = int(x[i])

x.sort()

for i in x:
    print(i, end=" ")
print()