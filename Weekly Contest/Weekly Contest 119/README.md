## Directory: Weekly Contest 119

In the directory are my codes for [Weekly Contest 119](https://leetcode-cn.com/contest/weekly-contest-119/).

### Files:

#### kClosest.cpp

the code for [problem 1](https://leetcode-cn.com/contest/weekly-contest-119/problems/k-closest-points-to-origin/).

Using `map` to store the distances so that they can be ordered automatically.

Then return first `K` elements.

#### largestPerimeter.cpp

the code for [problem 2](https://leetcode-cn.com/contest/weekly-contest-119/problems/largest-perimeter-triangle/).

First, order the data in descending sequence.

Then, `for` every three elements, if `A[i] < A[i+1] + A[i+2]`, that is to say, the three lengths can form a triangle, `A[i] + A[i+1] + A[i+2]` will be the answer.

It seems to be *greedy algorithm*? 

#### subarraysDivByK_1.cpp & subarraysDivByK_2.cpp

the code for [problem 3](https://leetcode-cn.com/contest/weekly-contest-119/problems/subarray-sums-divisible-by-k/).

But the two ways are both TLE.

The key to the problem is that the subarray must be **continuous**.

**subarraysDivByK_1.cpp :** At first I want to use *recursion*, but the data size is a little large, so I choose iterative method alternatively. That means to use `stack`. 

This method is similar to *DFS* to some extent, whose time complexity is `O(2^n)`, but actually it is just `O(n^2)`, approximately, due to the pruning of **continuous** condition.

**subarraysDivByK_2.cpp :** brutal force. Let `length` vary from 1 to `A.size()`  and for each certain `length`, let `start` vary from 0 to `A.size()-length`, all possible subarray will be drawn.

Time Complexity: `O(n^2)`

#### rank.png

the final rank.

##### Last-modified date: 2019.1.13 2 p.m.

