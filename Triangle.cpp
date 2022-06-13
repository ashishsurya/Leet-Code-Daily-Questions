/*
link : https://leetcode.com/problems/triangle/
reference : https://www.youtube.com/watch?v=FdwDUkldcA0
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> helper(triangle.back());
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<triangle[i].size();j++) {
                helper[j] = min(helper[j],helper[j+1]) + triangle[i][j];
            }
        }
        return helper[0];
    }
};
