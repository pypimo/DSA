## gcd `cout << gcd(x,y)`
### brute force
```
for (int i = 1; i <= min(num1, num2); i++) {
	if (num1 % i == 0 && num2 % i == 0) {
		ans = i;
	}
}
```
- Time Complexity: O(N)
- Space Complexity: O(1)
### euclid's theorem (WHY??)
```
int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b,a%b); 
} 
```
## modular arithmetic
- if negative numbers
- eg: -27%10 calculate 27%10=7
- then do 10-7=3

- eg2 : -7%11 = 11-7=4

## parity = odd or even

## getting upper float
- when dividing x by y
- add (y-1) to x
- so `(x+(y-1))/y` gives upper bound

## product of i,j divisible by k
- i*j%k==0 same as
- `gcd(i,k) * gcd(j,k) % k == 0`
- or precompute mod of nums[i] and nums[j] and check `(mod_values[i] * mod_values[j]) % k == 0`, if range of nums is low this helps and 
