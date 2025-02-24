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
tt=int(input())
for _ in range(tt):
    #n=int(input())
    n,k=map(int, input().split()) 
    L=[]
    for _ in range(n):
        x,y=map(int,input().split())
        L.append((x,y))
    vrf=0;ans=0;mx=0
    for i in range(n):
        for j in range(n):
            ans=max(ans,abs(L[i][0]-L[j][0])+abs(L[i][1]-L[j][1])) 
            if abs(L[i][0]-L[j][0])>k and abs(L[i][1]-L[j][1])>k:
                vrf=1
     
    if ans>2*k:
        print(-1)
    else:
        print((ans-1)//k)

