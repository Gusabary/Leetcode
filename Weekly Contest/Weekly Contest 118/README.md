## Directory: Weekly Contest 118

In the directory are my codes in the [weekly contest 118](https://leetcode-cn.com/contest/weekly-contest-118).

I used one hour finishing first two questions but remaining ones were a little difficult.

### Files:

#### powerfulIntegers.cpp

the code for [question 1](https://leetcode-cn.com/contest/weekly-contest-118/problems/powerful-integers/).

brutal force.

But notice the extreme condition that `x==1` or `y==1`, which can result in endless loop unless handled otherwise.

#### pancakeSort.cpp

the code for [question 2](https://leetcode-cn.com/contest/weekly-contest-118/problems/pancake-sorting/).

I found a rule:

> If `A[i] > A[i-1]`, find a `pos` before `i`, which meets the condition that `A[pos] < A[i]` and `A[pos+1] < A[i]`. That is to say, find an appropriate place for `A[i]`.
>
> If `pos` is really found:
>
> > `pancakeFlip(i+1)`->`pancakeFlip(i-pos)`->`pancakeFlip(i-pos-1)`->`pancakeFlip(i+1)`
>
> If `pos` is not found (`A[i]` is the smallest in current numbers):
>
> > `pancakeFlip(i)`->`pancakeFlip(i+1)`

Let `i` traverse through the whole vector `A`, the answer is drawn and the vector is sorted well.

#### rank.png

the final rank.

##### Last-modified date: 2019.1.6 12 p.m.

