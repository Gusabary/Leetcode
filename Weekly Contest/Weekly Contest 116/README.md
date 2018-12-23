## Directory: Weekly Contest 116

In the directory are my codes in the [weekly contest 116](https://leetcode-cn.com/contest/weekly-contest-116/).

And in the contest I defeat Yuan Jianyong :)

### Files:

#### repeat.cpp

the code for [question 1](https://leetcode-cn.com/contest/weekly-contest-116/problems/n-repeated-element-in-size-2n-array/).

Extremely easy.

#### ramp.cpp

the code for [question 2](https://leetcode-cn.com/contest/weekly-contest-116/problems/maximum-width-ramp/).

brutal force.

But I exceeded time limit so I firstly deal with the condition that all elements were arranged in descending order to pass the big test case.

Luckily, there wasn't any other strange case.

#### rectangle.cpp

the code for [question 3](https://leetcode-cn.com/contest/weekly-contest-116/problems/minimum-area-rectangle-ii/).

I used a `set<pair<int,int>>` to store each point.

First, link any two points, and draw vertical line to reach other two points simultaneously, forming a rectangle. 

But TLE.

I think the problem is that choosing two points in the `set` costs too much time and some points which have been reached can be omitted.

###### TO DO: optimize the solution

#### rank.png

the final rank.

##### Last-modified date: 2018.12.23 2 p.m.