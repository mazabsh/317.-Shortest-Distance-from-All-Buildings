#include<iostream> 
#include<vector> 
#include<queue> 
#include<climits> 

using namespace std; 

int BFS(vector<vector<int>>& grid){

  int m = grid.size(); 
  int n = grid[0].size(); 

  vector<vector<int>> distance(m, vector<int> (n); 
  vector<vector<int>> count(m, vector<int>(n)); 
  vector<int> direction = {-1,0,1,0,-1}; 
  vector<vector<bool>> visited(m, vector<bool> (n, false)); 
  int minDistance = INT_MAX; 
  queue<pair<int,int>> q; 
  int totalbuildings = 0; 
  for(int i=0; i<m; ++i){
    for(int j=0; j<n ; ++j){
      if(grid[i][j]==1){
        int depth = 0; 
        q.push({i,j}); 
        totalbuildings++; 
        for(int k=0; k< q.size(); ++k){
          auto [x,y] = q.front(); 
          q.pop(); 
          for(int t=0; t<4; ++t){
            int dx= x+direction[k]; 
            int dy = y+direction[k+1]; 
            if(dx>=0 && dx<m && dy>=0 && dy<n && grid[dx][dy]==0 && !visited[dx][dy]){
              visited[dx][dy] = true; 
              q.push({dx,dy}); 
              
            }
          }
        }
        
      }
    }
  }
  
}
