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
