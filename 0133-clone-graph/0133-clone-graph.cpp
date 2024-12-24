// Definition for a Node
// class Node {
// public:
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        // Map to store the mapping of original nodes to their clones
        unordered_map<Node*, Node*> visited;

        // Queue for BFS
        queue<Node*> q;

        // Create a clone for the starting node and add it to the map and queue
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        q.push(node);

        // Perform BFS
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            // Iterate through the neighbors of the current node
            for (Node* neighbor : current->neighbors) {
                // If the neighbor hasn't been visited, clone and enqueue it
                if (visited.find(neighbor) == visited.end()) {
                    Node* neighborClone = new Node(neighbor->val);
                    visited[neighbor] = neighborClone;
                    q.push(neighbor);
                }

                // Add the cloned neighbor to the current node's clone
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }

        // Return the clone of the starting node
        return cloneNode;
    }
};
/*
Here's how we can solve the graph cloning problem using **Breadth-First Search (BFS)**. Instead of recursively visiting nodes as in DFS, we use a queue to traverse the graph layer by layer.

---

### **Steps for BFS Solution**

1. **Create a HashMap**:
   - Map each original node to its clone. This ensures we create exactly one copy of each node.

2. **Use a Queue for BFS**:
   - Start with the given `node`. Push it into the queue and clone it.
   - While the queue is not empty, pop a node and iterate through its neighbors:
     - If a neighbor is not visited, clone it and push it into the queue.
     - Add the cloned neighbor to the neighbors of the cloned node.

3. **Return the Cloned Graph**:
   - After the BFS traversal, the cloned graph will be ready.
---

### **Explanation of the Code**

1. **Initialization**:
   - Use an unordered map `visited` to store the mapping from original nodes to cloned nodes.
   - Use a queue `q` to implement BFS.

2. **Cloning the First Node**:
   - Clone the starting node and add it to the `visited` map.
   - Push the original starting node into the queue.

3. **BFS Traversal**:
   - For each node in the queue, process its neighbors:
     - If a neighbor is not visited, clone it, add it to the map, and enqueue the original neighbor.
     - Add the cloned neighbor to the neighbors of the current node's clone.

4. **Return the Clone**:
   - Once BFS completes, the entire graph is cloned. Return the clone of the starting node.

---

### **Time and Space Complexity**

1. **Time Complexity**:
   - \(O(V + E)\), where \(V\) is the number of nodes and \(E\) is the number of edges. Each node and edge is processed once.

2. **Space Complexity**:
   - \(O(V)\) for the `visited` map and the BFS queue.

---

### **Example**

#### Input Graph:
```
1: [2, 4]
2: [1, 3]
3: [2, 4]
4: [1, 3]
```

#### Output Graph (Cloned):
```
1: [2, 4]
2: [1, 3]
3: [2, 4]
4: [1, 3]
```

#### Test Code:
```cpp
int main() {
    // Create a graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    node1->neighbors = {node2, node4};
    node2->neighbors = {node1, node3};
    node3->neighbors = {node2, node4};
    node4->neighbors = {node1, node3};

    // Clone the graph
    Solution solution;
    Node* clonedGraph = solution.cloneGraph(node1);

    // Output cloned graph
    cout << "Cloned Node Value: " << clonedGraph->val << endl;
    for (Node* neighbor : clonedGraph->neighbors) {
        cout << "Neighbor: " << neighbor->val << endl;
    }
    return 0;
}
```

This BFS approach ensures that the graph is correctly cloned in \(O(V + E)\) time and is well-suited for connected graphs.
*/
