# 1964. Find the Longest Valid Obstacle Course at Each Position

You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.

For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:

You choose any number of obstacles between 0 and i inclusive.
You must include the ith obstacle in the course.
You must put the chosen obstacles in the same order as they appear in obstacles.
Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.

```
Input: obstacles = [1,2,3,2]
Output: [1,2,3,3]
Explanation: The longest valid obstacle course at each position is:
- i = 0: [1], [1] has length 1.
- i = 1: [1,2], [1,2] has length 2.
- i = 2: [1,2,3], [1,2,3] has length 3.
- i = 3: [1,2,3,2], [1,2,2] has length 3.
```



```cpp
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        
        // lis[i] records the lowest increasing sequence of length i + 1.
        vector<int> answer(n, 1), lis;
        
        for (int i = 0; i < n; ++i) {
            // Find the rightmost insertion position idx.
            int idx = upper_bound(lis.begin(), lis.end(), obstacles[i]) - lis.begin();
            if (idx == lis.size())
                lis.push_back(obstacles[i]);
            else
                lis[idx] = obstacles[i];
            answer[i] = idx + 1;
        }
        return answer;
    }
};
```
