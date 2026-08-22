## Boyer-Moore voting algo
https://www.geeksforgeeks.org/boyer-moore-majority-voting-algorithm/
majority element in n-size array ie frequency >= n/2
* method1: sort and see the mid element - nlogn
* moore's algo or keep vars candidate and counter, incremenet counter if same ele found, else decrement. If counter is 0, change the current ->  O(n) - 2passes needed if majority isnt guaranteed:
  * because {1,2,3} 3 will be the ans but its not majority
  * if even length {1,2,3,4,7,7} - 7 is the ans but its not majority
* Ques find elements with freq >= n/3
  * https://leetcode.com/problems/majority-element-ii/solutions/63520/Boyer-Moore-Majority-Vote-algorithm-and-my-elaboration
  * keep 2 candidates and counters, increment respective counter on match, but on no match with any decremenet both counters:
  * reason: if we only subtract with one, we can end up decrementing one majority candidate, that would still have a counter, so we wouldn't update candidate, but the second candidate could have been decremented to 0 and changed (one trick can be to subtract from the min counter) for eg {1,1,1,1,3,2,2,2,2} -> if we were to just subtract from one candidate1 = 1, then candidate1 = 1, candidate2=3 and by the end counter would be 0, but 2 wasn't even a candidate
## dutch national flag 
https://leetcode.com/problems/sort-colors/solutions/3464652/beats-100-c-java-python-javascript-two-pointer-dutch-national-flag-algorithm/
* my initial approach - wrong
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
Solution
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

## Two pointer algo
https://www.geeksforgeeks.org/two-pointers-technique/

## Sliding window
https://www.geeksforgeeks.org/window-sliding-technique/
