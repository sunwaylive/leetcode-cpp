#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

TreeNode* createTree()
{
    TreeNode *Tree;
    int data;
    cin>>data;
    if(data == -1){
        Tree = NULL;
    }else{
        Tree = (TreeNode*)malloc(sizeof(TreeNode));
        Tree->val = data;
        Tree->left = createTree();
        Tree->right = createTree();
    }
    return Tree;
}

void inorderTraversal(TreeNode *root)
{
    if(root != NULL){
        inorderTraversal(root->left);
        cout<<root->val<<endl;
        inorderTraversal(root->right);
    }
}

vector<int> inorderTraversal2(TreeNode *root)
{
    stack<TreeNode*> stk;
    vector<int> ret;

    TreeNode *p = root;
    while(p != NULL || !stk.empty()){
        if(p != NULL){
            stk.push(p);
            p = p->left;
        }else{
            p = stk.top();
            stk.pop();
            //cout<<p->val<<endl;
            ret.push_back(p->val);
            p = p->right;
        }
    }
    return ret;
}

// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
// 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
// 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
//     a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
//     b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空（恢复树的形状）。输出当前节点。当前节点更新为当前节点的右孩子。
// 3. 重复以上1、2直到当前节点为空。

void morrisInorder(TreeNode* root)
{
    TreeNode *p = root, *tmp;

    while(p){
        if(p->left == NULL){
            cout<<p->val<<endl;
            p = p->right;//no left children, then deal with right children
        }else{
            //find p's 前驱
            tmp = p->left;
            while(tmp->right != NULL && tmp->right != p)
                tmp = tmp->right;
            if(tmp->right == NULL){//link them
                tmp->right = p;
                p = p->left;
            }else{
                tmp->right = NULL;//cut them
                cout<<p->val<<endl;//we should visit p before it changes
                p = p->right;//move to right sub-tree
            }
        }
    }
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    inorderTraversal2(t);
    return 0;
}
