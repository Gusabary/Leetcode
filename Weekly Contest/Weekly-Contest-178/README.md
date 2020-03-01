# Weekly Contest 178

## P1

## P2

问题在于我的解法需要对 map 排序，但是 sort 函数只能用于对序列式容器排序，而 map 是关联式容器。所以正确的做法是先将 map 转为 vector，然后对 vector 排序：

```c++
vector<pair<k, v>> v(mapv.begin(), mapv.end());
sort(v.begin(), v.end());
```

只有一个点入度为 0，其余所有点入度为 1，遍历一遍数组就行。

## P3

二叉树，dfs

## P4

bfs，我的解法是递归实现，但是超时了，看了看别人的解法有用队列实现的。

##### Last-modified date: 2020.3.1, 12 p.m.