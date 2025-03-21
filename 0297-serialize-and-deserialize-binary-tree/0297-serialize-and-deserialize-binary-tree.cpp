/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // // Encodes a tree to a single string.
    // string serialize(TreeNode* root) {
        
    // }

    // // Decodes your encoded data to tree.
    // TreeNode* deserialize(string data) {

    //Approach: BFS
    string serialize(TreeNode* root) {
    if (root == nullptr)
      return "";

    string s;
    queue<TreeNode*> q{{root}};

    while (!q.empty()) {
      TreeNode* node = q.front();
      q.pop();
      if (node != nullptr) {
        s += to_string(node->val) + " ";
        q.push(node->left);
        q.push(node->right);
      } else {
        s += "n ";
      }
    }

    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty())
      return nullptr;

    istringstream iss(data);
    string word;
    iss >> word;
    TreeNode* root = new TreeNode(stoi(word));
    queue<TreeNode*> q{{root}};

    while (iss >> word) {
      TreeNode* node = q.front();
      q.pop();
      if (word != "n") {
        node->left = new TreeNode(stoi(word));
        q.push(node->left);
      }
      iss >> word;
      if (word != "n") {
        node->right = new TreeNode(stoi(word));
        q.push(node->right);
      }
    }

    return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));