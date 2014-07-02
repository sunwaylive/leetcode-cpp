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
    TreeLinkNode dummy(-1), *cur = root, *prev = &dummy;
    for(; cur != NULL; cur = cur->next){
        if(cur->left){
            prev->next = cur->left;
            prev = prev->next;
        }
        if(cur->right){
            prev->next = cur->right;
            prev = prev->next;
        }
    }
    connect2(dummy.next);
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
