#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void nextPermutation(vector<int> &num) {
    int size = num.size();
    int pivot, first_larger, i;
    for(i = size - 2; i >= 0; --i)
        if(num[i] < num[i+1])
            break;

    pivot = i;
    //cout<<"pivot: "<<pivot<<endl;
    //if already in descending order, then reverse and return;
    if(pivot < 0){
        reverse(num.begin(), num.end());
        return ;
    }

    for(i = size - 1; i > pivot; --i){
        if(num[i] > num[pivot])
            break;
    }

    first_larger = i;
    //cout<<"first larger: "<<first_larger <<endl;
    //swap the two numbers
    num[pivot] ^= num[i];
    num[i] ^= num[pivot];
    num[pivot] ^= num[i];

    reverse(num.begin() + pivot + 1, num.end());
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
    int B[3] = {1, 1, 5};
    vector<int> A(B, B + 3);
    nextPermutation(A);
    printVector(A);
    return 0;
}
