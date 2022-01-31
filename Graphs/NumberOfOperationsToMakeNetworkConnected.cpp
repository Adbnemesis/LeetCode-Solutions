class Solution {
public:
    
    void dfs(list<int>* l, int x, bool* visited){
        visited[x] = true;
        for(auto a : l[x]){
            if(visited[a])continue;
            dfs(l,a,visited);
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<(n-1))return -1;
        int edges = connections.size();
        list<int>* l = new list<int>[100000];
        for(int i = 0;i<connections.size();i++){
            l[connections[i][0]].push_back(connections[i][1]);
            l[connections[i][1]].push_back(connections[i][0]);
            
        }
        
        int components = 0;
        bool*visited = new bool[n];
        for(int i = 0;i<n;i++)visited[i] = false;
        for(int i = 0;i<n;i++){
            if(!visited[i]){
                components++;
                dfs(l,i,visited);
            }
        }
        int red = edges - ((n-1) - (components-1));
        if(red>=components-1)return components-1;
        return -1;
        
    }
};
