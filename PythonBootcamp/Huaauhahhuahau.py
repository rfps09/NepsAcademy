s = input()
str = ""
ans = True

for i in range(len(s)):
    if s[i] in ('a','e','i','o','u'):
        str+= s[i]

for i in range(int(len(str)/2)):
    if str[i] != str[(i+1)*-1]:
        ans = False

if ans == True:
    print("S")
else:
    print("N")