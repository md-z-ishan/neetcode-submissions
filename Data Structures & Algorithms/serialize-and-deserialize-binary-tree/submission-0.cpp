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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string ans="";
        if(!root){
            return "";
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
           
            if(node==NULL){
                ans+="N,";
                continue;
            }
             ans+=to_string(node->val)+",";
            q.push(node->left);
            q.push(node->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        if(data==""){
            return NULL;
        }
        string str;
        stringstream ss(data);
        getline(ss,str,',');
        TreeNode*root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            
            //left child
            getline(ss,str,',');
                if(str!="N"){
                    node->left=new TreeNode(stoi(str));
                    q.push(node->left);
                }
            
            //right child
            getline(ss,str,',');
                if(str!="N"){
                    node->right=new TreeNode(stoi(str));
                    q.push(node->right);
                }
            
        }
        return root;
    }
};