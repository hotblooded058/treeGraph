/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/

void dfs(int i,int j,vector<vector<char>>& grid)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(i<0 || j<0) return;
        if(i>=m || j>=n) return;
        if(grid[i][j]=='0') return;
        grid[i][j]='0';
        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int cnt=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {  
                if(grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    cnt++;
                }
                  
            }
        }
        return cnt;
    }