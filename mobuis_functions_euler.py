MAX=10**6+1 
mob=[1]*MAX 
for i in range(2,MAX):
    for j in range(2*i,MAX,i):
        mob[j]-=mob[i]

phi=[i-1 for i in range(MAX)] 
phi[0]=0;phi[1]=1 
for i in range(2,MAX):
    for j in range(2*i,MAX,i):
        phi[j]-=phi[i]
    
    