import sys

input = sys.stdin
T = int(input.readline())
for t in range(T):
    N = int(input.readline())
    SEQ = input.readline()
    temp = 1
    result = "YES"
    for c in SEQ:
        if c == 'U':
            temp += 1
        else:
            temp -= 1
        if temp < 1 or temp > N:
            result = "NO"
            # break
    print(result)
