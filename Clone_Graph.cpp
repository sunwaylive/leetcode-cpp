#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

struct UndirectedGraphNode{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x){}
};



class Solution {
public:
    //bfs, c++11, only works for connected graph
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == nullptr) return nullptr;

        using UGN = UndirectedGraphNode;
        map<UGN*, UGN*> old_new;
        queue<UGN*> to_be_visited;

        to_be_visited.push(node);
        while(!to_be_visited.empty()){
            UGN *tmp = to_be_visited.front();
            to_be_visited.pop();

            //copy the node
            old_new[tmp] = new UGN(tmp->label);
            copy(begin(tmp->neighbors), end(tmp->neighbors), back_inserter(old_new[tmp]->neighbors));

            //visit all its neighbors
            for(int i = 0; i < tmp->neighbors.size(); ++i){
                if(old_new.count(tmp->neighbors[i]) == 0)
                   to_be_visited.push(tmp->neighbors[i]);
            }
        }

        //change old to new allocated UGN
        for(auto &p : old_new)
            for(auto &nei : p.second->neighbors)//iteration for neighbors which is a vector
                nei = old_new[nei]; //old_new[nei] is the corresponding node to old nei;

        return old_new[node];
    }
};


int main()
{

    return 0;
}
