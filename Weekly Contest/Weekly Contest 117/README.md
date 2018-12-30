## Directory: Weekly Contest 117

In the directory are my codes in the [weekly contest 117](https://leetcode-cn.com/contest/weekly-contest-117).

It is really a pity that I finished question 3 just after the contest ended :(

### Files:

#### UnivalTree.cpp

the code for [question 1](https://leetcode-cn.com/contest/weekly-contest-117/problems/univalued-binary-tree/).

Judge whether each node is equivalent to all nodes of its left subtree and right one, using recursion.

#### sameConsecDiff.cpp

the code for [question 2](https://leetcode-cn.com/contest/weekly-contest-117/problems/numbers-with-same-consecutive-differences/).

I used a binary tree to simulate the route it took, which means the following number can choose to `+K` or `-K` as long as it is still in the range `[0,9]` after selection. `+K` means to choose left subtree while `-K` means to choose the right one so starting from the `root`, when it reaches the `leaf` , a route is generated, which records all the choice. Then return to the father of the leaf and repeat the process. (**DFS**) 

With the route and `K`, a required number can be constructed.

Let the first number change from 1 to 9, all routes are drawn.

But some boundary conditions such as `N==1` or `K==0` really cost me too much time.

#### spellChecker.cpp

the code for [question 3](https://leetcode-cn.com/contest/weekly-contest-117/problems/vowel-spellchecker/).

brutal force.

This question seems to be easier than question 2.

#### rank.png

the final rank.

##### Last-modified date: 2018.12.30 1 p.m.