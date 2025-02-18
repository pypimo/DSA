## Moore's voting algo
https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
- why lo and hi doesnt work
- eg: `1 2 1` or `1 0 1` so if you increase lo at default (prob) or hi at default (prob)
```cpp
  int n=nums.size(), lo=0, hi=n-1;
  while (lo<hi) {
      if (nums[lo]>nums[hi]) swap(nums[lo], nums[hi]); 
      if (nums[hi]==2) hi--;
      else if (nums[lo]==0) lo++;
      else hi--;
  }
```
## dutch national flag 
https://leetcode.com/problems/sort-colors/solutions/3464652/beats-100-c-java-python-javascript-two-pointer-dutch-national-flag-algorithm/
```cpp
  int n=arr.size(), lo=0, hi=n-1, mid=0;
    while(mid<=hi) {
        if (arr[mid]==1) mid++;
        else if (arr[mid]==2) {
            swap(arr[mid], arr[hi]);
            hi--;
        } else { // arr[mid]==0
            swap(arr[lo], arr[mid]);
            lo++;
            mid++;
        }
    }
```

## two pointer algo
https://www.geeksforgeeks.org/two-pointers-technique/

## sliding window
https://www.geeksforgeeks.org/window-sliding-technique/
