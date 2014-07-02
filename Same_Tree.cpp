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

bool isSameTree(TreeNode *p, TreeNode *q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;

    return (p->val == q->val)
        && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

bool isSameTree2(TreeNode *p, TreeNode *q)
{
    stack<TreeNode*> stk;
    stk.push(p);
    stk.push(q);

    while(!stk.empty()){
        p = stk.top(); stk.pop();
        q = stk.top(); stk.pop();

        if(p == NULL && q == NULL) continue;
        if(p == NULL || q == NULL) return false;
        if(p->val != q->val) return false;
        stk.push(p->left);
        stk.push(q->left);
        stk.push(p->right);
        stk.push(q->right);
    }
    return true;
}

void inorder(TreeNode *root)
{
    if(root){
        inorder(root->left);
        cout<<root->val <<endl;
        inorder(root->right);
    }
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());
    TreeNode *t1 = createTree();
    inorder(t1);
    in.close();

    ifstream in2;
    in2.open("input.txt");
    cin.rdbuf(in2.rdbuf());
    TreeNode *t2 = createTree();
    t2->val = 99;
    inorder(t2);
    in2.close();

    cout<<isSameTree2(t1, t2)<<endl;;
    return 0;
}
