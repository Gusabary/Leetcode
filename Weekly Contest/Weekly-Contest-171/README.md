# Weekly Contest 171

快一年没参加 leetcode 周赛了，所幸手感还在。

## P1

穷举，O(n)

## P2

遍历，O(logn)

## P3

对于每个 SCC，找一个生成树，记下多余边的个数，最后比较所有多余的边的个数和 SCC 的数目。

如果多余的边比较多，那么可以将这些 SCC 都连起来，否则连不起来。

## P4

做完前三题只剩大概半小时了，说实话在畏难情绪的作用下压根没想做出来最后一题，不过仔细想想也不是很难。

DP，感觉关键在于 index 意义的选择上，一开始我选择的是一维表，i 表示处理到第几个字符，但是最后一题 DP 怎么可能只用一维表- -

后来改成二维表，i 表示左手输的**最后**一个字符在原字符串中的位置，j 表示右手输的**最后**一个字符在原字符串中的位置。

对于 i <= j-2 的情况，比如原字符串是 ABCD，当前状态是 B|D，那这个必然只能从 B|C 的状态转移过来。

对于 i = j-1 的情况，比如 C|D，可以从 C|B, C|A, C|0 转移过来，取代价最小的转移。

二维表关于对角线对称。

##### Last-modified date: 2020.1.12, 1 p.m.