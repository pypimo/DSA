# LCA O(n)
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
        if (curr==goal) return true;
        if (curr->left!=NULL) {   
            path.push_back(curr);
            if (dfs(curr->left,goal, path)) return true;
        }
        if (curr->right!=NULL) {
            path.push_back(curr);
           if (dfs(curr->right,goal, path)) return true;
        }
        // only one needed here bcz if both left and right null, we want to remove this node
        // since we would have added this leaf node using curr->left or right
        path.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=NULL;
        if (root==NULL) return ans;
        vector<TreeNode*> path1,path2;
        dfs(root, p, path1);
        dfs(root, q, path2);
        path1.push_back(p);
        path2.push_back(q);
        for (int i=0; i<min(path1.size(), path2.size()); i++) {
            if (path1[i]==path2[i]) ans = path1[i];
        }
        return ans;
    }
};
```
better yet
```cpp
bool dfs(TreeNode* curr, TreeNode* goal, vector<TreeNode*>& path) {
    if (curr==NULL) return false;
    if (curr==goal || dfs(curr->left,goal, path) || dfs(curr->right,goal, path)){ 
        path.push_back(curr);
        return true;
    }   
    return false;
}
// then reverse in main
```
- another method - see left and right
- note: we don't want right subtree to have those seen values of left subtree because if that happens LCA will be incorrectly marked as the right subtree element instead of root
- eg: 3 (root), 5 (left), 1 (right), -> if we pass variables, p=5, q=1, seen at 1 will be true for both and 1 will be the ans which is wrong 
```cpp
TreeNode *find1, *find2, *ans=NULL;
// dfs to look left, then right - at whichever you see p and q first 
// that's ans
pair<int,int> dfs(TreeNode* curr){
    if (curr==NULL) return {0,0};
    pair<int,int> p1, p2, p3;
    if (ans==NULL) p1=dfs(curr->left);
    if (ans==NULL) p2=dfs(curr->right);
    if (curr==find1 || p1.first || p2.first) p3.first=1; 
    if (curr==find2 || p1.second || p2.second) p3.second=1; 
    if (ans==NULL && p3.first && p3.second) ans=curr;
    cout << curr->val << " " << p3.first << " " << p3.second << '\n';
    return p3;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    find1=p; find2=q;
    dfs(root);
    return ans;
}
```
```cpp
// using references
void dfs(TreeNode* curr, int &f1, int &f2){
    if (curr==NULL) return;
    // left and right subtree don't need to know about each other
    int leftf1=0, leftf2=0, rightf1=0, rightf2=0;
    if (ans==NULL) dfs(curr->left, leftf1, leftf2);
    if (ans==NULL) dfs(curr->right, rightf1, rightf2);
    if (curr==find1 || leftf1 || rightf1) f1=1; 
    if (curr==find2 || leftf2 || rightf2) f2=1; 
    if (ans==NULL && f1 && f2) ans=curr;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    find1=p; find2=q;
    int f1=0, f2=0;
    dfs(root, f1, f2);
    return ans;
}
```
- for q queries -> q*n (doestn work if q ~ 1e5)
## Binary Lifting
```cpp
```
