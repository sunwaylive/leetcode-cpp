#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int threeSumClosest(vector<int> &num, int target)
{
    typedef vector<int>::iterator VI;

    int sum = 0;
    int gap = INT_MAX;

    if(num.size() < 3) return INT_MIN;

    sort(num.begin(), num.end());
    VI a_end = prev(num.end(), 2);
    for(VI a = num.begin(); a < a_end; a++){
        VI b = next(a);
        VI c = prev(num.end());
        int tmp_sum;
        while(b < c){
            tmp_sum = *a + *b + *c;
            if(tmp_sum > target) { c--; }
            else if(tmp_sum < target) { b++; }
            else { return target; }

            if(abs(tmp_sum - target) < gap){
                gap = abs(tmp_sum - target);
                sum = tmp_sum;
            }
        }
    }
    return sum;
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
    num.push_back(0);
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);

    int re = threeSumClosest(num, 100);
    cout<<re <<endl;
    return 0;
}
