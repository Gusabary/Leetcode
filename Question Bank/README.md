## Directory: Question Bank

In the directory are my codes for questions in the [question bank](https://leetcode-cn.com/problemset/all/).

### Files:

#### 921-parenthese.cpp

the code for [problem 921](https://leetcode-cn.com/problems/minimum-add-to-make-parentheses-valid/).

Problems related to parentheses can be solved with `stack` always.

In this problem, I store the top element of the imaginary stack rather than use a real stack so that space complexity is relatively low while the effect is the same.

Also, there are some rules such as the **current** `(` must be redundant and there cannot exist `(` before any `)` in the redundant parentheses.

#### 923-threeSum.cpp

the code for [problem 923](https://leetcode-cn.com/problems/3sum-with-multiplicity/).

half-brutal force.

Time complexity is O(m^3). m is the number of different elements of array A.

##### Last-modified date: 2018.12.22 5 p.m.

