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

## finding lower_bound (ceil>=intended-value)
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
- the node to be added should be added to the correct place
```cpp
  TreeNode* insertIntoBST(TreeNode* root, int val) {
        // put the node at the correct place
        TreeNode *addNode =  new TreeNode(val), *curr=root;
        if (!root) return addNode;
        while(curr) {
            if (addNode->val<curr->val) {
                // go left
                if (curr->left) curr=curr->left;
                else {
                    curr->left=addNode;
                    break;
                    //to stop while-loop since we do not assign curr again
                }
            } else {
                // go right
                if (curr->right) curr=curr->right;
                else {
                    curr->right=addNode;
                    break;
                    //to stop while-loop since we do not assign curr again
                }
            }
        }
        return root;
   }
```
RECURSIVE APPROACH
```cpp
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        else root->right = insertIntoBST(root->right, val);
        return root;
    }
```
