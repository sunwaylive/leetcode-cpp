#include <iostream>
#include <fstream>
#include <queue>
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
    TreeNode* Tree;
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

vector<vector<int> > levelOrderBottom(TreeNode *root) {
    vector<vector<int> > ret;
    queue<TreeNode*> current, next;
    vector<int> level;
    TreeNode *p = root;

    if(p == NULL) return ret;

    current.push(p);
    while(!current.empty()){
        while(!current.empty()){
            p = current.front();
            current.pop();
            cout<<p->val<<endl;
            level.push_back(p->val);

            if(p->left != NULL) next.push(p->left);
            if(p->right != NULL) next.push(p->right);
        }
        ret.push_back(level);
        level.clear();
        swap(current, next);
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    levelOrderBottom(t);
    return 0;
}
