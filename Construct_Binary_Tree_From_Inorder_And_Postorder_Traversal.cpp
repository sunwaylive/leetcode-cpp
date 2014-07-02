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

TreeNode* build(vector<int> &inorder, int il, int ir,
                vector<int> &postorder, int pl, int pr)
{
    TreeNode *root;
    if(il > ir || pl > pr){
        root = NULL;
    }else{
        root = new TreeNode(postorder[pr]);
        int i;
        for(i = il; i <= ir && inorder[i] != postorder[pr]; ++i) ;
        root->left = build(inorder, il, i - 1, postorder, pl, pl + i - il - 1);
        root->right = build(inorder, i + 1, ir, postorder, pl + i - il, pr - 1);
    }
    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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
    int in[] = {1, 2, 4, 3, 5, 7};
    int post[] = {1, 4, 2, 7, 5, 3};
    vector<int> v_postorder(post, post + sizeof(post) / sizeof(post[0]));
    vector<int> v_inorder(in, in + sizeof(in) / sizeof(in[0]));
    TreeNode *t = buildTree(v_inorder, v_postorder);
    preorder(t);
    return 0;
}
