## Directory: Weekly Contest 125

In the directory are my codes for [Weekly Contest 125](https://leetcode-cn.com/contest/weekly-contest-125).

### Files:

#### findJudge.cpp

the code for [question 1](https://leetcode-cn.com/contest/weekly-contest-125/problems/find-the-town-judge/).

If a man has never appeared in `trust[i][0]` but appeared in `trust[i][1]` for `N-1` times, he is the judge.

#### numRookCaptures.cpp

the code for [question 2](https://leetcode-cn.com/contest/weekly-contest-125/problems/available-captures-for-rook/).

pawN!!!

#### maxBinaryTree-II.cpp

the code for [question 3](https://leetcode-cn.com/contest/weekly-contest-125/problems/maximum-binary-tree-ii/).

Given a binary tree, the corresponding array can be drawn by In-order traversal. Then attack `val` to the last of the array. Finally, build the new binary tree recursively:

1. Find the maximum value of current array and raise it up as the root of current subtree.
2. Assign the left subarray of the maximum to a new array and repeat step 1 then link the current root to the one in step 1.
3. Do the same on the right part.

#### gridIllumination.cpp

the code for [question 4](https://leetcode-cn.com/contest/weekly-contest-125/problems/grid-illumination/).

I didn't get the score, but I haven't find the reason. Below is my tentative solution.

First, `map[i][j].light` means how many times the position `(i,j)` has been exposed to different lamps. If it is `>0`, this position is lighted up.

So traverse the array `lamps`, and calculate out `map[i][j].light`.

Then traverse the array `queries`, for each `query`, turn off the lamp of queried position and ones around it. The key is to subtract corresponding value from former `map[i][j].light`.

Maybe the algorithm needs further optimization.

#### rank.png

the final rank.

##### Last-modified date: 2019.2.24, 1 p.m.