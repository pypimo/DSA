left < root < right
- if we really need duplictes, use frequency table (left <= root < right)

## finding element
```cpp
TreeNode* searchBST(TreeNode* root, int find) {
        while(root!=NULL && root->val!=find) {
            root = find<root->val ? root->left:root->right;
        }
        return root;
    }
```

## finding lower_bound (ceil>=)
```cpp
int ceilBST(TreeNode* root, int key) {
    int ceil=-1;
    while(root) {
        // not needed actualy just write root->val>=key below
        if (key==ceil) {
            ceil=root->val;
            break;
        }
        if (root->val>key) {
            ceil=root->val;
            root =root->left;
        } else root=root->right;
    }
    return ceil;
}
```

## find floor
![chrome_lXo3Mj1HAC](https://github.com/user-attachments/assets/7c300460-749e-432b-ac11-2e1c64e91d69)


## insertion bst
- wrong ans if you just consider node and then insert at only root->left or root->right
- https://leetcode.com/problems/insert-into-a-binary-search-tree/submissions/1239099638/
