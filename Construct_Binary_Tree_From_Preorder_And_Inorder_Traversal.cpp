#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

TreeNode* createTree()
{
    TreeNode *Tree;
    int data;
    cin>>data;
    if(data == -1){
        Tree = NULL;
    }else{
        Tree = new TreeNode(data);
        Tree->left = createTree();
        Tree->right = createTree();
    }
    return Tree;
}

TreeNode* build(vector<int> &preorder, int pl, int pr,
                vector<int> &inorder, int il, int ir)
{
    TreeNode *root;
    if(pl > pr || il > ir){
        root = NULL;
    }else{
        root = new TreeNode(preorder[pl]);
        int i;
        for(i = il; i <= ir && preorder[pl] != inorder[i]; ++i) ;
        root->left = build(preorder, pl + 1, pl + i - il, inorder, il, i - 1);
        root->right = build(preorder, pl + i - il + 1, pr, inorder, i + 1, ir);
    }
    return root;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

void preorder(TreeNode *root)
{
    if(root){
        cout<<root->val<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    int pre[] = {3, 2, 1, 4, 5, 7};
    int in[] = {1, 2, 4, 3, 5, 7};
    vector<int> v_preorder(pre, pre + sizeof(pre) / sizeof(pre[0]));
    vector<int> v_inorder(in, in + sizeof(in) / sizeof(in[0]));
    TreeNode *t = buildTree(v_preorder, v_inorder);
    preorder(t);
    return 0;
}
