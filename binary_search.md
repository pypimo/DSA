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
