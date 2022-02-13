def eh_primo(x):
    for i in range(2,x):
        if x%i == 0:
            return False
    if x > 1: return True
    return False

x = int(input())

if eh_primo(x):
    print('S')
else:
    print('N')