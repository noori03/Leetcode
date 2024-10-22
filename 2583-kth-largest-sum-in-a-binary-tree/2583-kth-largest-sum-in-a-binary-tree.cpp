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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
             int n = q.size();
             long long sum=0;
             for(int i=0;i<n;i++){
                 TreeNode* node = q.front();
                 q.pop();
                if(node->right) q.push(node->right);
                if(node->left)  q.push(node->left);
                sum += node->val;

             }
             pq.push(sum);
        }
        if(k>pq.size()) return -1;
        while(k!=1){
            pq.pop();
            k--;
        }
        return pq.top();

    }
};