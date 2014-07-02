#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct TreeLinkNode{
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL){}
};

TreeLinkNode* createTree()
{
    TreeLinkNode *Tree;
    int data;
    cin>>data;
    if(data == -1){
        Tree = NULL;
    }else{
        Tree = new TreeLinkNode(data);
        Tree->left = createTree();
        Tree->right = createTree();
    }
    return Tree;
}

void connect(TreeLinkNode *root) {
    if(!root) return ;

    queue<TreeLinkNode*> cur, next;
    TreeLinkNode *p = root;
    cur.push(p);
    while(!cur.empty()){
        while(!cur.empty()){
            p = cur.front();
            cur.pop();
            //cout<<p->val<<endl;

            if(!cur.empty())  p->next = cur.front();
            else p->next = NULL;

            if(p->left) next.push(p->left);
            if(p->right) next.push(p->right);
        }
        swap(cur, next);
    }
}

//recursive solution
void connect2(TreeLinkNode *root)
{
    if(!root) return;

    if(root->left) root->left->next = root->right;
    //connect through parent node's next node
    if(root->right) root->right->next = root->next ? root->next->left : NULL;

    connect2(root->left);
    connect2(root->right);
}

void preorder2(TreeLinkNode *root)
{
    if(root){
        if(root->next)
            cout<<root->next->val<<endl;
        preorder2(root->left);
        preorder2(root->right);
    }
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeLinkNode *t = createTree();
    connect2(t);
    preorder2(t);
    in.close();
    return 0;
}
