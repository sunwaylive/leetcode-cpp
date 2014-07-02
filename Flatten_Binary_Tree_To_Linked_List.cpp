#include <iostream>
#include <fstream>
#include <stack>

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

void flatten(TreeNode *root)
{
    if(root == NULL) return;

    flatten(root->left);
    flatten(root->right);

    //flatten process, move the left sub-tree between root ,and root->right
    if(root->left != NULL){
        TreeNode *p = root->left;
        while(p->right != NULL) p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
}

void flatten2(TreeNode *root)
{
    if(root == NULL) return;

    stack<TreeNode*> stk;
    TreeNode *p = root;
    stk.push(p);
    while(!stk.empty()){
        p = stk.top();
        stk.pop();

        if(p->left) stk.push(p->left);
        if(p->right) stk.push(p->right);

        p->left = NULL;
        if(!stk.empty())
            p->right = stk.top();
    }
}

void inorder(TreeNode *root)
{
    if(root){
        inorder(root->left);
        cout<<root->val<<endl;
        inorder(root->right);
    }
}

int main()
{
    fstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());
    TreeNode *t = createTree();
    inorder(t);
    flatten2(t);
    cout<<"after flatten"<<endl;
    inorder(t);
    in.close();
    return 0;
}
