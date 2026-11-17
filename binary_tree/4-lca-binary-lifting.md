# LCA O(n)
## Time O(n), Space O(h) or O(n) worst case
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || root == p || root == q) return root;

  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);

  if (left && right) return root;
  return left ? left : right;
}

```
- way2: find last common node in path
```cpp
class Solution {
public: 
    bool dfs(TreeNode* curr, TreeNode* goal, vector<TreeNode*>& path) {
        if (curr==NULL) return false;
        path.push_back(curr);
        if (curr==goal || dfs(curr->left, goal, path) || dfs(curr->right, goal, path)) return true;
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        if (root==NULL) return ans;
        vector<TreeNode*> path1,path2;
        dfs(root, p, path1);
        dfs(root, q, path2);
        for (int i=0; i<min(path1.size(), path2.size()); i++) {
            if (path1[i]==path2[i]) ans = path1[i];
        }
        return ans;
    }
};
```
stack build path 
```cpp
bool dfs(TreeNode* curr, TreeNode* goal, stack<TreeNode*>& path) {
    if (curr==NULL) return false;
    if (curr==goal || dfs(curr->left,goal, path) || dfs(curr->right,goal, path)){ 
        path.push(curr);
        return true;
    }   
    return false;
}
// then pop stack in main for correct path
```
- for q queries -> q*n (doestn work if q ~ 1e5)
## Binary Lifting
```cpp
```
## Tarjan's algo
