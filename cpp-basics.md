## tricks to increase code speed
- use `ios::sync_with_stdio(0); cin.tie(0)` in class function or main func
- use `for (auto x : nums )` rather than `for (int i=0; i<nums.size(); i++)`
## libraries (use #include)
- iostream (input/output)
- math.h
- string

## using namespace std;
- without this, use `std::cout << "HELLO";`
- writing this, std is used for all functions

## <bits/stdc++.h>
includes all the libraries in c++

## comments //

## data types
- int -1e9 to 1e9
- long -1e12 to 1e12
- long long -1e18 to 1e18
- float 1e38
- double 1e308
- long double 2e4932
- string separated by space and endline
```
string s;
cin >> s;
cout << s;
```
- to get the complete string (only separated by endline)
`string s;
getline(cin, s);
cout << s;`
- for single character -> use char takes less space (256 characters)

## switch
```
int day;
cin >> day;
switch(day) {
  case 1:
    cout << "Monday";
  case 2:
    cout << "Tuesday";
  case 3:
    cout << "Wednesday";
  case 4:
    cout << "Thursday";
  case 5:
    cout << "Friday";
  case 6:
    cout << "Saturday";
  case 7:
    cout << "Sunday";
  cout << "Hello World"; //not executed, if switch statement has break keyword
  default:
    cout << "invalid";
  // without break, everything is executed in sequence
}
// if a  case is found to be true, everything after that is true
// thus, need to add break statements after every case
```
## array
- only same kind of data can be stored `int arr[5];` if any element is double, will trim itself to be int
- 2D `int arr

## string 
len of string
```
string s;
cin >> s;
cout << s.size(); // length of string
```

- DO NOT use `ans = ch + ans`
- this addition takes O(n)
- rather use `ans+=ch` then reverse ans 

## loops 
- while
- for / nested for
- do-while

## functions (flow goes to the function)
- void
- non-void (MUST ALWAYS have a return type) --> else returns a garbage value 
- parameterised
- non-parameterised
- passing by reference -->

## sort
has no return value

## ascii code: a --> 65, A --> 97
add 25 to each to get z=90, Z=122

## round()
to round down

## stoi()
https://www.geeksforgeeks.org/stdstoi-function-in-cpp/
- converts string to num, int n = stoi(str);
- out of range https://stackoverflow.com/questions/29931827/stoi-causes-out-of-range-error

## stol
- if number is long then stoi can contain the num

## to_string()
- int to string
- string s = to_string(num)

## min({1,2,3})
min of multiple values

## min_element(arr, arr+n)
min element of multiple values

## typeid(variable).name()
get type of variable, Pc = pointer

## pop_back vs back()
pop_back just removes the last member from the vector but it doesnt return anything
thus, cant do: cout << v.pop_back();

## pass by value vs reference
- by value
  - funcname(int num)
  - copy is created inside the function
  - changes made are made tp the copy of var
- by reference
  - funcname(int &num)
  - function takes the address of num
  - changes made are made to the actually var
```
void funcname(int num) {
  num+=10; // changes made to copy
}
void funcname(int &num) {
  num+=10; // changes made to original
}
```
- arrays are by default passed by reference by default
- but maps, sets, vectors etc all are passed by copy
```
void func(int arr[]) {
  arr[0]+=100; //changes made to original array
}
```
## string compare
- can't use double apostrophes `""` for character compare in a string
- since str[i] is a character
```
string str;
for (int i=0; i<str.size(); i++) {
  if (s[i]=='(') {} // should be single apostrophe
}
```
## time space complexity 
- when something /=10 eg digits in a number = floor(log num)+1
- since default base 10

## type conversion
int(chr) converts character chr to int
// a number with 1e5 digits can be written as 1e(1e5)
// since nos like 1e7 have 7 digits
## iswalnum(ch) 
- checks is char ch is alphanumeric
## reverse_copy()
- reverse (s.begin(), s.end()) reverses in place
- reverse_copy returns the reversed copy to a destination (can be used for vectors, strings etc)
```cpp
string A = "abc";
string B; //destination size should be changed to accomodate
// true in case of vector, string, etc
B.resize(A.size()); // make B big enough
reverse_copy(A.begin(), A.end(), B.begin());
cout << B << '\n';
```
## delimiter separation
```cpp
        vector<int> tokens;
        stringstream ss(inputString);
        string token;
        char delimiter=',';
        while (getline(ss, token, delimiter)) { 
            tokens.push_back(stoi(token)); 
        }
```
## Time Complexity
if k jumps in a loop -> complexity is harmonic sum (1/1 + 1/2 + 1/3 + .... 1/k) ~ log k
`for (int i=1; i<=n; i+=k)` 

## nC2 sums needed
eg 1 3 4 6 
all sums 1-3, 1-4, 1-6, 3-4, 3-6, 4-6
a[i]*i - prefix_sum[i]

## setprecision()
used for SIGNIFICANT DIGITS (not the ones after decimal but all significant digits)
```cpp
double num=0;
num+=a[i];
cout << setprecision(5) << num;
```

WHEN X DECIMAL PLACES ARE NEEDED
- use fixed keyword
`cout << fixed << setprecision(n) << float_variable`

## stable_sort()
https://chatgpt.com/share/a6d1e467-ceb5-496e-96d1-eb45ed81de8e
the sort in cpp doesnt make comparisons in order, so for cases when certain equal values require to maintain the order use stable sort
`stable_sort(arr.begin(), arr.end(), compare);`
