import math 

n, m, k, l = [int(x) for x in input().split()]
if m > n or l > n:
    print(-1)
    exit(0)

times = ((l + k + m  - 1) // m)

if times * m > n:
    print(-1)
    exit(0)
else:
    print(times)

