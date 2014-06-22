#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit2(vector<int> &gas, vector<int> &cost)
{
    int sum = 0, total = 0;

    int j = 0;
    for(int i = 0; i < gas.size(); ++i){
        sum += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if(sum < 0){
            sum = 0;
            j = i + 1;
        }
    }

    return total >= 0 ? j : -1;
}

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int n = gas.size();
    vector<bool> visited(n, false);

    //test for all possibilities
    for(int start = 0; start < n; ++start){
        fill(visited.begin(), visited.end(), false);

        int carry = 0;
        int cur = start;
        do{
            int next = cur + 1;
            if(next >= n)
                next = 0;

            //cout<<next<<" ";

            //we have reached the start point
            if(visited[next]) return start;

            //not enough gas to the next station
            if(gas[cur] + carry < cost[cur])
                break;

            carry = gas[cur] + carry - cost[cur];
            visited[cur] = true;
            cur = next;
        }while(true);
    }

    return -1;
}

int main()
{
    int g[] = {5};
    int c[] = {4};
    vector<int> gas(g, g + sizeof(g) / sizeof(g[0]));
    vector<int> cost(c, c + sizeof(c) / sizeof(c[0]));

    cout<<canCompleteCircuit2(gas, cost)<<endl;
    return 0;
}
