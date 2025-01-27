MOD = 10**9 + 7

def pwr(a, b):
    res = 1
    while b:
        if b & 1:
            res = (res * a) % MOD
        a = (a * a) % MOD
        b //= 2
    return res % MOD

MAX = 2 * 10**5
fct = [1] * (MAX + 1)
inv = [1] * (MAX + 1)

# Precompute factorials and modular inverses
for i in range(1, MAX + 1):
    fct[i] = (fct[i - 1] * i) % MOD

inv[MAX] = pwr(fct[MAX], MOD - 2)  # Modular inverse using Fermat's Little Theorem
for i in range(MAX, 0, -1):
    inv[i - 1] = (i * inv[i]) % MOD

# Compute C(k, n) modulo MOD
def C(k, n):
    if k > n or k < 0:
        return 0
    # Binomial coefficient formula: C(n, k) = n! / (k! * (n - k)!)
    return (fct[n] * inv[k] % MOD) * inv[n - k] % MOD

# Computes C(k, n) modulo MOD using Lucas's theorem in O(log(n)) time
def lucas(k, n):
    if k > n or k < 0:
        return 0
    if k == 0 or k == n:
        return 1
    # Recursive application of Lucas's theorem
    return (lucas(k // MOD, n // MOD) * C(k % MOD, n % MOD)) % MOD
