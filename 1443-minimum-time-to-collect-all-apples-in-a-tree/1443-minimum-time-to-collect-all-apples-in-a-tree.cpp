class Solution {
public:
    vector<bool>visited;
    int dfs(vector<int>adj[], int node, int myCost, vector<bool>& hasApple){
	  if (visited[node]) {
		  return 0;
	  }
	  visited[node] = true;
	  
      int childrenCost = 0; // cost of traversing all children. 
      for (auto x: adj[node]) { 
        childrenCost += dfs(adj, x, 2, hasApple);  // check recursively for all apples.
      }

      if (childrenCost == 0 && hasApple[node] == false) {
	  // If no child has apples, then we won't traverse the subtree, so cost will be zero.
	  // similarly, if current node also does not have the apple, we won't traverse this branch at all, so cost will be zero.
        return 0;
      }
	  
	  // Children has at least one apple or the current node has an apple, so add those costs.
      return (childrenCost + myCost);
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<int> adj[n];
        
        for(auto x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        for(int i=0; i<n; i++){
            visited.push_back(false);
        }
        int time = 0;
        time = dfs(adj, 0, 0, hasApple);
        return time;
    }
};