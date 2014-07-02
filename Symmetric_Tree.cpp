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
        Tree = (TreeNode*) malloc(sizeof(TreeNode));
        Tree->val = data;
        Tree->left = createTree();
        Tree->right = createTree();
    }
    return Tree;
}


//recursive solution
bool isSymmetric2(TreeNode *left, TreeNode *right) {
    if(left == NULL && right == NULL) return true;//reach NULL at the same time
    if(left == NULL || right == NULL) return false;//only one of them reaches NULL
    return (left->val == right->val)
        && isSymmetric2(left->left, right->right)
        && isSymmetric2(left->right, right->left);
}

bool isSymmetric(TreeNode *root)
{
    return root ? isSymmetric2(root->left, root->right) : true;
}

//iterative solution
bool isSymmetric3(TreeNode *root)
{
    if(root == NULL) return true;

    stack<TreeNode*> stk;
    TreeNode *p, *q;
    stk.push(root->left);
    stk.push(root->right);

    while(!stk.empty()){
        p = stk.top(); stk.pop();
        q = stk.top(); stk.pop();

        if(!p && !q) continue;
        if(!p || !q) return false;
        if(p->val != q->val) return false;

        stk.push(p->left);
        stk.push(q->right);

        stk.push(p->right);
        stk.push(q->left);
    }
    return true;
}

void inorder(TreeNode *root)
{
    if(root){
        cout<<root->val<<" ";
        inorder(root->left);
        inorder(root->right);
    }
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());
    TreeNode *t = createTree();
    in.close();

    inorder(t);
    cout<<endl<<isSymmetric3(t)<<endl;
    return 0;
}
