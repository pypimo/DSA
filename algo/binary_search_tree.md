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
## insertion bst
- wrong ans if you just consider node and then insert at only root->left or root->right
- https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/1239099638/
