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

## binary search
returns true or false
## lower bound
returns index of first values >=target
## upper bound
returns index of first value > target
