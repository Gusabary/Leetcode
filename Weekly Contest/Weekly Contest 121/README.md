## Directory: Weekly Contest 121

In the directory are my codes for [Weekly Contest 121](https://leetcode-cn.com/contest/weekly-contest-121).

I am so happy that it's my first time to finish three questions.

### Files:

#### stringWithout3aAnd3b.cpp

the code for [question 1](https://leetcode-cn.com/contest/weekly-contest-121/problems/string-without-aaa-or-bbb/).

Calculate how many groups of `aab` there are and fill the remaining space with `ab` or `a`, assuming `A` is bigger than `B`.

#### mincostTickets.cpp

the code for [question 2](https://leetcode-cn.com/contest/weekly-contest-121/problems/time-based-key-value-store/).

using a structure of `map<string, vector<pair<int, string>>>`.

#### timeMap.cpp

the code for [question 3](https://leetcode-cn.com/contest/weekly-contest-121/problems/minimum-cost-for-tickets/).

using... DP? I remembered just a little bit about DP but I finished this question luckily.

For each travelling day, the cost is the **minimum** of below:

+ the cost of the previous day + the cost of a 1-day pass.
+ the cost seven days ago + the cost of a 7-day pass.
+ the cost thirty days ago + the cost of 30-day ago.

(If the 7 or 30 day before the current day is `< 0`, then its cost should be 0.)

Therefore, the cost of the last day is the answer required.

#### rank.png

the final rank.

##### Last-modified date: 2019.1.27, 1 p.m.



