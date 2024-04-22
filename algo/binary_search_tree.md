left < root < right
- if we really need duplictes, use frequency table (left <= root < right)
```cpp
//BST
TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL && root->val!=val) {
            root = val<root->val ? root->left:root->right;
        }
        return root;
    }
```
