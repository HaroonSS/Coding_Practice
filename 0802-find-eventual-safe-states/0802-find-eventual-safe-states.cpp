class Solution {
public:
    bool DFSRec(int s, vector<bool>&visited, vector<bool>&pathVisited, vector<vector<int>>& graph, vector<bool> &present_cycle){     
        visited[s] = true;
        pathVisited[s] = true;
        
        vector<int>data = graph[s];
        for(auto x: data){
            if(!visited[x]){   // when the node is not visited
                
                if(DFSRec(x, visited, pathVisited, graph, present_cycle)){
                    present_cycle[s] = true;
                    return true;
                }
            }
            else if(pathVisited[x]){ // if the node has been previously visited but it has to be visited on the same path
                present_cycle[s] = true;
                return true;
            }
        }
        
        pathVisited[s] = false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> safeNodes;
        int n = graph.size();
        
        vector<bool>visited(n, false), pathVisited(n, false);
        vector<bool> present_cycle(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                DFSRec(i, visited, pathVisited,graph, present_cycle);
            }
        }
        for(int i=0; i<n; i++){
            if(!present_cycle[i]){
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};/*
Time Complexity: O(V+E)+O(V), where V = no. of nodes and E = no. of edges. There can be at most V components. So, another O(V) time complexity.
Space Complexity: O(3N) + O(N) ~ O(3N): O(3N) for three arrays required during dfs calls and O(N) for recursive stack space.*/