#include <iostream>
#include <fstream>
#include <vector>
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

void preorderTraversal(TreeNode *root)
{
    if(root != NULL){
        cout<<root->val <<endl;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

vector<int> preorderTraversal2(TreeNode *root) {
    stack<TreeNode*> stk;
    vector<int> ret;
    TreeNode *p = root;

    if(p != NULL) stk.push(root);

    while(!stk.empty()){
        p = stk.top();
        stk.pop();
        ret.push_back(p->val);
        cout<<p->val<<endl;

        if(p->right != NULL) stk.push(p->right);
        if(p->left != NULL) stk.push(p->left);
    }

    return ret;
}

// http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
// 1. 如果当前节点的左孩子为空，则输出当前节点并将其右孩子作为当前节点。
// 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
//    a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。输出当前节点（在这里输出，这是与中序遍历唯一一点不同）。当前节点更新为当前节点的左孩子。
//    b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。当前节点更新为当前节点的右孩子。
// 3. 重复以上1、2直到当前节点为空。

void morrisPreorder(TreeNode *root)
{
    TreeNode *p = root, *tmp;
    if(p == NULL) return;

    while(p){
        if(p->left == NULL){
            cout<<p->val<<endl;
            p = p->right;
        }else{
            tmp = p->left;
            while(tmp->right != NULL || tmp->right != p)
                tmp = tmp->right;
            if(tmp->right == NULL){
                tmp->right = p;
                cout<<p->val<<endl;//we should visit p before it changes
                p = p->left;
            }else{
                tmp->right = NULL;
                p = p->right;
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
    preorderTraversal(t);
    return 0;
}
