- binary rep of 9 = 1001 (rightmost bit is least sig)

## odd vs even
LSB = 1 -> odd
LSB = 0 -> even
```
if (x&1) return odd;
else return even;
```

## xor(^)

```
1 ^ 1 = 0
1 ^ 0 = 1
0 ^ 1 = 1
0 ^ 0 = 0
```
```
n ^ 0 = n
x ^ y = x^ y
x^x=0
```

## power of 2
binary rep of 8 = 1000 <br>
binary rep of 7 = 0111 <br>
if x is power of 2 <br>
```x & (x-1) = 0``` 

## kth bit - lsb (kth bit from right)
1. check if kth bit is set `x & (1<<k)`
2. toggle kth bit `x ^ (1<<k)`
3. set kth bit `x | (1<<k)`
4. unset kth bit `x & ~(1<<k)`

## multiply/divide by 2 raised to k
```
x << k // mutliple
x >> k // divide
```

## swapping numbers x,y
1. temp var
```
z = x 
x = y
y = z
```
2. without xtra var
```
a = a+b
b = a-b
a = a-b
```
3. using xor
```
x = x^y
y = x^y
x = x^y
```

## obv: set bits
```
setbits in A = X
setbits in B = Y
setbits in A^B = Z
if X+Y is odd, Z is odd
if X+Y is even, Z is even
```
reason: if xor had no chnage then z = x+y, but if even one setbit was same, loss of 2 setbits in z

## X = X^A^B
```
// a different way to write instead of
if (X==B) X=A;
else if (X==A) X=B;
```

## A+B
```
A+B = (A^B) + 2(A&B)
A+B = (A|B) + (A&B)
```
## counting setbits
```
__builtin_popcount(x); //for int
__builtin_popcountll(x); //for long long
```

## bit rep
```
bitset<64> x(num);
bitset<32> x(num);
cout << x;
```
storing the bit repersntation for `num` in `x`

## for raising a to power b and moding with mod
```cpp
ll binexp(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}
```
