#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

//recursive
void postorderTraversal(TreeNode *root)
{
    if(root != NULL){
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout<<root->val<<endl;
    }
}

//non-recursive
vector<int> postorderTraversal2(TreeNode *root)
{
    stack<TreeNode *> stk;
    TreeNode *p = root, *q = NULL;
    vector<int> ret;

    do{
        //for each un-visited node, push stack
        while(p != NULL){
            stk.push(p);
            p = p->left;
        }

        //for every un-visited node, check its right child
        while(!stk.empty()){
            p = stk.top();
            stk.pop();
            if(p->right == NULL || p->right == q){
                cout<<p->val<<endl;
                ret.push_back(p->val);
                q = p;
            }else{
                stk.push(p);
                p = p->right;
                break;
            }
        }
    }while(!stk.empty());

    return ret;
}

//for morris traversal
void reverse(TreeNode *from, TreeNode *to)
{
    TreeNode *p, *q, *r;
    if(from == to) return;

    p = from;
    q = from->right;
    while(p != to){
        r = q->right;
        q->right = p;
        p = q;
        q = r;
    }

}

void printReverse(TreeNode *from, TreeNode *to)
{
    TreeNode *p;
    reverse(from, to);
    p = to;
    while(1){
        cout<<p->val<<endl;
        if(p == from)
            break;
        p = p->right;
    }
    reverse(to, from);
}

//http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
// 后续遍历稍显复杂，需要建立一个临时节点dump，令其左孩子是root。并且还需要一个子过程，就是倒序输出某两个节点之间路径上的各个节点。
// 步骤：
// 当前节点设置为临时节点dump。
// 1. 如果当前节点的左孩子为空，则将其右孩子作为当前节点。
// 2. 如果当前节点的左孩子不为空，在当前节点的左子树中找到当前节点在中序遍历下的前驱节点。
//   a) 如果前驱节点的右孩子为空，将它的右孩子设置为当前节点。当前节点更新为当前节点的左孩子。
//   b) 如果前驱节点的右孩子为当前节点，将它的右孩子重新设为空。倒序输出从当前节点的左孩子到该前驱节点这条路径上的所有节点。当前节点更新为当前节点的右孩子。
// 3. 重复以上1、2直到当前节点为空。

void morrisPostorder(TreeNode *root)
{
    TreeNode *dummy = (TreeNode*) malloc(sizeof(TreeNode));
    TreeNode *p = root, *tmp;
    dummy->left = root;
    p = dummy;
    while(p){
        if(p->left == NULL){
            p = p->right;//no visit here
        }else{
            tmp = p->left;
            while(tmp->right != NULL && tmp->right != p)
                tmp = tmp->right;

            if(tmp->right == NULL){
                tmp->right = p;//link them
                p = p->left;
            }else{
                printReverse(p->left, tmp);//visit only here!
                tmp->right = NULL;
                p = p->right;
            }
        }
    }
}

int main()
{
    streambuf *backup;
    ifstream in;
    in.open("input.txt");
    backup = cin.rdbuf();
    cin.rdbuf(in.rdbuf());

    //go back
    //cin.rdbuf(backup);
    TreeNode *t = createTree();
    //postorderTraversal(t);
    //postorderTraversal2(t);
    morrisPostorder(t);
    return 0;
}
