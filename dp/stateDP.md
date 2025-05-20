https://leetcode.com/problems/painting-a-grid-with-three-different-colors
- cell level dp is too naive, because you can't use `sum` or `max` of any combinations without seeing the path history
- the adjacency constraints affect whole rows and columns
