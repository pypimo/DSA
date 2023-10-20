#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve(ll n) {	
	while(n>1) {
		cout << n << " ";	
		if (n%2) n=n*3+1;
		else n/=2;
	}
	cout << n << " ";
}
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	ll n;
	cin >> n;
	solve(n);
	
	return 0; 
}
