import sys
import copy
import functools

def cal(abc):
    sum = functools.reduce(lambda x, y: x*y, abc)
    for i, val1 in enumerate(abc):
        for j, val2 in enumerate(abc):
            if i != j and val1 > 1 and val2 % val1 == 0:
                tmp = copy.deepcopy(abc)
                tmp[j] = int(val2/val1)
                sum = cal(tmp)
    return sum

input = sys.stdin
T = int(input.readline())
for t in range(T):
    ABC = [int(abc) for abc in input.readline().split()]
    assert(len(ABC) == 3)
    print(cal(ABC))
