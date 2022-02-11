a, b = input().split()
a = float(a)
b = float(b)
media = (a+b)/2;

if media < 4:
    print('Reprovado')
elif media < 7:
    print('Recuperacao')
else:
    print('Aprovado')