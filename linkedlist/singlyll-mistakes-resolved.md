# ASAN error - memory limit reached as multiple addresses access a Node, bcz of inifinite loop
https://leetcode.com/problems/odd-even-linked-list/submissions/1192478447/
- multiple nodes can point to the same node
- but a single node can point only to one node
- above doesnt work bcz odd values (with starting as head) 1 3 5
- even vals (with starting as evenst) 2 4 5
- the above is not intended but doesnt give error, but when you assign odd->next = even, then nxt of 5 is 2, but 5 is also in even nos, so infinite loop hence error
- reason for 5 to be included curr=curr->next, so 4 points to 5 and that link is never broken
- so you need to change 4 points to null (even->next=NULL)
- CORRECTED https://leetcode.com/problems/odd-even-linked-list/submissions/1192442904/
