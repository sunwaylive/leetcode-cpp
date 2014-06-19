#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum2(vector<int> &numbers, int target)
{
    vector<int> result;
    unordered_map<int, int> hash;
    int size = numbers.size();
    for(int i = 0; i < size; ++i)
        hash[numbers[i]] = i;

    for(int i = 0; i < size; ++i){
        const int gap = target - numbers[i];
        unordered_map<int, int>::iterator hash_iter = hash.find(gap);

        if(hash_iter != hash.end()){
            if(hash_iter->second == i) continue;
            result.push_back(i + 1);
            result.push_back(hash[gap] + 1);
            break;
        }
    }

    return result;
}

//O(n^2) solution
vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> result;
    int size = numbers.size();
    for(int i = 0; i < size; ++i){
        for(int j = i + 1; j < size; ++j){
            if(numbers[i] + numbers[j] == target){
                result.push_back(i);
                result.push_back(j);
                break;
            }
        }
        if(!result.empty()) break;
    }

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
    const int size = 20;
    int A[size];
    generateArray(A, size);
    vector<int> num;
    for(int i = 0; i < size; ++i)
        num.push_back(A[i]);
    printVector(num);

    num.clear();
    num.push_back(5);
    num.push_back(75);
    num.push_back(25);
    vector<int> re;
    re = twoSum2(num, 100);
    printVector(re);
    return 0;
}
