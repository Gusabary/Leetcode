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

#### 662-maxWidthOfBinaryTree.cpp

the code for [problem 662](https://leetcode-cn.com/problems/maximum-width-of-binary-tree/).

using level-order traversal.

Get the position of the most left and right node that isn't `NULL` in each level and width can be calculated.

Moreover, in my algorithm, the `leftSon` and `rightSon` of `NULL` are both assigned as `NULL` unless there is not **valid** node (that is, the node is not `NULL`) at the left of the current `NULL`. It is a kind of optimization, which can discard many **useless** `NULL` in the left. (**useful** `NULL` means it is between the left and right border so that can contribute to the width)

#### 934-bridge.cpp

the code for [problem 934](https://leetcode-cn.com/problems/shortest-bridge/).

using BFS.

**Step 1 :** determine the range of the first island.

**Step 2 :** determine the range of the second island.

**Step 3 :** determine the distance of each point from the second island.

**Step 4 :** find the smallest distance in the first island, which is the distance between two islands

##### Last-modified date: 2019.1.12 5 p.m.

