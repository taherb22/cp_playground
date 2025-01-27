from bisect import bisect_left as bl
from bisect import bisect_right as br
from math import inf, log2, ceil, sqrt, gcd
from collections import defaultdict, deque, Counter
from itertools import combinations
from heapq import heappop,heappush,heapify
import os
import sys
from io import BytesIO, IOBase
 
BUFSIZE = 8192
 
 
class FastIO(IOBase):
    newlines = 0
 
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
 
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
 
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
 
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
 
 
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
#print(f"{x:.9f}")
#dy=[1,-1,1,-1]
#dx=[1,1,-1,-1]
#%
tt=1
#tt=int(input())
for _ in range(tt):
    #n=int(input())
    n,m,k=map(int, input().split())   
    x,s=map(int, input().split())   
    a= list(map(int,input().split()))
    b= list(map(int,input().split())) 
    c= list(map(int,input().split())) 
    d= list(map(int,input().split()))
    #s=input().strip() 
    L=[(b[i],a[i]) for i in range(m)]
    L.sort()
    for i in range(m):
        b[i]=L[i][0]
        a[i]=L[i][1]
    mn1=n*x 
    prf_min=[a[0]]*m
    prf_max=[c[0]]*k
    for i in range(1,m):
        prf_min[i]=min(prf_min[i-1],a[i])
    for i in range(1,k):
        prf_max[i]=max(prf_max[i-1],c[i])
    for i in range(k):
        if d[i]>s:
            break
        j=br(b,s-d[i])
        if j==0:
            mn1=min(mn1,(n-c[i])*x)
            continue 
        mn1=min(mn1,prf_min[j-1]*(n-c[i]))
    mn2=n*x    
    for i in range(m):
        if b[i]>s:
            break
        j=br(d,s-b[i])
        if j==0:
            mn2=min(mn2,n*a[i])
            continue 
        mn2=min(mn2,a[i]*(n-prf_max[j-1]))
    print(min(mn1,mn2))
        