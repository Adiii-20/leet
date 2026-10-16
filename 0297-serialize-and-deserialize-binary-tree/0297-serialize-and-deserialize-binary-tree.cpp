/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:


    void serial(TreeNode* root, string& s){
        if(root == NULL){
            s = s + 'x';
            return ;
        }
        s = s + to_string(root->val) +  ',';
        serial(root->left,s);
        serial(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        serial(root,s);
        return s;
    }

    TreeNode* deserialize(string& s, int& i){
        if( s[i] == 'x' ){
            i++;
            return NULL;
        };
        string v = "";
        while(i<s.size() && s[i]!=','){
            v = v + s[i];
            i++;
        }
        if( i < s.size() ) i++;
        TreeNode* root = new TreeNode(stoi(v));
        root->left = deserialize(s,i);
        root->right = deserialize(s,i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return deserialize(data,i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));