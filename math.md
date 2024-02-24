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
