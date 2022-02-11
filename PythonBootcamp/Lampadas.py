n = int(input())
x = input().split()
a = 0
b = 0

for i in range(n):
    if x[i] == '1':
        a+=1
    else: 
        a+=1
        b+=1

print(a%2)
print(b%2)