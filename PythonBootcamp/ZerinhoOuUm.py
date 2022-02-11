a,b,c = input().split()
a = int(a)
b = int(b)
c = int(c)

sum = a+b+c

if sum == 1:
    if a == 1:
        print('A')
    if b == 1:
        print('B')
    if c == 1:
        print('C')
elif sum == 2:
    if a == 0:
        print('A')
    if b == 0:
        print('B')
    if c == 0:
        print('C')
else:
    print('*')