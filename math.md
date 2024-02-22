binary rep of 9 = 1001
c (rightmost bit is least sig)

## odd vs even
LSB = 1 -> odd
LSB = 0 -> even
```
if (x&1) return odd;
else return even;
```

## xor(^)
```
n ^ 0 = n
x ^ y = x^ y
x^x=0
```

## power of 2
binary rep of 10 = 1010
binary rep of 8 = 1000
```
x & (x-1) -> 0 then x is power of 2
else no
```

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
