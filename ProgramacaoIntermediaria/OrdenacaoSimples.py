n = int(input())
vetor = input().split()

for i in range(len(vetor)):
	vetor[i] = int(vetor[i])

def bubbleSort(array):
    for i in range(len(array)):
        for j in range(len(array)- 1):
            if int(array[j]) > int(array[j+1]):
                aux = array[j+1]
                array[j+1] = array[j]
                array[j] = aux
    return array

vetor.sort()

for i in vetor:
    print(i, end=" ")