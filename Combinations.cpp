#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int> > combine2(int n, int k)
{
    vector<int> values(n);
    for(int i = 0; i < n; ++i)
        values[i] = i + 1;

    //this means use k true and (n-k) f to do permutation
    vector<bool> select(n, false);
    for(int i = 0; i < k; ++i)
        select[i] = true;

    cout<<"done1"<<endl;
    vector<vector<int> > result;
    do{
        vector<int> one(k);
        for(int i = 0, index = 0; i < n; ++i)
            //pick the true ones
            if(select[i])
                one[index++] = values[i];

        result.push_back(one);
    }while(prev_permutation(select.begin(), select.end()));//1 1 0 0 has no next permutation

    return result;
}

void generateArray(int *A, const int n)
{
    for(int i = 0; i < n; i ++){
        A[i] = i;
    }
}

void printArray(int *A, const int n)
{
    for(int i = 0; i < n; ++i){
        cout<< A[i] << " ";
    }
    cout<<endl;
}

void printVector(const vector<int> &v)
{
    for(vector<int>::const_iterator iter = v.begin();
        iter != v.end(); ++iter){
        cout<<*iter <<" ";
    }
    cout<<endl;
}


int main(){
    int a[] = {1, 1, 2};
    vector<int> A(a, a+3);
    vector<vector<int> > result;
    result = combine2(4, 2);
    for(int i = 0; i < result.size(); ++i){
        printVector(result[i]);
    }

    return 0;
}
