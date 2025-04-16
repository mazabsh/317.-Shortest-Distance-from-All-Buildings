#include<iostream> 
#include<vector> 
#include<queue> 
#include<climits> 

using namespace std; 

int BFS(vector<vector<int>>& grid){

  int m = grid.size(); 
  int n = grid[0].size(); 
  vector<vector<int>> count(m, vector<int> (n,0)); 
  vector<vector<int>> dist(m,vector<int> (n,0)); 
  vector<int> direction={-1,0,1,0,-1}; 
   
  int totalBuilding=0; 

  for(int i=0; i<m; ++i){
    for(int j=0; j<n;++j){
      if(grid[i][j]==1){
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n,false)); 
        int level =0; 
        totalBuilding++; 
        q.push({i,j}); 
        while(!q.empty()){
          level++; 
          int size= q.size();
          for(int p=0; p<size; ++p){
            auto [x,y] = q.front(); 
            q.pop(); 
            for(int k =0; k<4; ++k){
              int dx = x+direction[k]; 
              int dy = y+direction[k+1]; 
              if(dx>=0 && dx<m && dy>=0 && dy<n && grid[dx][dy]==0 && !visited[dx][dy]){
                visited[dx][dy] = true; 
                q.push({dx,dy}); 
                dist[dx][dy]+=level; 
                count[dx][dy]++; 
                
              }
            }
          }
        }
      }
    }
  }
  int minDistance = INT_MAX; 
  for(int i=0; i<m; ++i){
    for(int j=0; j<n; ++j){
      if(totalBuilding == count[i][j] && grid[i][j]==0){
        minDistance = min(minDistance, dist[i][j]); 
      }
    }
  }
  return (minDistance == INT_MAX) ? -1 : minDistance; 
  
}
int main() {
    vector<vector<int>> grid = {
        {1, 0, 2, 0, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };
    cout << BFS(grid) << endl;  // Output: 7
    return 0;
}
