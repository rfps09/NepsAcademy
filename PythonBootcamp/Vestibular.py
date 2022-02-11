n = int(input())
gabarito = input()
candidato = input()
acertos = 0

for i in range(n):
    if gabarito[i] == candidato[i]:
        acertos+=1

print(acertos)