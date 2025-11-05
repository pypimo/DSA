## binary search on answers

https://leetcode.com/problems/koko-eating-bananas/description/

https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/

- greedy doesnt always work at times and we need to perform a search on the complete ansewr range
- binary search comes in handy here

## changing the ques to fit to binary search
https://takeuforward.org/data-structure/aggressive-cows-detailed-solution/
```cpp
int aggressiveCows(vector<int> &nums, int k)
{
   int lo=1, hi=1e9, n=nums.size(), ans=-1;
      sort(nums.begin(), nums.end());
      while(lo<=hi) {
          int mid = lo + (hi-lo)/2, prev=nums[0], ct=1;
          for (int i=1; i<n; i++) {
              if (prev+mid>nums[i]) continue;
              ct++; prev=nums[i];
          }
          if (ct>=k) {
              ans = mid;
              lo=mid+1;
          } else hi=mid-1;
      } 
      return ans;
}
```
https://leetcode.com/problems/split-array-largest-sum/description/

## mid+1 and -1 are not the only numbers
https://takeuforward.org/arrays/minimise-maximum-distance-between-gas-stations/
```cpp
#include<bits/stdc++.h>
double minimiseMaxDistance(vector<int> &arr, int k){
	int n=arr.size();
	double lo = 0, hi=1e9, ans=-1;
	while(lo<=hi) {
		double mid = lo+(hi-lo)/2;
		int ct=0;
		for (int i=1; i<n; i++) {
			ct += ceil((arr[i]-arr[i-1])/mid)-1;
		}
		//cout << mid << " " << ct << '\n';
		if (ct<=k) {
			ans = mid;
			hi=mid-1e-6;
		} else lo = mid+1e-6;
	}
	//cout << ans << "ANS ";
	return ans;
}
```
## setting lo and hi
- sometimes you dont need lo to be 1 and hi to be the max possible int
- you can do some optimisation and lo = max(arr) and hi = sum(arr)
