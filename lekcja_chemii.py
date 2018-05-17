import sys

input = sys.stdin
T = int(input.readline())
for t in range(T):
    N = int(input.readline())
    Ns = [[int(mz) for mz in input.readline().split()] for n in range(N)]
    print("{}".format(Ns.index(max(Ns, key=lambda mz : mz[0] * mz[1])) + 1))
