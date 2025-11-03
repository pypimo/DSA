## binary search
```cpp
    int lo=0, hi=n-1;
    while(lo<=hi) {
        int mid = lo+(hi-lo)/2;
        if (target==arr[mid]) return mid;
        else if (target>arr[mid]) hi=mid-1;
        else lo=mid+1;
    }
    return -1;
```
## lower bound 
if all elemets strictly smaller return index n
```cpp
while (low <= high) {
        int mid = low+(high-low)/2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
}
```
## upper bound
if not prsent returns index n
```cpp
while (low <= high) {
        int mid = low+(high-low)/2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
}
```
## C++ STL
- binary search -> returns true or false
- lower bound -> returns pointer index to first values >=target
- upper bound -> returns pointer index of first value > target

```upper_bound(arr.begin(), arr.end(), target)-arr.begin();```
## single element in sorted array
https://leetcode.com/problems/single-element-in-a-sorted-array/
- sometimes look at mid and see if there are properties in the index that can be used
## peak element
```cpp
int findPeakElement(vector<int>& nums) {
    int n = nums.size(), lo=0,hi=n-1;
    while(lo<=hi) {
        int mid = lo + (hi-lo)/2, curr=nums[mid],prev=INT_MIN,nxt=INT_MIN; 

        if (mid-1>=0) prev = nums[mid-1];
        if (mid+1<n) nxt = nums[mid+1];

        if (prev<curr && nxt<curr) return mid;
        if (prev>curr) {
            hi = mid-1;
        } else lo=mid+1;
    }
    return 0;
}
```
