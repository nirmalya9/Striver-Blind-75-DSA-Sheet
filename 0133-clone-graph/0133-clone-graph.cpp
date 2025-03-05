/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        //Approach 1: BFS
    if (node == nullptr)
      return nullptr;

    queue<Node*> q{{node}};
    unordered_map<Node*, Node*> map{{node, new Node(node->val)}};

    while (!q.empty()) {
      Node* u = q.front();
      q.pop();
      for (Node* v : u->neighbors) {
        if (!map.contains(v)) {
          map[v] = new Node(v->val);
          q.push(v);
        }
        map[u]->neighbors.push_back(map[v]);
      }
    }

    return map[node];
}
    //Approach 2: DFS
//     if (node == nullptr)
//       return nullptr;
//     if (const auto it = map.find(node); it != map.cend())
//       return it->second;

//     Node* newNode = new Node(node->val);
//     map[node] = newNode;

//     for (Node* neighbor : node->neighbors)
//       newNode->neighbors.push_back(cloneGraph(neighbor));

//     return newNode;
//   }

//  private:
//   unordered_map<Node*, Node*> map;
    
};