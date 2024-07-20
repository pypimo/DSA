#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxN = 2e5+10;
ll a[maxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n,k,l=1;
	double sum=0, avg=0;
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		sum += a[i];
		if (i>k) {
			sum-=a[l];
			l++;
		}
		if (i>=k) avg+=sum;
	}
	avg /= (n-k+1);
	cout << fixed << setprecision(10) << avg << '\n';

	return 0;
}
