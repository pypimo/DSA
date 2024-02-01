# Implmenting
## binary search
```
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
```
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
```
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
## binary search
returns true or false
## lower bound
returns index of first values >=target
## upper bound
returns index of first value > target
