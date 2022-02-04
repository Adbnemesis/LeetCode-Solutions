class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int steps = 0;
      bool visited[n][n];
        memset(visited,false,sizeof(visited));
        queue<int> q;
        q.push(1);
        visited[n-1][0] = true;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                int x = q.front();
                q.pop();
                if(x == n*n)return steps;
                for(int j = 1;j<=6;j++){
                   if(j+x>(n*n))break;
                    auto[r,c] = coordinates(x+j,n);
                    if(visited[r][c])continue;
                    visited[r][c] = true;
                    if(board[r][c]==-1)q.push(x+j);
                    else q.push(board[r][c]);
                }
            }
            steps++;
        }
        return -1;
    }
    
    pair<int,int> coordinates(int x, int n){
        int r = n-1-((x-1)/n);
        int c = (x-1)%n;
        if(r%2 == n%2)c = n-1-c;
        
        return {r,c};
    }
};
