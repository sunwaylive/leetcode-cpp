#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int> &num)
{
    unordered_map<int, bool> used;
    for(auto i : num) used[i] = false;

    int longest = 0;
    for(auto i : num){
        if(used[i]) continue;

        int length = 1;
        //forward direction
        for(int j = i + 1; used.find(j) != used.end(); j++){
            length ++;
            used[j] = true;
        }

        for(int j = i - 1; used.find(j) != used.end(); j--){
            length++;
            used[j] = true;
        }

        longest = max(longest, length);
    }
    return longest;
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

int main(){
    const int size = 20;
    int A[size];
    generateArray(A, size);
    vector<int> num;
    for(int i = 0; i < size; ++i){
        num.push_back(A[i]);
        cout<<num[i]<<" ";
    }

    cout<<longestConsecutive(num) <<endl;
    return 0;
}
