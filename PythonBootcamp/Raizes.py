import math

n = int(input())
x = input().split()

for i in range(n):
    print("{:.4f}".format(math.sqrt(float(x[i]))))