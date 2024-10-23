/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL) return root;
       vector<int> levelsum;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum =0;
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
            levelsum.push_back(sum);   
        }
        for(auto it: levelsum)
                cout<<it<<" ";
        int h=1;
        q.push(root)   ;
        root->val=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode * node = q.front();
                q.pop();
                int siblingsum=node->left!=NULL ? node->left->val: 0;
                siblingsum += node->right!=NULL ? node->right->val: 0;
                if(node->left && h< levelsum.size()){
                    node->left->val = levelsum[h]-siblingsum;
                    q.push(node->left);
                }
                if(node->right && h< levelsum.size()){
                    node->right->val = levelsum[h]-siblingsum;
                    q.push(node->right);
                }
            }
            h++;
        }
        return root;
    }
};