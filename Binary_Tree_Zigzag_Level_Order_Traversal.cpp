#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
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

vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
    vector<vector<int> > ret;
    queue<TreeNode*> current, next;
    vector<int> level;
    TreeNode *p = root;
    if(p == NULL) return ret;

    bool isZigzag = true;
    current.push(p);
    while(!current.empty()){
        while(!current.empty()){
            p = current.front();
            current.pop();
            level.push_back(p->val);
            cout<<p->val <<endl;

            if(p->left != NULL) next.push(p->left);
            if(p->right != NULL) next.push(p->right);
        }
        isZigzag = !isZigzag;
        if(isZigzag)
            reverse(level.begin(), level.end());

        ret.push_back(level);
        level.clear();
        swap(current, next);
    }
    return ret;
}

void printVector(const vector<int> &v)
{
    for(int i = 0; i < v.size(); ++i)
        cout<<v[i] <<endl;
    cout<<endl;
}

int main()
{
    ifstream in;
    in.open("input.txt");
    cin.rdbuf(in.rdbuf());

    TreeNode *t = createTree();
    vector<vector<int> > result;
    result = zigzagLevelOrder(t);
    for(int i = 0; i < result.size(); ++i)
        printVector(result[i]);

    return 0;
}
