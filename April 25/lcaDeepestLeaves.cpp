class Solution {
public:
    unordered_map<int,int> mp;
    int maxDepth = 0;

    void depth(TreeNode* root,int d){
        if(root == nullptr){
            return;
        }
        mp[root->val]=d;
        maxDepth=max(maxDepth,d);
        depth(root->left,d+1);
        depth(root->right,d+1);
    }

    TreeNode* lca(TreeNode* root){
        if(root == nullptr || mp[root->val]==maxDepth){
            return root;
        }
        TreeNode* l=lca(root->left);
        TreeNode* r=lca(root->right);
        if(l && r) return root;
        return l==nullptr? r:l;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) { 
        depth(root,0);
        return lca(root);
    }
};
