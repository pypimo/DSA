What is collision & How the hashing works:
Hashing is done using several methods. Among them, the three most common ones are

Division method
Folding method
Mid-Square method

Note: In the map data structure, the data type of key can be anything like int, double, pair<int, int>, etc.
But for unordered_map the data type is limited to integer, double, string, etc. We cannot have an unordered_map whose key is pair<int, int>.

## Map alternatives
- frequency array
- word matrix eg: for sotring 2 letter words and findign there reverese in map, use int freg[26][26] = {0} // now you can find in O(1)
