# get index of target in roatated array (non-duplicate)
- either arr[mid], arr[hi] is sorted or arr[lo] to arr[mid]
- find target in the sorted portions and if not in leftover side
```cpp
int search(vector<int>& nums, int target) {
  int n=nums.size(), lo = 0, hi = n-1;
  while (lo<=hi) {
      int mid = lo + (hi-lo)/2;
      if (nums[mid]==target) return mid;
      if (nums[mid]>=nums[lo]) {
          if (target>=nums[lo] && target<nums[mid]) hi=mid-1;
          else lo = mid+1;
      } else {
          if (target>nums[mid] && target<=nums[hi]) lo=mid+1;
          else hi=mid-1;
      }
  }
  return -1;
}
```
