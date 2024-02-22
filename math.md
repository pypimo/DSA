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

###
