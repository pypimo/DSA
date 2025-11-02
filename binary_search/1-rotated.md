# index of target in roatated array
## (non-duplicate)
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
## duplicates 
- lo++ when arr[lo]=arr[mid]
- to get index just check if arr[hi] is target or else arr[lo] or else arr[mid] (if first occuring index needed in actual sorted array)
- LOGIC: 
- sitation where arr[mid]=arr[lo]=arr[hi] and any part of array can be sorted occurs
- eg: 4  4-4  4  0-1  4
- eg: 4  5-6  4  4-4  4
- by looking at arr[mid] and arr[lo] assuming one part is sorted doesnt work since target < arr[mid] && target < arr[lo] doesnt make sense

```cpp
  if (num[mid]==target) return true;
  if (nums[mid]==nums[lo]) {
      lo++;
      continue;
  }
  if (nums[mid]>nums[lo]) {
      if (target>=nums[lo] && target<nums[mid]) hi=mid-1;
      else lo = mid+1;
  } else {
      if (target>nums[mid] && target<=nums[hi]) lo=mid+1;
      else hi=mid-1;
  }
```
# min
```cpp
int findMin(vector<int>& nums) {
    int n = nums.size(), l=0, r=n-1, k=-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if (nums[mid]<=nums[0] && nums[mid]<=nums[n-1]) {
            k=nums[mid];
            r=mid-1;
        } else {
            l=mid+1;
        }
    }
    return k==-1 ? nums[0] : k;  
}
```
